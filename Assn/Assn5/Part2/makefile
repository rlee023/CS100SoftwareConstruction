CXX=g++
CXXFLAGS=-ggdb -Werror -Wall
OBJECTS=Animal.o Sea_creature.o Mammal.o Bird.o  

all: Animal.o Sea_creature.o Mammal.o Bird.o
	$(CXX) $(CXXFLAGS) $(OBJECTS) main.cc

Animal.o: Animal.h Animal.cc
	$(CXX) $(CXXFLAGS) -c Animal.cc

Sea_creature.o: Sea_creature.h Sea_creature.cc
	$(CXX) $(CXXFLAGS) -c Sea_creature.cc

Mammal.o: Mammal.h Mammal.cc 
	$(CXX) $(CXXFLAGS) -c Mammal.cc

Bird.o: Bird.h Bird.cc
	$(CXX) $(CXXFLAGS) -c Bird.cc
clean: 
	rm Animal.o Sea_creature.o Mammal.o Bird.o a.out
