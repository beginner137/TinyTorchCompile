#include "MiniTriton/Conversion/LowerToGPU.h"
#include "MiniTriton/IR/MiniTritonOps.h"
#include "MiniTriton/IR/MiniTritonGPUOps.h"

#include "mlir/IR/PatternMatch.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

#include "MiniTriton/IR/MiniTritonGPUAttrs.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"

namespace mini_triton
{

    struct SplatToGPUPattern
        : mlir::OpRewritePattern<SplatOp>
    {

        using OpRewritePattern::OpRewritePattern;

        mlir::LogicalResult matchAndRewrite(
            SplatOp op,
            mlir::PatternRewriter &rewriter) const override
        {

            rewriter.replaceOpWithNewOp<gpu::SplatOp>(
                op,
                op.getResult().getType(),
                op.getInput(),
                rewriter.getI64IntegerAttr(4),
                rewriter.getI64IntegerAttr(1));

            return mlir::success();
        }
    };

    struct MakeRangeToGPUPattern
        : mlir::OpRewritePattern<MakeRangeOp>
    {

        TargetInfo target_;

        MakeRangeToGPUPattern(
            mlir::MLIRContext *context,
            TargetInfo target) : OpRewritePattern<MakeRangeOp>(context),
                                 target_(target) {}

        mlir::LogicalResult matchAndRewrite(
            MakeRangeOp op,
            mlir::PatternRewriter &rewriter) const override
        {
            auto oldType = op.getResult().getType();
            unsigned sizePerThread = target_.warpSize == 32 ? 2 : 1;
            auto layout = gpu::BlockedLayoutAttr::get(
                rewriter.getContext(),
                sizePerThread,
                target_.warpSize,
                target_.numWarps);

            auto gpuType = mlir::RankedTensorType::get(
                oldType.getShape(),
                oldType.getElementType(),
                layout);

            // Our demo function returns this tensor, so its
            // declared return type must change too.
            auto func = op->getParentOfType<mlir::func::FuncOp>();

            rewriter.modifyOpInPlace(func, [&]
                                     {
                auto oldFuncType = func.getFunctionType();
                func.setType(rewriter.getFunctionType(
                    oldFuncType.getInputs(), {gpuType}
                )); });

            rewriter.replaceOpWithNewOp<gpu::MakeRangeOp>(
                op,
                gpuType,
                op.getStartAttr(),
                op.getEndAttr(),
                rewriter.getI64IntegerAttr(target_.numWarps),
                rewriter.getI64IntegerAttr(sizePerThread));

            return mlir::success();
        }
    };

    mlir::LogicalResult lowerToGPU(mlir::ModuleOp module, TargetInfo target)
    {
        mlir::RewritePatternSet patterns(module.getContext());

        patterns.add<SplatToGPUPattern>(module.getContext());
        patterns.add<MakeRangeToGPUPattern>(
            module.getContext(), target);
        return mlir::applyPatternsGreedily(
            module.getOperation(),
            mlir::FrozenRewritePatternSet(std::move(patterns)));
    }

    struct LowerToGPUPass
        : mlir::PassWrapper<
              LowerToGPUPass,
              mlir::OperationPass<mlir::ModuleOp>>
    {
        TargetInfo target_;

        explicit LowerToGPUPass(TargetInfo target)
            : target_(target) {}

        MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(LowerToGPUPass)

        void getDependentDialects(mlir::DialectRegistry &registry) const override
        {
            registry.insert<gpu::MiniTritonGPUDialect>();
        }

        void runOnOperation() override
        {
            llvm::outs() << "Target warp size: "
                         << target_.warpSize << "\n";
            if (mlir::failed(lowerToGPU(getOperation(), target_)))
            {
                signalPassFailure();
            }
        }
    };

    std::unique_ptr<mlir::Pass> createLowerToGPUPass(TargetInfo target)
    {
        return std::make_unique<LowerToGPUPass>(target);
    }

} // namespace mini_triton
