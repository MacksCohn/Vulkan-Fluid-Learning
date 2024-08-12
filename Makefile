CC = g++
CFLAGS = --std=c++17 -O2 -Wall -pedantic -g 
LIB = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
# Your .hpp files 
DEPS = lve_window.hpp lve_pipeline.hpp lve_device.hpp lve_swap_chain.hpp
# Your compiled .o files
OBJECTS = first_app.o lve_window.o lve_pipeline.o lve_device.o lve_swap_chain.o
# The name of your program
PROGRAM = app

# spv list and set as dependency
vertSources = $(shell find ./shaders -type f -name "*.vert")
vertObjFiles = $(patsubst %.vert, %.vert.spv, $(vertSources))
fragSources = $(shell find ./shaders -type f -name "*.frag")
fragObjFiles = $(patsubst %.frag, %.frag.spv, $(fragSources))

.PHONY: all clean lint


all: $(PROGRAM) shaders

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<


shaders: $(vertObjFiles) $(fragObjFiles)
$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

# Shader targets
%.spv: %
	/usr/local/bin/glslc $< -o $@

clean:
	rm *.o $(PROGRAM) shaders/*.spv

lint:
	cpplint *.cpp *.hpp
