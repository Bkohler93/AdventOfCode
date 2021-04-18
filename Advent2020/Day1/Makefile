CC = g++ -v -g -std=c++11
exe_file = run

$(exe_file): main.o funcs.o bst.o
	$(CC) main.o funcs.o bst.o -o $(exe_file)

main.o: main.cpp
	$(CC) -c main.cpp
funcs.o: funcs.cpp
	$(CC) -c funcs.cpp
bst.o: bst.cpp
	$(CC) -c bst.cpp


clean:
	rm -f .run *.o $(exe_file)