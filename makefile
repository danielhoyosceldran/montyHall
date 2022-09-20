montyHall: montyHall.o coutGenerator.o
	g++ -O2 -o montyHall montyHall.o coutGenerator.o

montyHall.o: montyHall.cpp ../GeneradorCout/coutGenerator.h
	g++ -O2 -c montyHall.cpp

coutGenerator.o: ../GeneradorCout/coutGenerator.cpp ../GeneradorCout/coutGenerator.h
	g++ -O2 -c ../GeneradorCout/coutGenerator.cpp

clean:
	del montyHall.exe *.o codiGenerat.cpp
