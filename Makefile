Vector_project: main.o Vector.o
	g++ -c main.o Vector.o -o Vector_project

main.o: main.cpp
	g++ -c main.cpp

Vector.o: Vector.h
	g++ -c Vector.h
