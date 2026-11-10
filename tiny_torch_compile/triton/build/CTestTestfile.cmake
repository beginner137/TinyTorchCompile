# CMake generated Testfile for 
# Source directory: /Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton
# Build directory: /Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test("mini_ttir_ops" "/Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/build/mini_ttir_tests" "/Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/tests/elementwise.mlir")
set_tests_properties("mini_ttir_ops" PROPERTIES  _BACKTRACE_TRIPLES "/Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/CMakeLists.txt;128;add_test;/Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/CMakeLists.txt;0;")
add_test("blocked_layout" "/Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/build/blocked_layout_test")
set_tests_properties("blocked_layout" PROPERTIES  _BACKTRACE_TRIPLES "/Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/CMakeLists.txt;141;add_test;/Users/dorisxiang/inference-projects/TinyTorchCompile/tiny_torch_compile/triton/CMakeLists.txt;0;")
