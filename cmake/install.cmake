include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # Windows: if install locations not set by user, set install prefix to "<build_dir>\install".
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install" CACHE PATH "default install path" FORCE)
endif()

# uninstall target
if(NOT TARGET uninstall)
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
                   "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
                   IMMEDIATE
                   @ONLY)
    add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

# Location registry files will be installed to
set(VLK_REGISTRY_DIR "${CMAKE_INSTALL_DATADIR}/vulkan")

# Install header files
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vk_video" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/vulkan" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# Install registry files
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/registry" DESTINATION ${VLK_REGISTRY_DIR})

set(export_name "VulkanHeadersConfig")
set(namespace "Vulkan::")
set(cmake_files_install_dir ${CMAKE_INSTALL_DATADIR}/cmake/VulkanHeaders/)

# Set EXPORT_NAME for consistency with established names. The CMake generated ones won't work.
set_target_properties(Vulkan-Headers PROPERTIES EXPORT_NAME "Headers")
set_target_properties(Vulkan-Registry PROPERTIES EXPORT_NAME "Registry")

# Add find_package() support
target_include_directories(Vulkan-Headers INTERFACE $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
install(TARGETS Vulkan-Headers EXPORT ${export_name})

target_include_directories(Vulkan-Registry INTERFACE $<INSTALL_INTERFACE:${VLK_REGISTRY_DIR}/registry>)
install(TARGETS Vulkan-Registry EXPORT ${export_name})

install(EXPORT ${export_name} NAMESPACE ${namespace} DESTINATION ${cmake_files_install_dir})
export(TARGETS Vulkan-Headers NAMESPACE ${namespace} FILE ${export_name}.cmake)

set(config_version "${CMAKE_CURRENT_BINARY_DIR}/${export_name}Version.cmake")

# Add find_package() versioning support
write_basic_package_version_file(${config_version} COMPATIBILITY SameMajorVersion ARCH_INDEPENDENT)

install(FILES ${config_version} DESTINATION ${cmake_files_install_dir})
