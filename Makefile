# makefile

library : main.o resource.o member.o space.o library.o
	g++ -std=c++11 -o library main.o resource.o member.o space.o library.o
main.o : main.cpp
	g++ -std=c++11 -c main.cpp
library.o : library.cpp	
	g++ -std=c++11 -c library.cpp
resource.o : resource.cpp
	g++ -std=c++11 -c resource.cpp
member.o : member.cpp
	g++ -std=c++11 -c member.cpp
space.o : space.cpp
	g++ -std=c++11 -c space.cpp
clean :
	rm library main.o resource.o member.o space.o library.o
