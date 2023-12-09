CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: cleardb clean main

clean:
	rm obj/*

cleardb:
	rm data/database.db

main: src/main.cpp src/User.cpp src/Course.cpp src/Lecture.cpp src/Student.cpp src/Teacher.cpp src/Admin.cpp src/Grade.cpp src/Database.cpp
	$(CC) $(FLAGS) src/main.cpp src/User.cpp src/Course.cpp src/Lecture.cpp src/Database.cpp src/Student.cpp src/Grade.cpp src/Admin.cpp src/Teacher.cpp -o obj/main -lsqlite3 
