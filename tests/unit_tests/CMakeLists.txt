CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

project (unit_tests
         LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

set(sources
    "${AVP_UT_DIRECTORY}/src/main.cpp"
    "${AVP_UT_DIRECTORY}/src/TestMetadataUtils.cpp")

set(headers
    "${AVP_UT_DIRECTORY}/headers/TestMetadataUtils.h")

include_directories(unit_tests
    PRIVATE
        ${AVP_UT_DIRECTORY}/headers
)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include(AddGTestTest)

enable_testing()
add_gtest_test(${PROJECT_NAME} "${sources}" AVInterface)

get_filename_component(AVPROCESSING_REPO_DIRECTORY "${AVP_UT_ROOT_DIRECTORY}" DIRECTORY)

include_directories(
        PRIVATE
        ${AVPROCESSING_REPO_DIRECTORY}/include
        )