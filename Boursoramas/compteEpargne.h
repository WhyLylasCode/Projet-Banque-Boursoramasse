#include <iostream>
#include <string>
using namespace std;

#include "compteBancaire.h"
 
#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

class CompteEpargne : public CompteBancaire
{protected:
    double tauxInteret;
    int plafondDepot;
    int depotMin;
 
public:
    CompteEpargne(double tauxInteret = 0, int plafondDepot = 0, int DepotMin = 0, string NC = "Epargne", double SC = 0, int j =1, int m = 1, int a = 1);// Constructeur par Paramètre
    CompteEpargne(const CompteEpargne & Acopier); // Constructeur par copie
    void AppliquerTaux();// Application du taux au compte
    virtual void AfficherCompte(ostream &out)const;
    virtual ~CompteEpargne(); // destructeur
    
    void SetTypeCompte();
    virtual void Deposer(){}
    virtual void Retrait(){}
    virtual void MettreAJourSolde(double montant);
};

    ostream & operator<<(ostream &out, const CompteEpargne &C);// Affichage
    istream & operator>>(istream &in, CompteEpargne &C);// Saisie

#endif

