# CS 300 Final Project Write-up

## Project: WikiLadder
## Team Members: Elisabeth Molen and Sam Miller Phillips

### Project Description
- A project to build the path from one Wikipedia article page to another.

### Compile/Execute:
- To use the cpr library we had to use cmake rather than a Makefile.
- To run things:
1. Make sure you're in the WikiLadder directory.
2. mkdir cmake_build
3. cd cmake_build
4. cmake ..
5. cmake --build .
6. make
7. ./WikiLadder
8. You should just be able to call make and ./WikiLadder to recompile and then run after any changes (see our Unit Tests approach for why this might be needed).  Just need to make sure you're in the cmake_build directory.

### Unit Tests:
- Our unit tests are written in the UnitTests class.
- Because we are using cmake, it wasn't ideal to write a new main file to run the unit tests.
- We discussed with Joe that we are adding two main() functions to main.cpp.  One is the normal main() to run the project itself.  The other is the main() to run unit tests.  You can comment out the one you're not wanting to run.  We are submitting with the project ready to run (i.e., unit test main() commented out).

### Notes:
- To Compile and Execute: Use the CMakeLists.txt file to create a cmake build.  As discussed with Dr. Wagner and TAs, the only way we could get the cpr library to work was to use a CMake, which is why we're doing this instead of a Makefile.  Given the amount of trouble Sam had getting the cpr library to work on her machine, there is a possibility this project may not work easily on all machines.  As also discussed, we are happy to demo the code fully.  Thank you again for understanding!
- docs folder contains the index.html for the doxygen comments page.
- Screenshots folder contains some screenshots from running the program. Useful to demonstrate how the program will run on page selections that take longer to run.  (Note the screenshots were taken prior to us adding the length of the path to the terminal output, but things should otherwise be the same).

### Linter:
- We used a CLion Project to create our final project.
- We used the built-in linter for C/C++ in Clion, which is Clang-Tidy.
- Clang-Tidy is a clang based linter that is useful for programming errors including "style violations, interface misuse, or bugs" (https://clang.llvm.org/extra/clang-tidy/)
- Clion displays Clang-Tidy checks in the same way as Clion's own inspections and allowed us to quickly fix code by following the suggestions.
- We used the default option for Clang-Tidy checks, which includes seeing the checks as warnings in the editor. Clang-Tidy is modular by nature and allows developers to write new checks relatively easily. We felt the default checks were sufficient for our purposes.
- The warnings were helpful in understanding how we could improve our project.  One prime example was finding instances where we had forgotten to implement const correctness on a particular function.
- The CLion project also worked with doxygen, so it helped catch when a doxygen comment had not been properly written.
