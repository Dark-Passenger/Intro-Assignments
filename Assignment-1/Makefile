# Makefile for compiling libshared and main

# # *****************************************************
# # Variables to control Makefile operation

CXX = g++

# ****************************************************
# # Targets needed to bring the executable up to date
#-L: option to link main to shared library shared.o
main: libshared.so main.o
	$(CXX) -o main  main.o -L. -lshared

# -fPIC: Compiler directive to output position independent code, a characteristic required by shared libraries.
#-shared: Produce a shared object which can then be linked with other objects to form an executable.
#-Wl,options: Pass options to linker. here the option "-soname libshare.so", name is passed with the "-o" option is passed to g++.
libshared: shared_lib.cpp
	$(CXX) -fPIC -c shared_lib.cpp -o shared.o
	$(CXX) -shared  -Wl,-soname,libshared.so -o libshared.so shared.o

clean:
  $rm *.o *.so
