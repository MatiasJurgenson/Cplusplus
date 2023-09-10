CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

minutaisarv.o: minutaisarv.cpp	
	g++  $(CXXFLAGS) -c minutaisarv.cpp	

algarv.o: algarv.cpp	
	g++  $(CXXFLAGS) -c algarv.cpp	

toit.o: toit.cpp	
	g++  $(CXXFLAGS) -c toit.cpp	

.FORCE:

kodu6: kodu6.cpp minutaisarv.o algarv.o toit.o .FORCE
	g++  $(CXXFLAGS) -o kodu6 kodu6.cpp minutaisarv.o algarv.o toit.o
	./kodu6

loomad.o: loomad.cpp	
	g++  $(CXXFLAGS) -c loomad.cpp	

yl3: yl3.cpp loomad.o .FORCE
	g++  $(CXXFLAGS) -o yl3 yl3.cpp loomad.o
	./yl3
