
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

} // namespace mini_triton
