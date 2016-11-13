# Makefile for compiling libshared and main

# # *****************************************************
# # Variables to control Makefile operation

CXX = clang++
CXXFLAGS = -Weverything -std=c++11 -pthread

# ****************************************************
# # Targets needed to bring the executable up to date

main:
	@$(CXX) $(CXXFLAGS) main.cpp -o main

clean:
	@rm -f main
