CC = g++
CFLAGS = --std=c++17 -O2 -Wall -pedantic -g 
LIB = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
# Your .hpp files 
DEPS =
# Your compiled .o files
OBJECTS = lve_pipeline.o my_engine_device.o
# The name of your program
PROGRAM = test

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
