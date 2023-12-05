CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall

all: src/Database.cpp
	$(CC) $(FLAGS) src/Database.cpp -o obj/dbcreate -lsqlite3

clean:
	rm obj/*

cleardb:
	rm data/database.db