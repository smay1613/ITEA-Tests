cmake_minimum_required(VERSION 3.0)

project(HomeworkTests VERSION 1.0.0)

set(LESSON_NUMBER 1)
set(LESSON_DIR Lesson${LESSON_NUMBER})

set(sources
    "src/${LESSON_DIR}/HomeworkImpl.cpp"
)

set(headers
    "src/${LESSON_DIR}/Homework.h")

add_library(HomeworkTests SHARED ${sources})

set_target_properties(HomeworkTests PROPERTIES
                        C_STANDARD 11
                        CXX_STANDARD 11
                        PUBLIC_HEADER "${headers}"
                        VERSION "${PROJECT_VERSION}"
                        SOVERSION "${PROJECT_VERSION_MAJOR}"
)

target_compile_options(HomeworkTests PRIVATE -Wall -Wextra)

target_include_directories(HomeworkTests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/${LESSON_DIR}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LESSON_DIR}>
        $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

set(test true)

if (test)
  add_subdirectory(tests)
endif()
