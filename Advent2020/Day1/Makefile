CC = g++ -v -g -std=c++11
exe_file = run

$(exe_file): main.o funcs.o
	$(CC) main.o funcs.o -o $(exe_file)

main.o: main.cpp
	$(CC) -c main.cpp
funcs.o: funcs.cpp
	$(CC) -c funcs.cpp


clean:
	rm -f .run *.o $(exe_file)