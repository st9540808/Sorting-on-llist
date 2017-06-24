OBJECTS = insertionSort.o mergeSort.o quickSort.o
CXX = g++-7.1
INCULDE = -I .
CXXFLAGS = -g -Wall -std=gnu++17
vpath %.cpp src
vpath %.o   bin

verify: verify.o $(OBJECTS)
	$(CXX) $(OBJECTS) $(INCULDE) $(CXXFLAGS) -o main
verify.o: verify.cpp
	g++-7.1 $< -c $(INCULDE)
$(OBJECTS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c

performance_bench: ./src/performance_bench.cpp
	$(CXX) ./src/performance_bench.cpp -o main $(INCULDE) $(CXXFLAGS)



.PHONY: clean
clean:
	rm main $(OBJECTS)
