
.PHONY: driver


driver: driver.o
	g++ -o driver driver.o database.o -std=c++11

driver.o: driver.cpp
	g++ -c driver.cpp -std=c++11

driver.cpp: database.o
	g++ -c database.cpp -std=c++11

clean:
	rm -f database database.o driver driver.o

run: driver
		./driver
