CPPFLAGS = -g -c -Wall -ansi

OBJETOS = main.o

All: main.x clean

main.x: $(OBJETOS)
	g++ -o main.x $(OBJETOS)

main.o: main.cpp funciones.hpp grafo.hpp lado.hpp macros.hpp vertice.hpp
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f $(OBJETOS)