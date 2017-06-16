objects =
CXX = g++-7.1
INCULDE = -I .
CXXFLAGS = -g -Wall -std=gnu++14 

verify: ./src/verify.cpp
	$(CXX) ./src/verify.cpp -o main $(INCULDE) $(CXXFLAGS)

performance_bench: ./src/performance_bench.cpp
	$(CXX) ./src/performance_bench.cpp -o main $(INCULDE) $(CXXFLAGS)


.PHONY: clean
clean:
	rm main $(objects)
