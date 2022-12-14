
CFLAGS = -std=c++17 -O2 -Wall -Wextra -Wpedantic -g
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi 

VulkanTest: main.cpp
	g++ $(CFLAGS) -o main *.cpp $(LDFLAGS) && ./compile.sh

.PHONY: test clean



test: main
	./main

clean:
	rm -f main