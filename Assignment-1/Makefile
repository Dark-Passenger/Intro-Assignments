# Makefile for compiling libshared and main

# # *****************************************************
# # Variables to control Makefile operation

CXX = clang++
CXXFLAGS = -Weverything -std=c++11

.PHONY = libshared

# ****************************************************
# # Targets needed to bring the executable up to date
#-L: option to link main to shared library shared.o
main: libshared main.o
	@$(CXX) $(CXXFLAGS) -o main  main.o -L. -lshared
	@export LD_LIBRARY_PATH+=.

# -fPIC: Compiler directive to output position independent code, a characteristic required by shared libraries.
#-shared: Produce a shared object which can then be linked with other objects to form an executable.
#-Wl,options: Pass options to linker. here the option "-soname libshare.so", name is passed with the "-o" option is passed to g++.
libshared: shared.cpp
	@$(CXX) $(CXXFLAGS) -fPIC -c shared.cpp -o shared.o
	@$(CXX) $(CXXFLAGS) -shared  -Wl,-soname,libshared.so -o libshared.so shared.o

clean:
	@rm -f *.o *.so main
