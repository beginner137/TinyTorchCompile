// TTIR for (x * y + 1)^2, using 256-element blocks and masked tail lanes.
module {
  func.func @elementwise(%x: !mini.ptr<f32>, %y: !mini.ptr<f32>,
                        %out: !mini.ptr<f32>, %n: i32) {
    %pid = "mini.get_program_id"() {axis = 0 : i32} : () -> i32
    %block = arith.constant 256 : i32
    %base = arith.muli %pid, %block : i32
    %bases = "mini.splat"(%base) : (i32) -> tensor<256xi32>
    %range = "mini.make_range"() {start = 0 : i64, end = 256 : i64} : () -> tensor<256xi32>
    %offsets = arith.addi %bases, %range : tensor<256xi32>
    %ns = "mini.splat"(%n) : (i32) -> tensor<256xi32>
    %mask = arith.cmpi slt, %offsets, %ns : tensor<256xi32>
    %xs = "mini.splat"(%x) : (!mini.ptr<f32>) -> tensor<256x!mini.ptr<f32>>
    %ys = "mini.splat"(%y) : (!mini.ptr<f32>) -> tensor<256x!mini.ptr<f32>>
    %outs = "mini.splat"(%out) : (!mini.ptr<f32>) -> tensor<256x!mini.ptr<f32>>
    %xp = "mini.addptr"(%xs, %offsets) : (tensor<256x!mini.ptr<f32>>, tensor<256xi32>) -> tensor<256x!mini.ptr<f32>>
    %yp = "mini.addptr"(%ys, %offsets) : (tensor<256x!mini.ptr<f32>>, tensor<256xi32>) -> tensor<256x!mini.ptr<f32>>
    %op = "mini.addptr"(%outs, %offsets) : (tensor<256x!mini.ptr<f32>>, tensor<256xi32>) -> tensor<256x!mini.ptr<f32>>
    %zero = arith.constant dense<0.0> : tensor<256xf32>
    %one = arith.constant dense<1.0> : tensor<256xf32>
    %a = "mini.load"(%xp, %mask, %zero) : (tensor<256x!mini.ptr<f32>>, tensor<256xi1>, tensor<256xf32>) -> tensor<256xf32>
    %b = "mini.load"(%yp, %mask, %zero) : (tensor<256x!mini.ptr<f32>>, tensor<256xi1>, tensor<256xf32>) -> tensor<256xf32>
    %product = arith.mulf %a, %b : tensor<256xf32>
    %shifted = arith.addf %product, %one : tensor<256xf32>
    %square = arith.mulf %shifted, %shifted : tensor<256xf32>
    "mini.store"(%op, %square, %mask) : (tensor<256x!mini.ptr<f32>>, tensor<256xf32>, tensor<256xi1>) -> ()
    return
  }
}
