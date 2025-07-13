# msvc2013-cpp11-patch
A lightweight patch library providing C++11 compatibility and bug fixes for MSVC2013.

## Overview

**msvc2013-cpp11-patch** provides safe, portable replacements and workarounds for C++11 features that are missing or broken in Visual Studio 2013 (MSVC2013).  
It is designed to help legacy projects or open-source libraries build and run reliably on MSVC2013, while using the standard library on modern compilers.

## Features

- Drop-in replacements for C++11 features such as `once_flag` and `call_once`
- Exception-safe and retryable one-time initialization
- Automatically uses the standard library on modern compilers
- Clean, minimal API in the `cpp11patch` namespace
- Easy integration with legacy and modern codebases

## Directory Structure

```
/
├── include/         # Public headers (e.g., cpp11patch/mutex.h)
├── examples/        # Usage examples
├── tests/           # gtest-based unit tests
├── .gitignore
├── CHANGES.md
├── LICENSE
└── README.md
```

## Usage

1. **Include the header:**
    ```cpp
    #include 
    ```

2. **Use the API:**
    ```cpp
    cpp11patch::once_flag flag;

    void initialize(int value) {
        // Initialization code here
    }

    int main() {
        cpp11patch::call_once(flag, initialize, 42);
        return 0;
    }
    ```

- On MSVC2013 and earlier, the custom implementation is used.
- On modern compilers, the standard library is used automatically.

## Example

```cpp
#include 
#include 

cpp11patch::once_flag flag;

void my_init(int x) {
    std::cout << "Initialize: " << x << std::endl;
}

int main() {
    cpp11patch::call_once(flag, my_init, 42);
    cpp11patch::call_once(flag, my_init, 99); // This call will not execute the function again
    return 0;
}
```

## Supported Compilers

- **MSVC2013 and earlier**: Uses custom patch implementations
- **MSVC2015+, GCC, Clang, etc.**: Uses the standard library

## Limitations

- This library only patches a subset of C++11 features.  
  Contributions for other missing or broken features are welcome!
- Not needed or recommended for modern compilers.

## License

MIT License