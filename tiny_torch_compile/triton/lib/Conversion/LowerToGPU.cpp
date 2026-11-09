#include "MiniTriton/Conversion/LowerToGPU.h"
#include "MiniTriton/IR/MiniTritonOps.h"
#include "MiniTriton/IR/MiniTritonGPUOps.h"

#include "mlir/IR/PatternMatch.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

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

    mlir::LogicalResult lowerToGPU(mlir::ModuleOp module)
    {
        mlir::RewritePatternSet patterns(module.getContext());

        patterns.add<SplatToGPUPattern>(module.getContext());

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
            if (mlir::failed(lowerToGPU(getOperation())))
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
