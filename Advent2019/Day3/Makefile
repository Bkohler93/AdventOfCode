CC = g++
flags = -std=c++11 -g

exe_file = fix_wires
$(exe_file): main.o board.o

	$(CC) main.o board.o -o $(exe_file)

main.o: main.cpp
	$(CC) -c main.cpp

board.o: board.cpp
	$(CC) -c board.cpp


clean:
	rm -f *.out *.o $(exe_file)