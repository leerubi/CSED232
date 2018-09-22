all: assn1

assn1: main.o ToppingList.o DoughList.o EdgeList.o Topping.o Dough.o Edge.o
	g++ -o assn1 main.o ToppingList.o DoughList.o EdgeList.o Topping.o Dough.o Edge.o

main.o: main.cpp ToppingList.hpp DoughList.hpp EdgeList.hpp Topping.hpp Dough.hpp Edge.hpp
	g++ -c main.cpp
Topping.o: Topping.cpp Topping.hpp
	g++ -c Topping.cpp
Dough.o: Dough.cpp Dough.hpp
	g++ -c Dough.cpp
Edge.o: Edge.cpp Edge.hpp
	g++ -c Edge.cpp
ToppingList.o: ToppingList.cpp ToppingList.hpp Topping.hpp
	g++ -c ToppingList.cpp
DoughList.o: DoughList.cpp DoughList.hpp Dough.hpp
	g++ -c DoughList.cpp
EdgeList.o: EdgeList.cpp EdgeList.hpp Edge.hpp
	g++ -c EdgeList.cpp

