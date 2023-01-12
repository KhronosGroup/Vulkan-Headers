# Vulkan-Headers

Vulkan header files and API registry

The contents of this repository are largely obtained from other repositories
and are collected, coordinated, and curated here.

If proposing changes to any file originating from a different repository,
please propose such changes in that repository, rather than Vulkan-Headers.
Files in this repository originate from:

## Contributing

See the [CONTRIBUTING.md](CONTRIBUTING.md)

## Building

See [BUILD.md](BUILD.md)

## SDK Support

Vulkan-Headers are shipped as part of the official [Vulkan-SDK](https://www.lunarg.com/vulkan-sdk/)

## C/C++ Package Manager Support

`Vulkan-Headers` are also supported by both conan & vcpkg.

## Version Tagging Scheme

Updates to the `Vulkan-Headers` repository which correspond to a new Vulkan
specification release are tagged using the following format:
`v<`_`version`_`>` (e.g., `v1.1.96`).

**Note**: Marked version releases have undergone thorough testing but do not
imply the same quality level as SDK tags. SDK tags follow the
`sdk-<`_`version`_`>.<`_`patch`_`>` format (e.g., `sdk-1.1.92.0`).

This scheme was adopted following the 1.1.96 Vulkan specification release.
