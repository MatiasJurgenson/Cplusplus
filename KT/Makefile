CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

alfalt.o: alfalt.cpp	
	g++  $(CXXFLAGS) -c alfalt.cpp

.FORCE:

kt: kt.cpp alfalt.o .FORCE
	g++  $(CXXFLAGS) -o kt kt.cpp alfalt.o
	./kt