CC = gcc -v -std=c++11
exe_file = run

$(exe_file): main.o password.o
	$(CC) main.o password.o -o $(exe_file)

main.o: main.cpp
	$(CC) -c main.cpp
passwords.o: password.cpp
	$(CC) -c password.cpp


clean:
	rm -f *.o $(exe_file)
