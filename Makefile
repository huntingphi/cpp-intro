
.PHONY: run

run: database
	./database

database: database.o
	g++ -o database database.o

database.o: database.cpp
	g++ -c database.cpp

clean:
	rm -f database database.o
