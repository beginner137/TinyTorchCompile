
cmake_minimum_required(VERSION 3.20)
# Deduplicate libraries when the platform linker supports it (CMake 3.29+).
if(POLICY CMP0156)
    cmake_policy(SET CMP0156 NEW)
endif()
project(MiniTriton LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(MLIR REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}" "${MLIR_CMAKE_DIR}")
include(TableGen)
find_program(MINI_TRITON_TABLEGEN_EXECUTABLE NAMES mlir-tblgen
    HINTS "${LLVM_TOOLS_BINARY_DIR}" REQUIRED)
set(MLIR_TABLEGEN_EXE "${MINI_TRITON_TABLEGEN_EXECUTABLE}")

set(MINI_TRITON_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/include")
file(MAKE_DIRECTORY "${MINI_TRITON_GENERATED_DIR}/MiniTriton/IR")
set(MINI_TRITON_TABLEGEN_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    ${MLIR_INCLUDE_DIRS}
    ${LLVM_INCLUDE_DIRS}
)

set(LLVM_TARGET_DEFINITIONS include/MiniTriton/IR/MiniTritonOps.td)
tablegen(MLIR include/MiniTriton/IR/MiniTritonOps.h.inc -gen-op-decls
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
tablegen(MLIR include/MiniTriton/IR/MiniTritonOps.cpp.inc -gen-op-defs
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})

set(LLVM_TARGET_DEFINITIONS include/MiniTriton/IR/MiniTritonDialect.td)
tablegen(MLIR include/MiniTriton/IR/MiniTritonDialect.h.inc
    -gen-dialect-decls -dialect=mini
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
tablegen(MLIR include/MiniTriton/IR/MiniTritonDialect.cpp.inc
    -gen-dialect-defs -dialect=mini
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
set(LLVM_TARGET_DEFINITIONS include/MiniTriton/IR/MiniTritonGPU.td)
tablegen(MLIR include/MiniTriton/IR/MiniTritonGPUOps.h.inc -gen-op-decls
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
tablegen(MLIR include/MiniTriton/IR/MiniTritonGPUOps.cpp.inc -gen-op-defs
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
tablegen(MLIR include/MiniTriton/IR/MiniTritonGPUDialect.h.inc
    -gen-dialect-decls -dialect=mini_gpu
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
tablegen(MLIR include/MiniTriton/IR/MiniTritonGPUDialect.cpp.inc
    -gen-dialect-defs -dialect=mini_gpu
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})

set(LLVM_TARGET_DEFINITIONS include/MiniTriton/IR/MiniTritonTypes.td)
tablegen(MLIR include/MiniTriton/IR/MiniTritonTypes.h.inc -gen-typedef-decls
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
tablegen(MLIR include/MiniTriton/IR/MiniTritonTypes.cpp.inc -gen-typedef-defs
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
set(LLVM_TARGET_DEFINITIONS include/MiniTriton/IR/MiniTritonGPUAttrs.td)
tablegen(MLIR include/MiniTriton/IR/MiniTritonGPUAttrs.h.inc -gen-attrdef-decls
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
tablegen(MLIR include/MiniTriton/IR/MiniTritonGPUAttrs.cpp.inc -gen-attrdef-defs
    EXTRA_INCLUDES ${MINI_TRITON_TABLEGEN_INCLUDES})
add_custom_target(MiniTritonIncGen DEPENDS ${TABLEGEN_OUTPUT})

add_executable(mini_triton main.cpp)
add_dependencies(mini_triton MiniTritonIncGen)
target_include_directories(mini_triton PRIVATE
    ${MINI_TRITON_GENERATED_DIR}
    ${MLIR_INCLUDE_DIRS}
    ${LLVM_INCLUDE_DIRS}
)
target_link_libraries(mini_triton PRIVATE
    MLIRIR
    MLIRSupport
)

target_sources(mini_triton PRIVATE
    lib/MiniTritonDialect.cpp
)

target_include_directories(mini_triton PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(mini_triton PRIVATE
    lib/MiniTritonOps.cpp
    lib/MiniTritonTypes.cpp
)

target_sources(mini_triton PRIVATE
    lib/Frontend/Frontend.cpp
)

target_link_libraries(mini_triton PRIVATE
    MLIRFuncDialect
)

target_sources(mini_triton PRIVATE
    lib/MiniTritonGPUDialect.cpp
    lib/MiniTritonGPUOps.cpp
)

target_include_directories(mini_triton PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

target_sources(mini_triton PRIVATE
    lib/Conversion/LowerToGPU.cpp
)

target_link_libraries(mini_triton PRIVATE
    MLIRTransformUtils
    MLIRPass
)

include(CTest)
if(BUILD_TESTING)
    add_executable(mini_ttir_tests
        tests/TTIROpsTest.cpp
        lib/MiniTritonDialect.cpp
        lib/MiniTritonTypes.cpp
        lib/MiniTritonOps.cpp)
    add_dependencies(mini_ttir_tests MiniTritonIncGen)
    target_include_directories(mini_ttir_tests PRIVATE
        ${MINI_TRITON_GENERATED_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${MLIR_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS})
    target_link_libraries(mini_ttir_tests PRIVATE
        MLIRParser MLIRArithDialect MLIRFuncDialect MLIRIR MLIRSupport)
    add_test(NAME mini_ttir_ops COMMAND mini_ttir_tests
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/elementwise.mlir)

    add_executable(blocked_layout_test
        tests/BlockedLayoutTest.cpp
        lib/MiniTritonGPUDialect.cpp
        lib/MiniTritonGPUOps.cpp)
    add_dependencies(blocked_layout_test MiniTritonIncGen)
    target_include_directories(blocked_layout_test PRIVATE
        ${MINI_TRITON_GENERATED_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${MLIR_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS})
    target_link_libraries(blocked_layout_test PRIVATE MLIRIR MLIRSupport)
    add_test(NAME blocked_layout COMMAND blocked_layout_test)
endif()
