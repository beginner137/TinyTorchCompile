
cmake_minimum_required(VERSION 3.20)
project(MiniTriton LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(MLIR REQUIRED CONFIG)

add_executable(mini_triton main.cpp)
target_include_directories(mini_triton PRIVATE
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
)

target_sources(mini_triton PRIVATE
    lib/Frontend/Frontend.cpp
)

target_link_libraries(mini_triton PRIVATE
    MLIRFuncDialect
)
