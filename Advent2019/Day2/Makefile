CC = g++ -v -std=c++11
exe_file = run
$(exe_file): main.o readFile.o runProg.o
	$(CC) main.o readFile.o runProg.o -o $(exe_file)
main.o: main.cpp
	$(CC) -c main.cpp
readFile.o: readFile.cpp
	$(CC) -c readFile.cpp
runProg.o: runProg.cpp
	$(CC) -c runProg.cpp

clean:
	rm -f *.out *.o $(exe_file)