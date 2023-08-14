<!--
Copyright 2018-2023 The Khronos Group Inc.

SPDX-License-Identifier: Apache-2.0
-->

# Integrating Updated Vulkan Headers into Vulkan Repositories

- This guide assumes the [Vulkan-Headers](https://github.com/KhronosGroup/Vulkan-Headers), [Vulkan-Loader](https://github.com/KhronosGroup/Vulkan-Loader), [Vulkan-Tools](https://github.com/KhronosGroup/Vulkan-Tools), [Vulkan-ValidationLayers](https://github.com/KhronosGroup/Vulkan-ValidationLayers), [LunarG/VulkanSamples](https://github.com/LunarG/VulkanSamples), and [LunarG/VulkanTools](https://github.com/LunarG/VulkanTools) repositories have been cloned to a known directory on the system. If necessary, see the `BUILD.md` file in each repository for information on how to clone and build the projects.
- If build issues exist at any point in the Vulkan header integration process, include the fix in the known-good update commit, propose a fix by creating a pull request, or create an issue in the relevant repository and wait for resolution.

# Clone and build the Vulkan-Headers

The first step of integrating Vulkan header updates is to checkout and build the desired Vulkan-Headers commit. Typically this is the latest tagged release.

Pull and build the dependent repositories

Update the Vulkan-Loader, Vulkan-ValidationLayers, and Vulkan-Tools known-good files

### Recommended order for updating the repositories

If the known-good of a repository needs to be updated, all repositories of interest that appear in its known-good files must be updated first using the procedure described in this wiki. See section [5. Update the Known Good Files](https://github.com/KhronosGroup/Vulkan-Headers/wiki/Integrating-Updated-Vulkan-Headers-into-Vulkan-Repositories/#5-update-the-known-good-files) for a list of dependencies per repository. The following list indicates the preferred known-good update order:
1. Vulkan-Loader
1. Vulkan-ValidationLayers
3. Vulkan-Tools
4. LunarG repositories when applicable

**Notes**:
* Typically the Vulkan-Loader's known-good is updated first, but the Vulkan-ValidationLayers known-good can also be updated first.
* The Vulkan-ValidationLayers GitHub CI currently contains a dependency on LunarG-VulkanTools. Occasionally Vulkan-Header updates require changes to be made to LunarG-VulkanTools before updating Vulkan-ValidationLayers known-good files (see the [update LunarG known-good section](https://github.com/KhronosGroup/Vulkan-Headers/wiki/Integrating-Vulkan-Header-Updates-into-Vulkan-Repositories#update-the-lunargvulkantools-and-lunargvulkansamples-known-good-files) below for more information).

### 1. Checkout and pull the `master` branch

Navigate to the directory of the project of interest and checkout the `master` branch. Pull in the most recent commits.

### 2. Generate new source files using `scripts/generate_source.py`

Using your favorite command prompt, navigate to the `scripts` directory and run the `generate_source.py` script. This script requires the specification of the location of the `Vulkan-Headers/registry` directory on the system. An example of how to run this script:
```
./generate_source.py ../../Vulkan-Headers/registry/
```

#### 2-1. Propogate `genvk.py` changes

All Khronos repositories and LunarG/VulkanTools contain a flavor of Vulkan-Headers's `genvk.py`. If `genvk.py` in the Vulkan-Headers repository is modified, the same changes must be made to each version of the file in each repository as part of the header update.

#### 2-2. Vulkan-ValidationLayers sub-step: check for VUID inconsistencies

In Vulkan-ValidationLayers, every time the `generate_source.py` script is run a new VUID database is generated. When VUIDs are added, removed, or modified consistency testing must be performed. The `vk_validation_stats.py` script found in the ValidationLayers `scripts` directory can be used to report consistency warnings using the `-c` option.
```
./vk_validation_stats.py ../../Vulkan-Headers/registry/validusage.json -c
```
All consistency warnings must be resolved and included in the pull request for the repository's known-good update.

### 3. Build the project

Build the project, referring to the `BUILD.md` file in the directory if necessary.

### 4. Test the build

  - To test the Vulkan-Loader build, run the loader tests (`run_all_tests.sh`) found in the `build/tests` directory. Information on how to build and run the tests can be found in the [Vulkan-Loader `BUILD.md`](https://github.com/KhronosGroup/Vulkan-Loader/blob/master/BUILD.md) file. **Note**: The `VK_LAYER_PATH` environment variable must be set to point at the layers found in `Vulkan-Loader/build/tests/layers` when running the loader tests.
  
  - To test the Vulkan-ValidationLayers build, run the validation layers tests (`vk_layer_validation_tests`) found in the `build/tests` directory. Information on how to build and run the tests can be found in the [Vulkan-ValidationLayers `BUILD.md`](https://github.com/KhronosGroup/Vulkan-ValidationLayers/blob/master/BUILD.md) file.
  
  - To test the Vulkan-Tools build, run `vkcube` and verify `vulkaninfo` produces reasonable output. More information on how to use `vulkaninfo` can be found [here](https://github.com/KhronosGroup/Vulkan-Tools/blob/master/vulkaninfo/vulkaninfo.md).

### 5. Update the known-good files

Every repository contains a `scripts/known_good.json` file which contains information about the known good commits for each dependent repository. Some repositories require an additional known-good file to be updated for Android builds and are specified below. Known-good updates require updating only the "commit" values of the relevant JSON objects. Using an existing tag for this value is preferred over using a full commit id. If a tag does not exist, typically the most recent commit on `master` is chosen for updating the known good. **Note**: Do not change commit values for repositories not listed below unless an update is absolutely required.

  - Vulkan-Loader: Update requires specifying a new `Vulkan-Headers` commit in `scripts/known_good.json`

  - Vulkan-ValidationLayers: Update requires specifying a new `Vulkan-Headers` commit in `scripts/known_good.json`. Additionally, new `Vulkan-Headers` and `Vulkan-Tools` commits must be specified in the `build-android/known_good.json` file.

  - Vulkan-Tools: Update requires specifying new `Vulkan-Headers` and `Vulkan-Loader` commits in `scripts/known_good.json`. Additionally, a new `Vulkan-Headers` commit must be specified in the `vulkan-headers_revision_android` file.

### 6. Commit changes

Commit all changes (e.g., newly generated scripts, known-good files, etc.) in a single commit on a branch and push it up to the online repository. In Vulkan-ValidationLayers, VUID inconsistency resolutions can be included in a single commit with the known-good update or on the same branch in a separate commit.

### 7. Create a pull request in the relevant repository

Verify the branch with the proposed known-good commit is rebased on the tip of `master` and create a pull request in the GitHub repository. The repository owner will assign someone with push rights and specify reviewers for the PR. Prior to approval, the proposed changes will be run through internal LunarG CI testing.

### 8. Rebase changes onto `master`

Once the known-good update PR is approved, the assignee will rebase the approved commits onto the `master` branch.

### 9. Tag the known-good commit

Once approved and rebased onto `master`, the known-good update commit must be marked with a version tag. For more information on the version tag format see the "Version Tagging Scheme" section of each repository's `BUILD.md` file

## Update the LunarG/VulkanTools and LunarG/VulkanSamples known-good files

Updating the Known-good files in LunarG repositories follows the same steps as updating the known-good files in the Khronos repositories.

### Testing LunarG builds

  - LunarG/VulkanTools: Build Debug and Release on Linux and Windows. Verify vktrace/replay works. Verify several of the layers built in this repo work.
  - LunarG/VulkanSamples: Build all and run a few of the Vulkan Samples. Instructions on how to build and run the LunarG Vulkan samples can be found in the repository's [`BUILD.md` file](https://github.com/LunarG/VulkanSamples/blob/master/BUILD.md).

### Updating LunarG known-good files

- LunarG/VulkanTools: Update requires specifying new `Vulkan-Headers`, `Vulkan-Loader`, `Vulkan-Tools`, and `Vulkan-ValidationLayers` commits in `scripts/known_good.json`. Additionally, the new `Vulkan-Headers` commit must be specified in the `build-android/vulkan-headers_revision_android` file and the new `Vulkan-Tools` commit must be specified in the `build-android/vulkan-tools_revision_android` file.
- LunarG/VulkanSamples: Update requires specifying new `Vulkan-Headers` and `Vulkan-Loader` commits in `scripts/known_good.json`.
