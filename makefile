COMPILER=g++
FLAGS=-Wall -pedantic -O3

all:
	$(COMPILER) $(FLAGS) tests.cpp -o tests

clean:
	rm -rf tests