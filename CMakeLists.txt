cmake_minimum_required(VERSION 3.0)

project(AVProcessing VERSION 1.0.0)

find_package(PkgConfig)
pkg_check_modules(TAGLIB REQUIRED taglib)

set(sources
    "src/Utils.cpp"
)

set(headers
    "src/Utils.h")

add_library(AVInterface SHARED ${sources})

set_target_properties(AVInterface PROPERTIES 
                        C_STANDARD 11
                        CXX_STANDARD 11
                        PUBLIC_HEADER "${headers}"
                        VERSION "${PROJECT_VERSION}"
                        SOVERSION "${PROJECT_VERSION_MAJOR}"
)

target_compile_options(AVInterface PRIVATE -Wall -Wextra)

target_include_directories(AVInterface
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Introduce variables:
# * CMAKE_INSTALL_LIBDIR
# * CMAKE_INSTALL_BINDIR
# * CMAKE_INSTALL_INCLUDEDIR
include(GNUInstallDirs)

# Layout. This works for all platforms:
#   * <prefix>/lib*/cmake/<PROJECT-NAME>
#   * <prefix>/lib*/
#   * <prefix>/include/
set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Use:
#   * PROJECT_VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

install(
    TARGETS AVInterface
    EXPORT "${TARGETS_EXPORT_NAME}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

# Config
#   * <prefix>/lib/cmake/<PROJECT-NAME>/<PROJECT-NAME>Config.cmake
#   * <prefix>/lib/cmake/<PROJECT-NAME>/<PROJECT-NAME>ConfigVersion.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/<PROJECT-NAME>/<PROJECT-NAME>Targets.cmake
install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)

set(test true)

if (test)
  add_subdirectory(UT)
endif()
