# Makefile pour l'APP

# Génération de l'executable (nommé graphicus2.exe)
executable: canevas.o couche.o forme.o graphicus.o tests.o coordonnee.h
	g++ -o graphicus2.exe canevas.o couche.o forme.o graphicus.o tests.o


# Génération du fichier objet pour canevas
canevas.o: canevas.cpp canevas.h forme.h coordonnee.h couche.h
	g++ -c -g -std=c++17 canevas.cpp

# Génération du fichier objet pour couche
couche.o: couche.cpp couche.h
	g++ -c -g -std=c++17 couche.cpp

# Génération du fichier objet pour forme
forme.o: forme.cpp forme.h coordonnee.h
	g++ -c -g -std=c++17 forme.cpp

# Génération du fichier objet pour graphicus
graphicus.o: graphicus.cpp tests.h canevas.h forme.h coordonnee.h couche.h
	g++ -c -g -std=c++17 graphicus.cpp

# Génération du fichier objet pour tests
tests.o: tests.cpp tests.h canevas.h forme.h coordonnee.h couche.h
	g++ -c -g -std=c++17 tests.cpp

# Cleaning up
clean:
	rm -f *.o
