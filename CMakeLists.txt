cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
project(ikaruga)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if (MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else ()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif ()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if (${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif ()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.11.1
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if (NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif ()

# Adds nlohmann/json parsing library
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if (NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

file(GLOB_RECURSE GAME_ENGINE_SOURCE_FILES src/game_engine/*.cc)

file(GLOB_RECURSE GUI_SOURCE_FILES src/interface/*.cc)

file(GLOB_RECURSE IKARUGA_CORE_SOURCE_FILES src/ikaruga/core/*.cc)

file(GLOB_RECURSE IKARUGA_APP_SOURCE_FILES src/ikaruga/app/*.cc)

file(GLOB_RECURSE IKARUGA_GAME_SOURCE_FILES src/ikaruga/game/*.cc)

list(APPEND SOURCE_FILES ${GAME_ENGINE_SOURCE_FILES} ${GUI_SOURCE_FILES} ${IKARUGA_CORE_SOURCE_FILES} ${IKARUGA_APP_SOURCE_FILES} ${IKARUGA_GAME_SOURCE_FILES})

file(GLOB_RECURSE GAME_ENGINE_TEST_FILES tests/game_engine/*.cc)

file(GLOB_RECURSE GUI_TEST_FILES tests/interface/*.cc)

file(GLOB_RECURSE IKARUGA_CORE_TEST_FILES tests/ikaruga/core/*.cc)

list(APPEND TEST_FILES ${GAME_ENGINE_TEST_FILES} ${GUI_TEST_FILES} ${IKARUGA_CORE_TEST_FILES})

#add_executable(train-model apps/train_model_main.cc ${CORE_SOURCE_FILES})
#target_include_directories(train-model PRIVATE include)

ci_make_app(
        APP_NAME ikaruga
        CINDER_PATH ${CINDER_PATH}
        SOURCES apps/cinder_app_main.cc ${SOURCE_FILES}
        INCLUDES include
        LIBRARIES nlohmann_json::nlohmann_json
)

ci_make_app(
        APP_NAME ikaruga-test
        CINDER_PATH ${CINDER_PATH}
        SOURCES tests/test_main.cc ${SOURCE_FILES} ${TEST_FILES}
        INCLUDES include
        LIBRARIES catch2 nlohmann_json::nlohmann_json
)

ci_make_app(
        APP_NAME sandbox
        CINDER_PATH ${CINDER_PATH}
        SOURCES apps/cinder_sandbox_main.cc src/sandbox/sandbox_app.cc ${SOURCE_FILES}
        INCLUDES include
        LIBRARIES nlohmann_json::nlohmann_json
)

if (MSVC)
    set_property(TARGET ikaruga-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif ()