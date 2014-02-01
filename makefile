tda:	main.o integer.o slnode.o slinkedlist.o object.o tdalist.o 
	g++ main.o integer.o  object.o slnode.o slinkedlist.o tdalist.o -o tda

main.o:	main.cpp tdalist.h slinkedlist.h integer.h
	g++ -c main.cpp

integer.o:	integer.cpp integer.h object.h
	g++ -c integer.cpp

tdalist.o:	tdalist.h tdalist.cpp
	g++ -c tdalist.cpp

slnode.o:	slnode.cpp slnode.h
	g++ -c slnode.cpp

slinkedlist.o:	slinkedlist.cpp slinkedlist.h
	g++ -c slinkedlist.cpp

object.o:	object.h object.cpp
	g++ -c object.cpp
clean:
	rm *.o tda
