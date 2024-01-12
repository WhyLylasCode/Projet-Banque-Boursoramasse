//Forme canonique faite par Guillaume 
#include <iostream>
#include <string>
#include "compteEpargne.h"
using namespace std;

CompteEpargne::CompteEpargne(double tauxInteret, int plafondDepot, int depotMin,string NC, double SC, int j,int m,int a):CompteBancaire(NC, SC, j,m,a)
{
    #ifdef DEBUG
    cout<<"Passage dans le contructeur par paramètre";
    #endif
    this->tauxInteret = tauxInteret;
    this->plafondDepot = plafondDepot; 
    this->depotMin = depotMin;
} 

CompteEpargne::CompteEpargne(const CompteEpargne & Acopier):CompteBancaire(Acopier)
{
    #ifdef DEBUG
    cout<<"Passage dans le constructeur par copie"<<endl;
    #endif
    this->tauxInteret = Acopier.tauxInteret;
    this->plafondDepot = Acopier.plafondDepot;
    this->depotMin = Acopier.depotMin;
}

void CompteEpargne::MettreAJourSolde(double montant){
    
    soldeCompte += montant;
    HistoriqueDepots(montant);
}

ostream & operator<<(ostream &out, const CompteEpargne &C)
{
    C.AfficherCompte(out);
    return out;
}

istream & operator>>(istream &in, CompteEpargne &C)
{   
    C.SaisirCompte(in);
    return in;
}

void CompteEpargne:: SetTypeCompte(){
    typeCompte=2;
}

void CompteEpargne::AfficherCompte(ostream&out)const
{
    CompteBancaire::AfficherCompte(out);
    out<<"Le taux d'intérêt est: "<<endl;
    out<<tauxInteret<<endl;
    out<<"Le compte est plafonné à: "<<endl;
    out<<plafondDepot<<endl;
    out<<"Le somme minimum pour ouvrir un compte est: "<<endl;
    out<<depotMin<<endl;
}


void CompteEpargne::AppliquerTaux(){
    soldeCompte+=soldeCompte*tauxInteret;
    cout<<"Vous avez été crédité de :"<<soldeCompte*tauxInteret<<endl;
}

CompteEpargne::~CompteEpargne()
{
#ifdef DEBUG
cout<<"Passage dans le destructeur du compte épargne"<<endl;
#endif
}