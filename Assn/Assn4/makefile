CXX=g++
CXXFLAGS=-g -Werror -Wall

all: main.o 

main.o: pq_HEAP.H main.cc
	$(CXX) $(CXXFLAGS) main.cc -o out

clean:
	rm out
