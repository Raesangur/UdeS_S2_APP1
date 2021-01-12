# bon matin

executable: pr13p4.o rectangle.o
	g++ -o executable pr13p4.o rectangle.o

pr13p4.o: pr13p4.cpp rectangle.h
	g++ -g -c -std=c++17 pr13p4.cpp

rectangle.o: rectangle.cpp rectangle.h
	g++ -g -c -std=c++17 rectangle.cpp

clear:
	rm -f *.o
