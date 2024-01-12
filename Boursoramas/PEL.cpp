#include "PEL.h"

int PEL::plafondDepot = 61200;
int PEL::depotMin = 540;
double PEL::tauxInteret = 0.02;


PEL::PEL(int dureeBlocage,bool verifDuree, double soldeCompte, double tauxInteret, int plafondDepot, int depotMin, string numeroCompte, int j, int m, int a) : CompteEpargne(tauxInteret, plafondDepot, depotMin, numeroCompte,soldeCompte, j, m, a){
    this->dureeBlocage=dureeBlocage;
    this->verifDuree=verifDuree;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Constructeur par défaut et paramètre de la classe PEL"<<endl;
    #endif 
}

PEL::PEL(const PEL &Acopier):CompteEpargne(Acopier){
    this->dureeBlocage=Acopier.dureeBlocage;
    this->verifDuree=Acopier.verifDuree;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Constructeur par copie de la classe PEL"<<endl;
    #endif
}
PEL::~PEL(){
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Destructeur de la classe PEL"<<endl;
    #endif
}
PEL & PEL:: operator=(const PEL & C){
    dureeBlocage=C.dureeBlocage;        
    verifDuree=C.verifDuree;
    CompteEpargne *C1;
    const CompteEpargne *C2;
    C1=this;
    C2=&C;
    *C1=*C2;
    return *this;
}
bool PEL:: operator<(const PEL & C)const{
    return(soldeCompte<C.soldeCompte);
}
bool PEL:: operator==(const PEL & C)const{
    return(soldeCompte==C.soldeCompte);
}

void PEL:: AfficherCompte(ostream &out){
    CompteEpargne::AfficherCompte(out);//appel fct dans Compte Epargne
    out<<"La durée pendant laquelle le compte est normalement bloqué est de : "<<dureeBlocage<<endl;
    verifDuree=VerifierDuree();
    if (verifDuree==true)
        out<<"Le compte n'est donc plus bloqué"<<endl;
    else if (verifDuree==false)
        out<<"Le compte est toujours bloqué"<<endl;
}


void PEL:: SaisirCompte(istream &in){ 
    CompteBancaire::SaisirCompte(in);
    cout<<"Veuillez entrer la durée pendant laquelle vous souhaitez bloquer ce compte (entre 4 et 10 ans) :"<<endl;
    do{
    in>>dureeBlocage;
    if (dureeBlocage<4|| dureeBlocage>10)
        cout<<"Veuillez entrer une durée entre 4 et 10 ans, s'il vous plaît !"<<endl;
    }
    while(dureeBlocage<4|| dureeBlocage>10);
}

void PEL ::Retrait(){
    cout<<"Retrait impossible dans un Plan d'Epargne Logement"<<endl;
}

void PEL:: Deposer(){
    double montantDepot;
    if (VerifierDuree()<=10){
        do{
        cout<<"Entrez le montant que vous voulez déposer dans le solde";
        cin>>montantDepot;
        }while(montantDepot<depotMin || montantDepot>plafondDepot);
        if (montantDepot>plafondDepot)
            cout<<"Opération Impossible! Vous avez dépassé le plafond de dépot";
        else if (montantDepot<depotMin)
            cout<<"Opération Impossible! Votre montant est inférieur au montant de dépôt minimum autorisé";
        else
            soldeCompte+=montantDepot;
        HistoriqueDepots(montantDepot);
    }
    else 
        cout<<"Vous avez dépassé la date limite de dépôt sur ce compte"<<endl;
}

int PEL:: VerifierDuree(){
    int an=dateOuverture.GetAnnee();
    return (2023 - an);
}

void PEL:: AppliquerPenalites(){
    if (verifDuree<2){
        soldeCompte-=54;
        cout<<"Vous allez avoir perdre 54 euros et perdre l'accès au prêt d'épargne logement"<<endl;
    }
    else if (verifDuree>=2 && verifDuree<3 ) 
        cout<<"Vous allez perdre l'accès au prêt d'épargne logement"<<endl;
    else if (verifDuree>=3 && verifDuree<=4 ) 
        cout<<"Vous allez avoir accès à un prêt d'épargne logement moins avantageux"<<endl;
    if (verifDuree>4) 
        cout<<"Pas de pénalité"; 
}

ostream & operator <<(ostream &out, PEL &C){
    C.AfficherCompte(out);
    return out;
}

istream & operator >>(istream &in, PEL &C){
    C.SaisirCompte(in);
    return in;
}
