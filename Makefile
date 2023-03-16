findtreasure:Reading Game main
	g++ Reading.o Game.o main.o -o findtreasure
Reading:
	g++ -c Reading.cpp -o Reading.o
Game:
	g++ -c Game.cpp -o Game.o
main:
	g++ -c main.cpp -o main.o
	
	

