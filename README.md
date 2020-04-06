# Vulkan-Headers

Vulkan header files and API registry

## Advance Notice of Pending Header Change (posted 2020-04-06)

Shortly after 2020-04-24, we will be removing the automatically generated
`VK_*_BEGIN_RANGE`, `VK_*_END_RANGE`, and `VK_*_RANGE_SIZE` tokens
from the Vulkan headers.
These tokens are currently defined for some enumerated types, but are
explicitly not part of the Vulkan API.
They existed only to support some Vulkan implementation internals, which no
longer require them.
We will be accepting comments on this topic in
https://github.com/KhronosGroup/Vulkan-Docs/issues/1230, but we strongly
suggest any external projects using these tokens immediately migrate away
from them.

## Repository Content

The contents of this repository are largely obtained from other repositories and are
collected, coordinated, and curated here.

Do not propose pull requests to this repository which modify any files under
include/vulkan/ or registry/. All such files are generated from the
Vulkan-Docs repository and, in the case of include/vulkan/vulkan.hpp, the
Vulkan-Hpp repository. Any changes must be made in those repositories.

The projects for these repositories are:

- [KhronosGroup/Vulkan-Docs](https://github.com/KhronosGroup/Vulkan-Docs)
  - Core Vulkan headers and Registry
- [KhronosGroup/Vulkan-Hpp](https://github.com/KhronosGroup/Vulkan-Hpp)
  - C++ Bindings for Vulkan

Please visit the appropriate project in the above list for obtaining additional information,
asking questions, or opening issues.

## Version Tagging Scheme

Updates to the `Vulkan-Headers` repository which correspond to a new Vulkan
specification release are tagged using the following format:
`v<`_`version`_`>` (e.g., `v1.1.96`).

**Note**: Marked version releases have undergone thorough testing but do not
imply the same quality level as SDK tags. SDK tags follow the
`sdk-<`_`version`_`>.<`_`patch`_`>` format (e.g., `sdk-1.1.92.0`).

This scheme was adopted following the 1.1.96 Vulkan specification release.
