OBJECTS = bin/insertionSort.o bin/mergeSort.o bin/quickSort.o bin/SinglyLList.o
CXX = g++-7.1
INCULDE = -I .
CXXFLAGS = -g -Wall -std=gnu++17
vpath %.cpp src
vpath %.o   bin

VPATH = bin
verify: bin/verify.o $(OBJECTS)
	$(CXX) $(OBJECTS) bin/verify.o $(INCULDE) $(CXXFLAGS) -o main
bin/verify.o: verify.cpp
	g++-7.1 $< -c $(INCULDE) -o $@
$(OBJECTS): bin/%.o: %.cpp SinglyLList.h
	$(CXX) -c $(CXXFLAGS) $< -o $@

performance_bench: ./src/performance_bench.cpp
	$(CXX) ./src/performance_bench.cpp -o main $(INCULDE) $(CXXFLAGS)



.PHONY: clean
clean:
	rm main $(OBJECTS)
