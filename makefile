CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: db main run_dbcreate

db: src/Database.cpp
	$(CC) $(FLAGS) src/Database.cpp -o obj/dbcreate -lsqlite3

run_dbcreate: db
	./obj/dbcreate

clean:
	rm obj/*

cleardb:
	rm data/database.db

main: src/main.cpp src/User.cpp src/Course.cpp src/Lecture.cpp src/Student.cpp
	$(CC) $(FLAGS) src/main.cpp src/User.cpp src/Course.cpp src/Lecture.cpp src/Student.cpp -o obj/main -lsqlite3
