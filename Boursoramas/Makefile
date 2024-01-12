GestionBanque.exe: main.cpp banque.o client.o CAT.o PEL.o livretA.o compteEpargne.o compteCourant.o compteBancaire.o date.o
	g++ main.cpp banque.o client.o CAT.o PEL.o livretA.o compteEpargne.o compteCourant.o compteBancaire.o date.o -o GestionBanque.exe

banque.o: banque.cpp banque.h client.o
	g++ -c banque.cpp

client.o: client.cpp client.h livretA.o CAT.o PEL.o compteCourant.o
	g++ -c client.cpp

CAT.o: CAT.cpp CAT.h compteEpargne.o
	g++ -c CAT.cpp

PEL.o: PEL.cpp PEL.h compteEpargne.o
	g++ -c PEL.cpp

livretA.o: livretA.cpp livretA.h compteEpargne.o
	g++ -c livretA.cpp

compteEpargne.o: compteEpargne.cpp compteEpargne.h compteBancaire.o
	g++ -c compteEpargne.cpp

compteCourant.o: compteCourant.cpp compteCourant.h compteBancaire.o
	g++ -c compteCourant.cpp

compteBancaire.o: compteBancaire.cpp compteBancaire.h date.o
	g++ -c compteBancaire.cpp

date.o: date.cpp date.h
	g++ -c date.cpp

Subprimes: 
	rm -f *.o
	