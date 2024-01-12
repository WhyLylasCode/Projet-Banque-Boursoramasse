#include <iostream>
#include <string>
#include "compteBancaire.h"
using namespace std;
 
#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H
 
class CompteCourant : public CompteBancaire
{
private:
    int decouvert;              // plafond decouvert 
    bool autorisationDecouvert;  // Si true, comparer le solde et le découvert 
                                 // Si false, print decouvert interdit.
    int plafondPaiement;    
    int plafondRetrait;
    vector <double> TabHistoriquePaiement;
    vector <double> TabHistoriqueRetrait;

public:
CompteCourant(string numeroCompte="999", double soldeCompte=900, int j=14, int m=10, int a=1996,int dec=1000,bool autoDecouvert=true,int plafondP=500,int plafondR=500);
CompteCourant(const CompteCourant&Acopier);
~CompteCourant();
CompteCourant&operator=(const CompteCourant &C);
bool operator<(const CompteCourant & C)const;
bool operator==(const CompteCourant & C)const;
void AfficherCompte(ostream&out)const;
void SaisirCompte(istream&in);
void SetTypeCompte();


//void PaiementInterne();
void HistoriquePaiements(double paiement);
void AfficherHistoriquePaiements();
void HistoriqueRetraits(double retrait);
void AfficherHistoriqueRetraits();
void Retrait();
void Deposer();
void Agios();
};

ostream & operator<<( ostream & out, const CompteCourant &C);
istream & operator>>( istream & in, CompteCourant &C);


#endif