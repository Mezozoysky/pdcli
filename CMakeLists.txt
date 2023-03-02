cmake_minimum_required(VERSION 3.13)

project(PDCLI
    LANGUAGES CXX
    VERSION 0.1.0
)

set(PDCLI_VERSION ${PROJECT_VERSION})

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

set(PDCLI_BUILD_SHARED_DEFAULT ${BUILD_SHARED_LIBS})
set(PDCLI_BUILD_UT_DEFAULT TRUE)

option(PDCLI_BUILD_SHARED "Build shared libraries" ${PDCLI_BUILD_SHARED_DEFAULT})
option(PDCLI_BUILD_UT "Build unit tests" ${PDCLI_BUILD_UT_DEFAULT})
#option(PDCLI_FMT_BUNDLED "Use bundled fmt library" TRUE)
#option(PDCLI_SPDLOG_BUNDLED "Use bundled spdlog library" TRUE)

add_library(common INTERFACE)
add_library(PDCLI::common ALIAS common)
target_compile_options(common
    INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra>
    )

add_subdirectory(dependencies)
add_subdirectory(sources)
