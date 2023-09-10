CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion

kodu3: kodu2.cpp
	g++ $(CXXFLAGS) -o kodu2 kodu2.cpp

#tahan teha prax2, vajan selleks prax2.cpp
prax2: prax2.cpp
	g++ $(CXXFLAGS) -o prax2 prax2.cpp

kodu3: kodu3_fun_def.cpp
	g++ $(CXXFLAGS) -o kodu3 kodu3_fun_def.cpp

prax3: prax3.cpp funktsioon.o
	g++ $(CXXFLAGS) -c -o praks3 praks3.cpp funktsioon.o

funktsioon.o: funktsioon.cpp
	g++ $(CXXFLAGS) funktsioon.cpp

PahupidiArv.o: PahupidiArv.cpp	
	g++  $(CXXFLAGS) -c PahupidiArv.cpp

.FORCE:

prax5: prax5.cpp PahupidiArv.o .FORCE
	g++  $(CXXFLAGS) -o prax5 prax5.cpp PahupidiArv.o 
	./prax5
