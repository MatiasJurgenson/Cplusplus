CXXFLAGS := -std=c++20 -Werror -Wall -Wpedantic -Wconversion
	
%.o: %.cpp
	g++  $(CXXFLAGS) -c -o $@ $<

.FORCE:

prax6: prax6.o osalejad_tulemused.o .FORCE
	g++  $(CXXFLAGS) -o prax6 prax6.o osalejad_tulemused.o
	./prax6