CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

stuff.o: stuff.cpp	
	g++  $(CXXFLAGS) -c stuff.cpp

.FORCE:

prax12: prax12.cpp stuff.o .FORCE
	g++  $(CXXFLAGS) -o prax12 prax12.cpp stuff.o
	./prax12