#include <iostream>
#include <string>
#include "livretA.h"
using namespace std;

int LivretA::plafondDepot = 22950;
int LivretA::depotMin = 10;
double LivretA::tauxInteret = 0.03;

LivretA::LivretA(double tauxInteret, int plafondDepot, int DepotMin, string NC, double SC, int j, int m, int a):CompteEpargne(tauxInteret, plafondDepot,DepotMin,NC, SC, j,m,a)
{
    #ifdef DEBUG
    cout<<"Passage dans le contructeur par paramètre du livret A";
    #endif
}
 
LivretA::LivretA(const LivretA & Acopier):CompteEpargne(Acopier)
{
    #ifdef DEBUG
    cout<<"Passage dans le constructeur par copie du livret A"<<endl;
    #endif
}


LivretA&LivretA::operator=(const LivretA & L)
{
    CompteEpargne *LA;
    const CompteEpargne *LA1;
    LA= this; 
    LA1 = &L; 
    *LA = *LA1;
    return *this;
}

void LivretA::AfficherCompte(ostream &out)const
{
    CompteEpargne::AfficherCompte(out);
}

void LivretA::SaisirCompte(istream &in)
{
    CompteBancaire::SaisirCompte(in);
} 

void LivretA::Deposer()
{

double depot;
do{
cout<<"Saisir le montant a deposer sur le livret A:"<<endl;
cin>>depot;
}while(depot<depotMin || depot>plafondDepot);
if (depot>plafondDepot)
    cout<<"Opération Impossible! Vous avez dépassé le plafond de dêpot";
else if (depot<depotMin)
    cout<<"Opération Impossible! Votre montant est inférieur au montant de dêpot minimum autorisé";
else
    soldeCompte=soldeCompte+depot;
HistoriqueDepots(depot);
}

void LivretA:: Retrait(){
    double retrait;
    cout<<"Entrer la valeur à retirer"<<endl;
    cin>>retrait;
    soldeCompte-=retrait;
}

LivretA::~LivretA()
{
#ifdef DEBUG
cout<<"Passage dans le constructeur"<<endl;
#endif
}

ostream & operator<<(ostream &out, const LivretA &C){
    C.AfficherCompte(out);
    return out;
}

istream & operator>>(istream &in, LivretA &C){
    C.SaisirCompte(in);
    return in;
}

