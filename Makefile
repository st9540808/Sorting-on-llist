OBJECTS = bin/insertionSort.o bin/mergeSort.o bin/quickSort.o bin/SinglyLList.o
CXX = g++-7.1
INCULDE = -I .
CXXFLAGS = -g -Wall -std=gnu++17
vpath %.cpp src
vpath %.o   bin

verify: bin/verify.o $(OBJECTS)
	$(CXX) $(OBJECTS) bin/verify.o $(INCULDE) $(CXXFLAGS) -o main
bin/verify.o: verify.cpp
	g++-7.1 $< -c $(INCULDE) -o $@

performance_bench: bin/performance_bench.o $(OBJECTS)
	$(CXX) $(OBJECTS) bin/performance_bench.o $(INCULDE) $(CXXFLAGS) -o main
bin/performance_bench.o: performance_bench.cpp
	g++-7.1 $< -c $(INCULDE) -o $@


$(OBJECTS): bin/%.o: %.cpp SinglyLList.h
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm main $(OBJECTS)
