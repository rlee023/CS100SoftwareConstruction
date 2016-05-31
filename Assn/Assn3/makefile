CXX=g++
CXXFLAGS=-w -Werror -ggdb 

all: zero.o one.o

zero.o: zero.cc pq_HEAP.H
	$(CXX) $(CXXFLAGS) zero.cc -o zero

one.o: one.cc pq_ONE.H
	$(CXX) $(CXXFLAGS) one.cc -o one
clean:
	rm zero one
