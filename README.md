# Vulkan-Headers

Vulkan header files and API registry

This repository contains Vulkan header files, include files for C and C++,
and related scripts and tests.

Most of the files in this repository are sourced from, or generated from,
other repositories as described in [CONTRIBUTING.md](CONTRIBUTING.md).
Vulkan-Headers exists as a staging area for these files, most of which are
then consumed by downstream repositories used to build SDK components such
as the Vulkan Validation Layers and Conformance Test Suite.

Developers normally obtain headers from the official
[Vulkan-SDK](https://www.lunarg.com/vulkan-sdk/).
They can also use headers from, or packaged from, this repository.

In most cases, developers should only need the headers, not the scripts and
other material in this repository.
In particular if you are packaging the headers for inclusion in Linux
distributions or similar uses, we advise that you do not include the
scripts, and direct potential users of the scripts to their canonical
sources in the [Vulkan Specification
repository](https://github.com/KhronosGroup/Vulkan-Docs).

## Contributing

See the [CONTRIBUTING.md](CONTRIBUTING.md)

## Building

See [BUILD.md](BUILD.md)

## SDK Support

Vulkan-Headers are shipped as part of the official [Vulkan-SDK](https://www.lunarg.com/vulkan-sdk/)

## C/C++ Package Manager Support

`Vulkan-Headers` are also supported by both [conan](https://conan.io/) & [vcpkg](https://learn.microsoft.com/en-us/vcpkg/).

## Version Tagging Scheme

Updates to the `Vulkan-Headers` repository which correspond to a new Vulkan
specification release are tagged using the following format:
`v<`_`version`_`>` (e.g., `v1.3.255`).

**Note**: Marked version releases have undergone thorough testing but do not
imply the same quality level as SDK tags. SDK tags follow the
`sdk-<`_`version`_`>.<`_`patch`_`>` format (e.g., `sdk-1.3.250.0`).
