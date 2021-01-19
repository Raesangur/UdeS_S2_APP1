# Makefile pour l'APP

FLAGS=-std=c++17 -Wall -Wextra -Wshadow

# Génération de l'executable (nommé graphicus2.exe)
executable: canevas.o couche.o forme.o graphicus.o tests.o coordonnee.h carre.o rectangle.o cercle.o
	g++ -o graphicus2.exe canevas.o couche.o forme.o graphicus.o tests.o rectangle.o carre.o cercle.o


# Génération du fichier objet pour canevas
canevas.o: canevas.cpp canevas.h forme.h coordonnee.h couche.h vector.h
	g++ -c -g $(FLAGS) canevas.cpp

# Génération du fichier objet pour couche
couche.o: couche.cpp couche.h vector.h
	g++ -c -g $(FLAGS) couche.cpp

# Génération du fichier objet pour forme
forme.o: forme.cpp forme.h coordonnee.h
	g++ -c -g $(FLAGS) forme.cpp

# Génération du fichier objet pour graphicus
graphicus.o: graphicus.cpp tests.h canevas.h forme.h coordonnee.h couche.h
	g++ -c -g $(FLAGS) graphicus.cpp

# Génération du fichier objet pour tests
tests.o: tests.cpp tests.h canevas.h forme.h coordonnee.h couche.h carre.o cercle.o rectangle.o canevas.o couche.o
	g++ -c -g $(FLAGS) tests.cpp

# Génération du fichier objet pour les cercles
cercle.o: cercle.cpp cercle.h forme.h coordonnee.h
	g++ -c -g $(FLAGS) cercle.cpp

# Génération du fichier objet pour les rectangles
rectangle.o: rectangle.cpp rectangle.h forme.h coordonnee.h
	g++ -c -g $(FLAGS) rectangle.cpp

# Génération du fichier objet pour les carrés
carre.o: carre.cpp carre.h rectangle.o
	g++ -c -g $(FLAGS) carre.cpp

# Cleaning up
clean:
	rm -f *.o
