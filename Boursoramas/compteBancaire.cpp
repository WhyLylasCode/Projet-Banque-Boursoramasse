//forme canonique faite par Elisa
#include "compteBancaire.h"

CompteBancaire ::CompteBancaire(string numeroCompte, double soldeCompte, int j, int m, int a):dateOuverture(j,m,a){
    this->numeroCompte=numeroCompte;
    this->typeCompte=typeCompte;
    this->soldeCompte=soldeCompte;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Constructeur par défaut et paramètre de la classe compte bancaire"<<endl;
    #endif
}  

CompteBancaire::CompteBancaire(const CompteBancaire &Acopier):dateOuverture(Acopier.dateOuverture){
    this->numeroCompte=Acopier.numeroCompte;
    this -> typeCompte = Acopier.typeCompte;
    this->soldeCompte=Acopier.soldeCompte;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Copie du CompteBancaire"<<endl;
    #endif
}

CompteBancaire::~CompteBancaire(){
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Destructeur de la classe compte bancaire"<<endl;
    #endif
}

CompteBancaire & CompteBancaire::operator=(const CompteBancaire & C){
    this -> numeroCompte=C.numeroCompte;
    this -> typeCompte = C.typeCompte;
    this-> soldeCompte=C.soldeCompte;
    this->dateOuverture=C.dateOuverture;
    return *this;
}
bool CompteBancaire:: operator<(const CompteBancaire & C)const{
    return(soldeCompte<C.soldeCompte);
}
bool CompteBancaire:: operator==(const CompteBancaire & C)const{
    return(soldeCompte==C.soldeCompte);
}

void CompteBancaire:: AfficherCompte(ostream &out)const{
    out<<"Le compte n°"<<numeroCompte<<", de type ";
    if (typeCompte==1)
    out<<"courant";
    else
    out<<"épargne";
    out<<", a un solde de : "<<soldeCompte<<" et a été ouvert le : "<<dateOuverture<<endl;
}

void CompteBancaire::SaisirCompte(istream &in){
    cout<<"Veuillez entrer le numéro du compte :"<<endl;
    in>>numeroCompte;
    cout<<"Veuillez entrer le montant du premier dépôt obligatoire :"<<endl;
    in>>soldeCompte;
    cout<<"Date de création du compte :"<<endl;
    in>>dateOuverture;
}

int CompteBancaire::GetTypeCompte(){
    return typeCompte;
}


string CompteBancaire::GetNumeroCompte()const{
    return numeroCompte;
}

double CompteBancaire::GetSolde(){
    return soldeCompte;
}

void CompteBancaire :: MettreAJourSolde(double montant){
    // Implémenter la mise a jour du solde pour un compte
    soldeCompte += montant;
}


void CompteBancaire::HistoriqueDepots(double depot){
    TabHistoriqueDepot.push_back(depot);
}

void CompteBancaire::AfficherHistoriqueDepots(){
    cout<<"L'historique de dépôts de ce compte est :"<<endl;
    for(vector <double>::iterator it=TabHistoriqueDepot.begin(); it!=TabHistoriqueDepot.end(); it++){
        cout << *it << endl;
    }
}

ostream & operator <<(ostream &out, const CompteBancaire &C){
    C.AfficherCompte(out);
    return out;
}
istream & operator >>(istream &in, CompteBancaire &C){
    C.SaisirCompte(in);
    return in;
}
