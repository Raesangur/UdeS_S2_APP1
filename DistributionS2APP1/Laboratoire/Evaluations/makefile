# creation makefile C.A. Brunet janvier 2014
#
# CE MAKEFILE A UN PROBLEME A CORRIGER POUR LE LABORATOIRE 1
#
test-evaluation: test-evaluation.o Evaluation.o EvaluationReussiEchec.o EvaluationChoixMultiples.o
	g++ -o test-evaluation test-evaluation.o Evaluation.o EvaluationReussiEchec.o EvaluationChoixMultiples.o

test-evaluation.o: test-evaluation.cpp EvaluationChoixMultiples.h
  g++ test-evaluation.cpp -g -c

EvaluationChoixMultiple.o: EvaluationChoixMultiple.cpp EvaluationChoixMultiple.h EvaluationReussiEchec.h Evaluation.h
  g++ EvaluationChoixMultiple.cpp -g -c

EvaluationReussiEchec.o: EvaluationReussiEchec.cpp EvaluationReussiEchec.h Evaluation.h
  g++ EvaluationReussiEchec.cpp -g -c

Evaluations.o: Evaluations.cpp Evaluations.h
  g++ Evaluations.cpp -g -c
#
clean:
	rm  -f *.o		
#
# fin du makefile
#
