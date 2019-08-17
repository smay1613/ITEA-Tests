CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project (unit_tests
         LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

set(sources
    "${HomeworkTests_UT_DIRECTORY}/src/main.cpp"
    "${HomeworkTests_UT_DIRECTORY}/src/${LESSON_DIR}/TestHomework.cpp")

set(headers
    "${HomeworkTests_UT_DIRECTORY}/headers/${LESSON_DIR}/TestHomework.h")

include_directories(unit_tests
    PRIVATE
        ${HomeworkTests_UT_DIRECTORY}/headers/${LESSON_DIR}
)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include(AddGTestTest)

enable_testing()
add_gtest_test(${PROJECT_NAME} "${sources}" HomeworkTests)

get_filename_component(HomeworkTests_REPO_DIRECTORY "${HomeworkTests_UT_ROOT_DIRECTORY}" DIRECTORY)

include_directories(
        PRIVATE
        ${HomeworkTests_REPO_DIRECTORY}/headers/${LESSON_DIR}
        )
