CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

arvutused.o: arvutused.cpp	
	g++  $(CXXFLAGS) -c arvutused.cpp

.FORCE:

kodu8: kodu8.cpp arvutused.o .FORCE
	g++  $(CXXFLAGS) -o kodu8 kodu8.cpp arvutused.o
	./kodu8