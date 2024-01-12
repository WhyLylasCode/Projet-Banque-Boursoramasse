//forme canonique faite par Elisa
#include "CAT.h"
 
int CAT::plafondDepot = 500000;
int CAT::depotMin = 5000;
double CAT::tauxInteret = 0.045;


CAT::CAT(int dureeBlocage,bool verifDuree, double soldeCompte, double tauxInteret, int plafondDepot, int depotMin, string numeroCompte, int j, int m, int a) : CompteEpargne(tauxInteret, plafondDepot, depotMin, numeroCompte,soldeCompte, j, m, a){
    this->dureeBlocage=dureeBlocage;
    this->verifDuree=verifDuree;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Constructeur par défaut et paramètre de la classe CAT"<<endl;
    #endif 
}

CAT::CAT(const CAT &Acopier):CompteEpargne(Acopier){
    this->dureeBlocage=Acopier.dureeBlocage;
    this->verifDuree=Acopier.verifDuree;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Constructeur par copie de la classe CAT"<<endl;
    #endif
}
CAT::~CAT(){
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Destructeur de la classe CAT"<<endl;
    #endif
}
CAT & CAT:: operator=(const CAT & C){
    dureeBlocage=C.dureeBlocage;
    verifDuree=C.verifDuree;
    CompteEpargne *C1;
    const CompteEpargne *C2;
    C1=this;
    C2=&C;
    *C1=*C2;
    return *this;
}
bool CAT:: operator<(const CAT & C)const{
    return(soldeCompte<C.soldeCompte);
}
bool CAT:: operator==(const CAT & C)const{
    return(soldeCompte==C.soldeCompte);
}

void CAT:: AfficherCompte(ostream &out){
    CompteEpargne::AfficherCompte(out);//appel fct dans Compte Epargne
    out<<"La durée pendant laquelle le compte est normalement bloqué est de : "<<dureeBlocage<<endl;
    verifDuree=VerifierDuree();
    if (verifDuree==true)
        out<<"Le compte n'est donc plus bloquée"<<endl;
    else if (verifDuree==false)
        out<<"Le compte est toujours bloqué"<<endl;
}

void CAT:: SaisirCompte(istream &in){
    CompteBancaire::SaisirCompte(in);
    cout<<"Veuillez entrer la durée pendant laquelle vous souhaiter bloquer ce compte (entre 1 et 5 ans) :"<<endl;
    do{
    in>>dureeBlocage;
    if (dureeBlocage<1|| dureeBlocage>5)
        cout<<"Veuillez entrer une durée entre 1 et 5 ans, s'il vous plaît !"<<endl;
    }
    while(dureeBlocage<1|| dureeBlocage>5);
}

void CAT:: Deposer(){
    double montantDepot;
    if (VerifierDuree()==true){
        cout<<"Entrez le montant que vous voulez déposer dans le solde";
        cin>>montantDepot;
        if (montantDepot>plafondDepot)
            cout<<"Opération Impossible! Vous avez dépassé le plafond de dépot";
        else if (montantDepot<depotMin)
            cout<<"Opération Impossible! Votre montant est inférieur au montant de dépôt minimum autorisé";
        else
            soldeCompte+=montantDepot;
        HistoriqueDepots(montantDepot);
    }
}

void CAT ::Retrait(){
    cout<<"Retrait impossible dans un Compte à terme"<<endl;
}

bool CAT:: VerifierDuree(){
    int an=dateOuverture.GetAnnee();
    return (dureeBlocage <= 2023 - an );
}

void CAT:: AppliquerPenalites(){
    if (verifDuree==true)
        soldeCompte-=500;
    else 
        cout<<"Pas de pénalité";    
}

ostream & operator <<(ostream &out, CAT &C){
    C.AfficherCompte(out);
    return out;
}

istream & operator >>(istream &in, CAT &C){
    C.SaisirCompte(in);
    return in;
}
