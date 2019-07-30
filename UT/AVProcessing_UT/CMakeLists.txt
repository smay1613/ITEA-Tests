CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project (AVProcessing_UT
         LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

set(sources
    "${AVPROCESSING_UT_DIRECTORY}/src/main.cpp"
    "${AVPROCESSING_UT_DIRECTORY}/src/TestMetadataUtils.cpp")

set(headers
    "${AVPROCESSING_UT_DIRECTORY}/headers/TestMetadataUtils.h")

include_directories(AVProcessing_UT
    PRIVATE
        ${AVPROCESSING_UT_DIRECTORY}/headers
)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include(AddGTestTest)

enable_testing()
add_gtest_test(${PROJECT_NAME} "${sources}" AVInterface)

get_filename_component(AVPROCESSING_REPO_DIRECTORY "${AVPROCESSING_UT_ROOT_DIRECTORY}" DIRECTORY)

include_directories(
        PRIVATE
        ${AVPROCESSING_REPO_DIRECTORY}/src
)