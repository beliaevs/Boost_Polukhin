# Boost_Polukhin

Sample programs from the book "Boost C++ Application Development" by Anton Polukhin.

## Building

Makefiles for building under linux are provided.
CMakeLists.txt for cmake are also here.
To use them simply create "build" subdirectory, cd into it and run:

cmake ../

### Universal building with cmake

In previously created build directory, run

cmake --build .

### Build with Visual Studio from command line

msbuild any_variant.sln /property:Configuration=Release // or Debug
