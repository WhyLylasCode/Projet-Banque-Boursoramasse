//fait par Elisa
#include <iostream>
#include <vector>
using namespace std;

#include "date.h"
 
#ifndef COMPTEBANCAIRE_H 
#define COMPTEBANCAIRE_H

class CompteBancaire{
private:
    string numeroCompte;
protected:
    double soldeCompte;
    int typeCompte;
    Date dateOuverture;
    vector <double> TabHistoriqueDepot;

public:
    CompteBancaire(string numeroCompte="999", double soldeCompte=900, int j=14, int m=10, int a=1996);
    CompteBancaire(const CompteBancaire &Acopier);
    virtual ~CompteBancaire();
    CompteBancaire & operator=(const CompteBancaire & C);
    bool operator<(const CompteBancaire & C)const;
    bool operator==(const CompteBancaire & C)const;

    int GetTypeCompte();
    string GetNumeroCompte() const;
    virtual void AfficherCompte(ostream &out)const;
    virtual void SaisirCompte(istream &in);
    void HistoriqueDepots(double depot);
    void AfficherHistoriqueDepots();

    //virtual void PaiementInterne()=0;//souci avec ça
    virtual void Deposer() = 0;
    double GetSolde();
    void MettreAJourSolde(double montant);
};

ostream & operator <<(ostream &out, const CompteBancaire &C);
istream & operator >>(istream &in, CompteBancaire &C);

#endif
