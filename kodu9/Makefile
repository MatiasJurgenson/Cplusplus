CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

andmed.o: andmed.cpp	
	g++  $(CXXFLAGS) -c andmed.cpp

.FORCE:

kodu9: kodu9.cpp andmed.o .FORCE
	g++  $(CXXFLAGS) -o kodu9 kodu9.cpp andmed.o
	./kodu9