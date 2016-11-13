# Makefile for compiling libshared and main

# # *****************************************************
# # Variables to control Makefile operation

CXX = clang++
CXXFLAGS = -Weverything -std=c++11


# ****************************************************
# # Targets needed to bring the executable up to date
main: time_daemon.cpp
	@$(CXX) $(CXXFLAGS) -o time_daemon time_daemon.cpp

clean:
	@rm -f time_daemon
