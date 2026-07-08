# Build and Test Guide

This guide provides comprehensive instructions on how to build, test, and run the Algorithmic Trading Backtester application. It covers prerequisites, a quick start using Make, a detailed workflow using CMake, and steps for IDE integration.

## 1. Prerequisites

Before you begin, ensure you have the following installed on your system:

*   **A C++20 Compliant Compiler**: Such as GCC, Clang, or MSVC.
*   **CMake**: Version 4.2 or later.
*   **Qt**: Version 6.x. You must set the `Qt6_ROOT` environment variable to your Qt installation path.
    ```shell
    export Qt6_ROOT=/path/to/your/Qt/6.x.x/gcc_64
    ```
*   **Make**: The `make` utility is required for the simplified workflow. It is typically pre-installed on Linux and macOS.

## 2. Quick Start with Make (Recommended)

For a simplified development experience, a `Makefile` is provided to wrap the underlying CMake commands.

*   **Build the project:**
    ```shell
    make
    ```
    This configures the project and compiles the application and tests.

*   **Build for IDE integration:**
    ```shell
    make dev
    ```
    This is the recommended command for the first build. It creates a `compile_commands.json` file, which is essential for IDEs and code analysis tools (see section 5 for details).

*   **Run tests:**
    ```shell
    make test
    ```
    This executes all test suites.

*   **Run the application:**
    ```shell
    make run
    ```
    This builds the project if necessary and runs the main application.

*   **Clean build artifacts:**
    ```shell
    make clean
    ```
    This removes compiled object files and executables but keeps the build configuration.

*   **Full project clean:**
    ```shell
    make distclean
    ```
    This removes the entire `build` directory, forcing a complete reconfiguration and rebuild on the next `make` command.

## 3. Detailed Workflow with CMake

If you don't have `make` or prefer to use CMake directly, you can use the following commands from the project's root directory.

*   **1. Configure the Project (Run Once):**
    To configure for standard builds:
    ```shell
    cmake -S . -B build -DBUILD_TESTING=ON
    ```
    To generate `compile_commands.json` for IDE support:
    ```shell
    cmake -S . -B build -DBUILD_TESTING=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    ```

*   **2. Build the Project:**
    ```shell
    cmake --build build
    ```

*   **3. Run Tests:**
    ```shell
    cmake --build build --target test
    ```
    Alternatively, you can use CTest directly from the build directory: `cd build && ctest`.

*   **4. Run the Application:**
    ```shell
    cmake --build build --target run
    ```

*   **5. Clean Build Artifacts:**
    CMake generates a `clean` target with build systems like Make and Ninja.
    ```shell
    cmake --build build --target clean
    ```

## 4. IDE Integration

This project is configured to work smoothly with modern C++ IDEs.

### CLion

Open the project by selecting the root `CMakeLists.txt` file. CLion will automatically detect the CMake project, configure it, and provide build/run/test configurations.

### Visual Studio Code (with CMake Tools Extension)

1.  Install the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) and [C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) extensions.
2.  Open the project folder in VS Code.
3.  When prompted, select a C++ compiler (Kit).
4.  The CMake Tools extension will automatically find the `CMakeLists.txt` and configure the project.
5.  You can build, run, and test using the commands in the VS Code command palette (`Ctrl+Shift+P`) or the status bar icons.

For best results, ensure `compile_commands.json` has been generated (`make dev` or by setting `CMAKE_EXPORT_COMPILE_COMMANDS` to `1`). The C++ extension uses this file to provide highly accurate code completion, navigation, and error highlighting.

## 5. Understanding `compile_commands.json`

The `compile_commands.json` file is a standard format for recording the exact compiler commands used to build the source files in a project.

### Why is it important?

Modern C++ development relies heavily on tooling for productivity. Language Server Protocol (LSP) servers, which power features like auto-completion, code navigation (`Go to Definition`), and real-time error checking in IDEs, need to understand how your code is compiled. This includes knowing the include paths, compiler flags, and preprocessor definitions.

The `compile_commands.json` file provides this information in a machine-readable format. By reading this file, tools can:

*   **Provide Accurate IntelliSense**: Understand all the types and functions available to each source file.
*   **Enable Precise Static Analysis**: Tools like `clang-tidy` can analyze your code with the same configuration as the compiler, leading to more relevant warnings.
*   **Improve Refactoring**: Safely perform complex refactoring operations with full knowledge of the codebase.

In short, generating this file is crucial for enabling the full power of your IDE and other development tools.
