# Build Instructions

Instructions for building this repository.

```bash
git clone https://github.com/KhronosGroup/Vulkan-Headers.git

cd Vulkan-Headers/

# Configure the project
cmake -S . -B build/

# Because Vulkan-Headers is header only we don't need to build anything.
# Users can install it where they need to.
cmake --install build --prefix build/install
```

See the official [CMake documentation](https://cmake.org/cmake/help/latest/index.html) for more information.

## Installed Files

The `install` target installs the following files under the directory
indicated by *install_dir*:

- *install_dir*`/include/vulkan` : The header files found in the
 `include/vulkan` directory of this repository
- *install_dir*`/share/cmake/VulkanHeaders`: The CMake config files needed
  for find_package support
- *install_dir*`/share/vulkan/registry` : The registry files found in the
  `registry` directory of this repository

## Usage in CMake

The library provides a Config file for CMake, once installed it can be found via `find_package`.

Which, when successful, will create the header only library `Vulkan::Headers` which you can use via the usual `target_link_libraries` mechanism.

```cmake
find_package(VulkanHeaders REQUIRED CONFIG)

target_link_libraries(foobar PRIVATE Vulkan::Headers)

message(STATUS "Vulkan Headers Registry: ${VULKAN_HEADERS_REGISTRY_DIRECTORY}")

message(STATUS "Vulkan Headers Version: ${VulkanHeaders_VERSION}")
```
