test : graph.o  main.o
	g++ -o test main.o graph.o 

main.o : main.cpp
	g++ main.cpp -c

graph.o : graph.cpp
	g++ graph.cpp -c

