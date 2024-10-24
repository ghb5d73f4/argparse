# Argument parsing Utility in C/C++

This repository contains a lightweight C/C++ library for parsing command-line arguments.
The library provides utility functions to handle flags, integers, floats, and string arguments passed via the command line.

## Features

- `ParseFlag`: Checks for the presence of a specific flag (e.g. `--help`).
- `ParseInt`: Extracts integer values from the command line.
- `ParseFloat`: Extract floating-point values from the command lines.
- `ParseString`: Extract string values from the command line.
- `CountArgs`: Get the number of non-flag, non-option passed to the program.
- `GetArgs`: Retrieve the non-flag, non-option arguments into a list.

## Usage

### Installation

To use this utility in your project:

Clone this repository or download the files from the `src` subdirectory.

Include `argparse.h` in your project, add `argparse.cpp` in the file to compile and link with the project.

### Function Descriptions

- `int ParseFlag(int argc, const char* argv[], const char* flag)` : Returns 1 if the specified flag is found among the command-line arguments, otherwise returns 0.
- `int ParseInt(int argc, const char* argv[], const char* arg, int orelse)`: Parses an integer from the argument arg. If not found, it returns the fallback value `orelse`.
- `float ParseFloat(int argc, const char* argv[], const char* arg, float orelse)`: Parses a floating-point number from the argument arg. If not found, it returns the fallback value `orelse`.
- `const char* ParseString(int argc, const char* argv[], const char* arg, const char* orelse)`: Parses a string from the argument arg. If not found, it returns the fallback value `orelse`.
- `int CountArgs(int argc, const char* argv[])`: Returns the number of non-flag, non-option arguments passed to the program (i.e. not starting with an `-`).
- `const char** GetArgs(int argc, const char* argv[], int ArgCount)`: Retrieves the arguments counted by `CountArgs` into a list.

The function rely heavily on `sscanf`, so there is no room for mistake when the user passes arguments and options.
But that allows the code writer to use any forms they like (`-`, `--`, ...)

### Example

Here's a simple example of how to use the functions in your program:

```cpp
#include "argparse.h"
#include <iostream>

int main(int argc, const char* argv[]) {
    // Check if a specific flag (e.g., -h) was passed
    if (ParseFlag(argc, argv, "-h")) {
        std::cout << "Help flag detected!\n";
    }

    // Parse an integer argument with default value 10
    int num = ParseInt(argc, argv, "--num=%d", 10);
    std::cout << "Parsed number: " << num << std::endl;

    // Parse a floating-point argument with default value 1.0
    float ratio = ParseFloat(argc, argv, "--ratio=%f", 1.0);
    std::cout << "Parsed ratio: " << ratio << std::endl;

    // Parse a string argument with default "default_value"
    const char* str = ParseString(argc, argv, "--str=%s", "default_value");
    std::cout << "Parsed string: " << str << std::endl;

    return 0;
}
```

## Disclaimer

The code is provided *as is* with no guarantee of working in any condition.
Adapt the use to your own need.
The arrays and buffer allocated by calling the functions are your responsibility to free once they are not used anymore.

## License

This project is licensed under the [CeCILL-C FREE SOFTWARE LICENSE AGREEMENT](https://cecill.info/licences/Licence_CeCILL-C_V1-en.html). See [LICENSE.txt](LICENSE.txt) for more.

## Contributing

Contributions are welcome! Please submit a pull request for any improvements or bug fixes.
