cmake_minimum_required(VERSION 3.8)

# https://cmake.org/cmake/help/latest/command/project.html
project(box2d VERSION 2.4.1)# Detect clang

if(CMAKE_CXX_COMPILER MATCHES ".*clang")
  set(CMAKE_COMPILER_IS_CLANGXX 1)
  # call find_package for Threads. Without this, you will get this error:
  # set_target_properties Can not find target to add properties to: Threads::Threads
  find_package(Threads)
endif()
if (WIN32)
  find_package(Threads)
endif()

add_definitions(-DLIQUIDFUN_EXTERNAL_LANGUAGE_API=0)

# set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo" CACHE STRING "" FORCE)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

option(BOX2D_BUILD_UNIT_TESTS "Build the Box2D unit tests" ON)
option(BOX2D_BUILD_TESTBED "Build the Box2D testbed" OFF)
option(BOX2D_BUILD_DOCS "Build the Box2D documentation" OFF)
option(BOX2D_USER_SETTINGS "Override Box2D settings with b2UserSettings.h" OFF)

option(BUILD_SHARED_LIBS "Build Box2D as a shared library" OFF)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

#option(box2d_EXPORTS "Export lib I guess" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

include(GNUInstallDirs)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (BOX2D_USER_SETTINGS)
	add_compile_definitions(B2_USER_SETTINGS)
endif()

add_subdirectory(src)

if (BOX2D_BUILD_DOCS)
    set(DOXYGEN_SKIP_DOT TRUE)
    find_package(Doxygen)
endif()

if (DOXYGEN_FOUND AND BOX2D_BUILD_DOCS)
    add_subdirectory(docs)
endif()

if (BOX2D_BUILD_UNIT_TESTS)
	add_subdirectory(unit-test)
endif()

# if (BOX2D_BUILD_TESTBED)
# 	add_subdirectory(extern/glad)
# 	add_subdirectory(extern/glfw)
# 	add_subdirectory(extern/imgui)
# 	add_subdirectory(extern/sajson)
# 	add_subdirectory(testbed)

# 	# default startup project for Visual Studio
# 	if (MSVC)
# 		set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT testbed)
# 		set_property(TARGET testbed PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/testbed")
# 	endif()
# endif()

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/box2d"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

message("Copied from ${CMAKE_CURRENT_SOURCE_DIR}/include/box2d to ${CMAKE_INSTALL_INCLUDEDIR}")

