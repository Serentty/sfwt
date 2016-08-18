CC = g++
CFLAGS = -std=c++14 -Wall -Werror -pedantic
LIBS = -lncurses
OBJECTS = main.o PlanetGeneration.o Material.o Calculations.o Renderer.o
VPATH = src

all: sfwt

sfwt: $(OBJECTS)
	@$(CC) -o sfwt $(OBJECTS) $(LIBS)

%.o: %.cpp
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@rm sfwt *.o
