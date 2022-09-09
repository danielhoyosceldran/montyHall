montyHall: montyHall.o coutGenerator.o
	g++ -o montyHall montyHall.o coutGenerator.o

montyHall.o: montyHall.cpp ../GeneradorCout/coutGenerator.h
	g++ -c montyHall.cpp

coutGenerator.o: ../GeneradorCout/coutGenerator.cpp ../GeneradorCout/coutGenerator.h
	g++ -c ../GeneradorCout/coutGenerator.cpp

clean:
	del montyHall.exe *.o codiGenerat.cpp
