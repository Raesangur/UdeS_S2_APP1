# makefile du projet TableauEntier
# creation: C.A. Brunet Janvier 2014
# Cible principale: construire le programme TableauEntier
# Cible secondaire: nettoyage
#
test-TableauEntier:  test-TableauEntier.o TableauEntier.o
	g++ -o test-TableauEntier test-TableauEntier.o TableauEntier.o

test-TableauEntier.o: test-TableauEntier.cpp TableauEntier.h
	g++ test-TableauEntier.cpp -g -c
#
#
TableauEntier.o: TableauEntier.cpp TableauEntier.h
	g++ TableauEntier.cpp -g -c
#
clean:
	rm  -f *.o		
#
# fin du makefile
#
