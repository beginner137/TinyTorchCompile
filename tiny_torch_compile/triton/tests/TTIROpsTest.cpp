#include "MiniTriton/IR/MiniTritonOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Diagnostics.h"
#include "mlir/IR/Verifier.h"
#include "mlir/Parser/Parser.h"
#include "llvm/Support/raw_ostream.h"
#include <string>

// No testing-framework dependency; failures return a nonzero status to CTest.
int main(int argc, char **argv) {
    if (argc != 2) return 2;
    mlir::MLIRContext context;
    context.getOrLoadDialect<mini_triton::MiniTritonDialect>();
    context.getOrLoadDialect<mlir::arith::ArithDialect>();
    context.getOrLoadDialect<mlir::func::FuncDialect>();
    int failures = 0;
    auto kernel = mlir::parseSourceFile<mlir::ModuleOp>(argv[1], &context);
    if (!kernel || mlir::failed(mlir::verify(*kernel))) return 1;
    // Ensure printing and reparsing preserve the custom pointer types and ops.
    std::string printed;
    llvm::raw_string_ostream os(printed);
    kernel->print(os);
    auto roundtrip = mlir::parseSourceString<mlir::ModuleOp>(printed, &context);
    if (!roundtrip || mlir::failed(mlir::verify(*roundtrip))) return 1;

    auto check = [&](const char *name, std::string args, std::string body,
                     const char *expectedError = nullptr) {
        std::string diagnostics;
        mlir::ScopedDiagnosticHandler handler(&context, [&](mlir::Diagnostic &d) {
            llvm::raw_string_ostream stream(diagnostics);
            d.print(stream);
            return mlir::success();
        });
        auto module = mlir::parseSourceString<mlir::ModuleOp>(
            "module { func.func @test(" + args + ") { " + body + " return } }",
            &context);
        bool valid = module && mlir::succeeded(mlir::verify(*module));
        bool passed = expectedError ? (!valid && diagnostics.find(expectedError) != std::string::npos) : valid;
        if (!passed) {
            llvm::errs() << "FAIL " << name << ": " << diagnostics << "\n";
            ++failures;
        }
    };

    for (int axis : {0, 1, 2})
        check("program axis", "", "%v = \"mini.get_program_id\"() {axis = " + std::to_string(axis) + " : i32} : () -> i32");
    for (int axis : {-1, 3})
        check("bad axis", "", "%v = \"mini.get_program_id\"() {axis = " + std::to_string(axis) + " : i32} : () -> i32", "axis must");
    check("scalar memory", "%p: !mini.ptr<f32>, %i: i64, %m: i1, %v: f32",
          "%q = \"mini.addptr\"(%p, %i) : (!mini.ptr<f32>, i64) -> !mini.ptr<f32> "
          "%x = \"mini.load\"(%q, %m, %v) : (!mini.ptr<f32>, i1, f32) -> f32 "
          "\"mini.store\"(%q, %x, %m) : (!mini.ptr<f32>, f32, i1) -> ()");
    check("float splat", "%v: f32", "%x = \"mini.splat\"(%v) : (f32) -> tensor<4xf32>");
    check("bad splat element", "%v: f32", "%x = \"mini.splat\"(%v) : (f32) -> tensor<4xi32>", "input type must match");
    check("tensor splat", "%v: tensor<4xi32>", "%x = \"mini.splat\"(%v) : (tensor<4xi32>) -> tensor<4xi32>", "scalar");
    check("bad pointer", "%p: !mini.ptr<tensor<4xf32>>", "", "pointer pointee");
    check("bad offset", "%p: !mini.ptr<f32>, %i: f32", "%q = \"mini.addptr\"(%p, %i) : (!mini.ptr<f32>, f32) -> !mini.ptr<f32>", "offset must");
    check("nonpointer", "%p: i32, %i: i32", "%q = \"mini.addptr\"(%p, %i) : (i32, i32) -> i32", "pointer operands");
    check("changed pointee", "%p: !mini.ptr<f32>, %i: i32", "%q = \"mini.addptr\"(%p, %i) : (!mini.ptr<f32>, i32) -> !mini.ptr<i32>", "result type must");
    check("offset shape", "%p: tensor<4x!mini.ptr<f32>>, %i: tensor<8xi32>", "%q = \"mini.addptr\"(%p, %i) : (tensor<4x!mini.ptr<f32>>, tensor<8xi32>) -> tensor<4x!mini.ptr<f32>>", "matching");
    check("bad mask", "%p: !mini.ptr<f32>, %m: i32, %v: f32", "%x = \"mini.load\"(%p, %m, %v) : (!mini.ptr<f32>, i32, f32) -> f32", "mask must");
    check("bad fallback", "%p: !mini.ptr<f32>, %m: i1, %v: i32", "%x = \"mini.load\"(%p, %m, %v) : (!mini.ptr<f32>, i1, i32) -> f32", "other type");
    check("bad load pointee", "%p: !mini.ptr<i32>, %m: i1, %v: f32", "%x = \"mini.load\"(%p, %m, %v) : (!mini.ptr<i32>, i1, f32) -> f32", "pointee");
    check("bad store pointee", "%p: !mini.ptr<i32>, %m: i1, %v: f32", "\"mini.store\"(%p, %v, %m) : (!mini.ptr<i32>, f32, i1) -> ()", "pointee");
    check("mask shape", "%p: tensor<4x!mini.ptr<f32>>, %m: tensor<8xi1>, %v: tensor<4xf32>", "\"mini.store\"(%p, %v, %m) : (tensor<4x!mini.ptr<f32>>, tensor<4xf32>, tensor<8xi1>) -> ()", "shapes must match");
    for (auto type : {"tensor<2x2xi32>", "tensor<?xi32>", "tensor<0xi32>", "tensor<4xf32>"})
        check("invalid range type", "", std::string("%r = \"mini.make_range\"() {start = 0 : i64, end = 4 : i64} : () -> ") + type, "requires");
    check("range size", "", "%r = \"mini.make_range\"() {start = 0 : i64, end = 4 : i64} : () -> tensor<8xi32>", "range length");
    check("valid range", "", "%r = \"mini.make_range\"() {start = -2 : i64, end = 2 : i64} : () -> tensor<4xi32>");
    check("reversed range", "", "%r = \"mini.make_range\"() {start = 4 : i64, end = 0 : i64} : () -> tensor<4xi32>", "increasing range");
    check("overflow range", "", "%r = \"mini.make_range\"() {start = -9223372036854775808 : i64, end = 9223372036854775807 : i64} : () -> tensor<4xi32>", "representable");

    // Memory effects are essential: a store cannot be treated as a pure op.
    kernel->walk([&](mini_triton::LoadOp op) {
        auto effects = mlir::cast<mlir::MemoryEffectOpInterface>(op.getOperation());
        if (!effects.hasEffect<mlir::MemoryEffects::Read>()) ++failures;
    });
    kernel->walk([&](mini_triton::StoreOp op) {
        auto effects = mlir::cast<mlir::MemoryEffectOpInterface>(op.getOperation());
        if (!effects.hasEffect<mlir::MemoryEffects::Write>()) ++failures;
    });
    if (failures) return 1;
    llvm::outs() << "TTIR kernel, roundtrip, verifier, and memory-effect tests passed\n";
    return 0;
}
