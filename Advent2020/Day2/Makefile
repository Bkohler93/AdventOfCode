CC = g++ -v -std=c++11
exe_file = run

$(exe_file): main.o gridproblem.o
	$(CC) main.o gridproblem.o -o $(exe_file)

main.o: main.cpp
	$(CC) -c main.cpp
gridproblem.o: gridproblem.cpp
	$(CC) -c gridproblem.cpp


clean:
	rm -f .run *.o $(exe_file)