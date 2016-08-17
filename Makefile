CC = g++
CFLAGS = -std=c++14 -Wall -Werror -pedantic
LIBS = -lncurses
OBJECTS = main.o PlanetGeneration.o

all: sfwt

sfwt: $(OBJECTS)
	@$(CC) -o sfwt $(OBJECTS) $(LIBS)

%.o: %.cpp
	@$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

clean:
	@rm sfwt *.o
