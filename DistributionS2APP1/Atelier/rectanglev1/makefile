# makefile No 1 du programme P13p4,
# compilation separee simple..
# Atelier APP No 3.  28 janvier 2015 
# But principal:
#   pr13p4 construire programme pr13p4
# But secondaires:
#  clean
#
pr13p4:  pr13p4.o  rectangle.o 
	g++ -o pr13p4 pr13p4.o rectangle.o
#
pr13p4.o: pr13p4.cpp rectangle.h
	g++ pr13p4.cpp -g -c
#
rectangle.o: rectangle.cpp rectangle.h
	g++ rectangle.cpp -g -c
#
clean:
	rm  -f *.o		
#
# fin du makefile
#
