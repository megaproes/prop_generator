# File Properties Scanner

## Project Description
The File Properties Scanner is a command-line application designed to scan file properties in a specified directory and generate reports in chosen formats (TXT, CSV, JSON, XML). Reports are generated in the directory from which the program was launched.

## Usage
To launch the application, you need to open the command line, navigate to the directory containing the `Task1.exe` executable file, and run it with the necessary arguments. The first argument is the directory to scan, the rest are report formats.

Example of usage:
Task1 <directory> <report_format1> <report_format2> ... <report_formatn>

Example:
Task1 C:\ xml json

This command will generate two reports, in XML and JSON formats whereis `Task1.exe` located.

## Compilation

You will need CMake to compile the program. 

1. Create a `build` directory and navigate into it.

2. Run CMake, pointing it to the source files: `cmake ..`

3. Build the project: `cmake --build .`

As a result, the `Task1.exe` executable file will appear in the `bin` directory. This file is static, meaning you can move it anywhere without needing to transfer additional libraries.

## Future Development
The project is still in development. All updates will be added to this repository as they are completed.



