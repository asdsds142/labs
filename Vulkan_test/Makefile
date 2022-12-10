
CFLAGS = -std=c++17 -O2 -Wall -Weffc++ -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wenum-compare -Wfloat-equal -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wextra-semi
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi 

VulkanTest: main.cpp
	g++ $(CFLAGS) -o main *.cpp $(LDFLAGS)

.PHONY: test clean

test: main
	./main

clean:
	rm -f main