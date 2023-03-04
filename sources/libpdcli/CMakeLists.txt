cmake_minimum_required(VERSION 3.13)

project(libpdcli
    LANGUAGES CXX
    VERSION ${PDCLI_VERSION}
    )

add_library(${PROJECT_NAME} STATIC)
add_library(PDCLI::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME pdcli
    )
target_link_libraries(${PROJECT_NAME}
    INTERFACE
    #spdlog::spdlog
    #fmt::fmt
    PDCLI::common
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/include"
    #$<TARGET_PROPERTY:spdlog::spdlog,INTERFACE_INCLUDE_DIRECTORIES>
    #$<TARGET_PROPERTY:fmt::fmt,INTERFACE_INCLUDE_DIRECTORIES>
    )

set(HEADER_FILES
    include/pd/cli/abstract_style.hpp
    include/pd/cli/basic_style.hpp
    include/pd/cli/posix_style.hpp
    include/pd/cli/gnu_style.hpp
    include/pd/cli/from_string.hpp
    include/pd/cli/pdcli.hpp
    )
set(SOURCE_FILES
    src/pd/cli/basic_style.cpp
    src/pd/cli/posix_style.cpp
    src/pd/cli/gnu_style.cpp
    src/pd/cli/from_string.cpp
    src/pd/cli/pdcli.cpp
    )

target_sources(${PROJECT_NAME}
    PRIVATE ${SOURCE_FILES}
    PUBLIC ${HEADER_FILES}
    )

if(PDCLI_BUILD_UT)
    add_subdirectory(ut)
endif()
