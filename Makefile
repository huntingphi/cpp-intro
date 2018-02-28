
.PHONY: run

run: database
	./database

database: database.o
	g++ -o database database.o -std=c++11

database.o: database.cpp
	g++ -c database.cpp -std=c++11

clean:
	rm -f database database.o
