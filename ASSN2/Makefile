all: assn2

assn2: main.o Game.o Object.o Torpedo.o Boat.o BoatA.o BoatB.o BoatC.o BoatAList.o BoatBList.o BoatCList.o
	g++ -o assn2 main.o Game.o Object.o Torpedo.o Boat.o BoatA.o BoatB.o BoatC.o BoatAList.o BoatBList.o BoatCList.o

main.o: main.cpp Game.hpp Object.hpp Torpedo.hpp Boat.hpp BoatA.hpp BoatB.hpp BoatC.hpp BoatAList.hpp BoatBList.hpp BoatCList.hpp
	g++ -c main.cpp
Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp
Object.o: Object.cpp Object.hpp
	g++ -c Object.cpp
Torpedo.o: Torpedo.cpp Torpedo.hpp
	g++ -c Torpedo.cpp
Boat.o: Boat.cpp Boat.hpp
	g++ -c Boat.cpp
BoatA.o: BoatA.cpp BoatA.hpp
	g++ -c BoatA.cpp
BoatB.o: BoatB.cpp BoatB.hpp
	g++ -c BoatB.cpp
BoatC.o: BoatC.cpp BoatC.hpp
	g++ -c BoatC.cpp
BoatAList.o: BoatAList.cpp BoatAList.hpp BoatA.hpp
	g++ -c BoatAList.cpp
BoatBList.o: BoatBList.cpp BoatBList.hpp BoatB.hpp
	g++ -c BoatBList.cpp
BoatCList.o: BoatCList.cpp BoatCList.hpp BoatC.hpp
	g++ -c BoatCList.cpp
