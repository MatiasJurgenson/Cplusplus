CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

raamat.o: raamat.cpp	
	g++  $(CXXFLAGS) -c raamat.cpp

.FORCE:

praks9: praks9.cpp raamat.o .FORCE
	g++  $(CXXFLAGS) -o praks9 praks9.cpp raamat.o
	./praks9