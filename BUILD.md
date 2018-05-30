# Build Instructions

Instructions for building this repository on Windows, Linux, and MacOS.

Since this repository doesn't contain any build targets for libraries
or executables, there usually isn't any need to "build" this repository.
However, `install` and `uninstall` targets are provided if you have a need to
install the Vulkan headers and registry files to system directories
or other location for use by other repositories.

## Index

1. [Contributing](#contributing-to-the-repository)
2. [Repository Set-Up](#repository-set-up)
3. [Installed Files](#installed-files)
4. [Windows Build](#building-on-windows)
5. [Linux Build](#building-on-linux)
6. [MacOS build](#building-on-macos)

## Contributing to the Repository

The contents of this repository are sourced primarily from the
[Khronos Vulkan API specification repository](https://github.com/KhronosGroup/Vulkan-Docs).
Please visit that repository for information on contributing.

## Repository Set-Up

### Download the Repository

To create your local git repository:

    git clone https://github.com/KhronosGroup/Vulkan-Headers.git

## Installed Files

The `install` target installs the following files under the directory
indicated by "install_dir":

- `install_dir/include/vulkan` : The header files found in the
 `include/vulkan` directory of this repository
- `install_dir/share/vulkan/registry` : The registry files found in the
  `registry` directory of this repository

## Building On Windows

### Windows Build Requirements

Windows 7+ with the following software packages:

- Microsoft Visual Studio 2013 Update 4 Professional, VS2015 (any version), or VS2017 (any version).
- [CMake](http://www.cmake.org/download/)
  - Tell the installer to "Add CMake to the system PATH" environment variable.
- [Git](http://git-scm.com/download/win)
  - Tell the installer to allow it to be used for "Developer Prompt" as well as "Git Bash".
  - Tell the installer to treat line endings "as is" (i.e. both DOS and Unix-style line endings).
  - Install both the 32-bit and 64-bit versions, as the 64-bit installer does not install the
    32-bit libraries and tools.

### Windows Build - Microsoft Visual Studio

The general approach is to run `cmake` to generate the VS project files.
Then either run `cmake` again to build from the command line or use the
Visual Studio IDE to open the generated solution and work with the solution
interactively.

It should be possible to perform these `cmake` invocations from any one of the Windows
"terminal programs", including the standard Windows Command Prompt, MSBuild Command Prompt,
PowerShell, MINGW, CygWin, etc.

#### Use `cmake` to create the VS project files

Switch to the top of the cloned repository directory,
create a build directory and generate the VS project files:

    cd Vulkan-Headers
    mkdir build
    cd build
    cmake ..

The default install directory location is `$CMAKE_BINARY_DIR\install`,
which is your `Vulkan-Headers\build\install` directory.

This default setting sets the install destination to
`Vulkan-Headers\build\install`
and causes the header files to be installed to
`Vulkan-Headers\build\install\include/vulkan`
and the registry files to be installed to
`Vulkan-Headers\build\install\share\vulkan\registry`.

The install location can be changed with the `CMAKE_INSTALL_PREFIX` variable.

For example:

    cd Vulkan-Headers
    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=/c/Users/dev/install ..  # MINGW64 shell

As it starts generating the project files, `cmake` responds with something like:

    -- Building for: Visual Studio 14 2015

which is a 32-bit generator.

Since this repository does not compile anything, there is no need
to specify a specific generator such as "Visual Studio 14 2015 Win64",
so the default generator should suffice.

This creates a Windows solution file named `Vulkan-Headers.sln`
in the build directory.

At this point, you can build the solution from the command line or open the
generated solution with Visual Studio.

#### Build the solution from the command line

While still in the build directory:

    cmake --build . --target install

to build the install target.

Build the `uninstall` target to remove the files from the install location.

    cmake --build . --target uninstall

#### Build the solution with Visual Studio

Launch Visual Studio and open the "Vulkan-Headers.sln" solution file in the build folder.
Build the `INSTALL` target from the Visual Studio solution explorer.

Build the `uninstall` target to remove the files from the install location.

    cmake --build . --target uninstall

## Building On Linux

### Linux Build Requirements

There are no specific Linux distribution or compiler
verison requirements for building this repository.

### Linux Build

Switch to the top of the cloned repository directory,
create a build directory and generate the make files:

    cd Vulkan-Headers
    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=install ..

Set the `CMAKE_INSTALL_PREFIX` variable to the directory to serve as the
destination directory for the `install` target.
The above setting sets the install destination to
`Vulkan-Headers/build/install`
which causes the header files to be installed to
`Vulkan-Headers/build/install/include/vulkan`
and the registry files to be installed to
`Vulkan-Headers/build/install/share/vulkan/registry`

For Linux, the default value for `CMAKE_INSTALL_PREFIX` is `/usr/local`,
which would be used if you do not specify `CMAKE_INSTALL_PREFIX`.
In this case, you may need to use `sudo` to install to system directories
later when you run `make install`.

Note that after generating the make files, running `make`:

    make

does nothing, since there are no libraries or executables to build.

To install the header files:

    make install

To uninstall the files from the install directories, you can execute:

    make uninstall

## Building on MacOS

The instructions for installing the headers for MacOS are the
same as those for Linux.
