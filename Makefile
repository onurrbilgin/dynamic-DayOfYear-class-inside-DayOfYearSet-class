target:	hw4

hw4:	dayofyearset.o main.o
		g++ --std=c++11 dayofyearset.o main.o -o hw4

dayofyearset.o:	dayofyearset.cpp
		g++ --std=c++11 -c dayofyearset.cpp

main.o:	main.cpp
		g++ --std=c++11 -c main.cpp

clean:
		rm dayofyearset.o main.o hw4