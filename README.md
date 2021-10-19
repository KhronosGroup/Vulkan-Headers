# Vulkan-Headers

Vulkan header files and API registry

## Default branch changed to 'main' 2021-09-12

As discussed in #222, the default branch of this repository is now 'main'. This change should be largely transparent to repository users, since github rewrites many references to the old 'master' branch to 'main'. However, if you have a checked-out local clone, you may wish to take the following steps as recommended by github:

```sh
git branch -m master main
git fetch origin
git branch -u origin/main main
git remote set-head origin -a
```

## Repository Content

The contents of this repository are largely obtained from other repositories
and are collected, coordinated, and curated here.

If proposing changes to any file originating from a different repository,
please propose such changes in that repository, rather than Vulkan-Headers.
Files in this repository originate from:

### Specification repository (https://github.com/KhronosGroup/Vulkan-Docs)

* registry/cgenerator.py
* registry/conventions.py
* registry/generator.py
* registry/genvk.py
* registry/reg.py
* registry/spec_tools/util.py
* registry/validusage.json
* registry/vk.xml
* registry/vkconventions.py
* All files under include/vulkan/ which are *not* listed explicitly as originating from another repository.

### This repository (https://github.com/KhronosGroup/Vulkan-Headers)

* .cmake-format.py
* BUILD.gn
* BUILD.md
* CMakeLists.txt
* CODE_OF_CONDUCT.md
* LICENSE.txt
* README.md
* cmake/Copyright_cmake.txt
* cmake/cmake_uninstall.cmake.in
* Non-API headers (report issues to the [Vulkan-Loader/issues](https://github.com/KhronosGroup/Vulkan-Loader/issues) tracker)
  * include/vulkan/vk_icd.h
  * include/vulkan/vk_layer.h
  * include/vulkan/vk_sdk_platform.h

### Vulkan C++ Binding Repository (https://github.com/KhronosGroup/Vulkan-Hpp)

As of the Vulkan-Docs 1.2.182 spec update, the Vulkan-Hpp headers have been
split into multiple files. All of those files are now included in this
repository.

* include/vulkan/vulkan.hpp
* include/vulkan/vulkan_enums.hpp
* include/vulkan/vulkan_funcs.hpp
* include/vulkan/vulkan_handles.hpp
* include/vulkan/vulkan_raii.hpp
* include/vulkan/vulkan_structs.hpp

## Version Tagging Scheme

Updates to the `Vulkan-Headers` repository which correspond to a new Vulkan
specification release are tagged using the following format:
`v<`_`version`_`>` (e.g., `v1.1.96`).

**Note**: Marked version releases have undergone thorough testing but do not
imply the same quality level as SDK tags. SDK tags follow the
`sdk-<`_`version`_`>.<`_`patch`_`>` format (e.g., `sdk-1.1.92.0`).

This scheme was adopted following the 1.1.96 Vulkan specification release.
