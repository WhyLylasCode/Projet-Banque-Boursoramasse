#include <iostream>
#include <string>
#include  <vector> 

using namespace std;
 
#include "compteEpargne.h"

#ifndef LIVRETA_H
#define LIVRETA_H
 
 
class LivretA: public CompteEpargne
{
private:
    static int plafondDepot;
    static int depotMin;
    static double tauxInteret;

public: 
    LivretA(double tauxInteret = 0.03, int plafondDepot = 22950, int depotMin = 10, string NC = "Epargne", double SC = 10, int j =1, int m = 1, int a = 1); // Constructeur par parmamètre
    LivretA(const LivretA & Acopier); // Constructeur par copie
    LivretA&operator=(const LivretA & L);
    void Deposer(); 
    void Retrait(); 
    ~LivretA(); // destructeur
    void AfficherCompte(ostream &out)const;
    void SaisirCompte(istream &in);
};

    ostream & operator<<(ostream &out, const LivretA &C);// Affichage
    istream & operator>>(istream &in, LivretA &C);// Saisie

#endif






