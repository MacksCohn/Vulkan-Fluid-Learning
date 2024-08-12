CC = g++
CFLAGS = --std=c++17 -O2 -Wall -pedantic -g 
LIB = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
# Your .hpp files 
DEPS = lve_window.hpp lve_pipeline.hpp lve_device.hpp lve_swap_chain.hpp
# Your compiled .o files
OBJECTS = first_app.o lve_window.o lve_pipeline.o lve_device.o lve_swap_chain.o
# The name of your program
PROGRAM = app

.PHONY: all clean lint


all: $(PROGRAM)

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM)

lint:
	cpplint *.cpp *.hpp
