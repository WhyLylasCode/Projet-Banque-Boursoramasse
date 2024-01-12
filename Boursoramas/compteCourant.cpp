#include "compteCourant.h"

 
CompteCourant::CompteCourant(string numeroCompte, double soldeCompte, int j, int m, int a,int dec,bool autoDecouvert,int plafondP,int plafondR): CompteBancaire(numeroCompte,soldeCompte,j,m,a)
{
    decouvert=dec;
    autorisationDecouvert=autoDecouvert;
    plafondPaiement=plafondP;
    plafondRetrait=plafondR;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Constructeur par défaut et paramètre du compte courant"<<endl;
    #endif 
} 

CompteCourant::CompteCourant( const CompteCourant&Acopier):CompteBancaire(Acopier)
{
    decouvert= Acopier.decouvert;
    autorisationDecouvert= Acopier.autorisationDecouvert;
    plafondPaiement=Acopier.plafondPaiement;
    plafondRetrait=Acopier.plafondRetrait;
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Constructeur par copie du compte courant"<<endl;
    #endif 
}
CompteCourant::~CompteCourant()
{
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Destructeur du compte courant"<<endl;
    #endif 
}
CompteCourant&CompteCourant::operator=(const CompteCourant &C)
{
    decouvert= C.decouvert;
    autorisationDecouvert= C.autorisationDecouvert;
    plafondPaiement=C.plafondPaiement;
    plafondRetrait=C.plafondRetrait;

    CompteBancaire *CB;
    const CompteBancaire *CB1;
    CB= this;
    CB1 = &C;
    *CB = *CB1;
    return *this;
}

bool CompteCourant:: operator<(const CompteCourant & C)const
{
    return(soldeCompte<C.soldeCompte);
}

bool CompteCourant:: operator==(const CompteCourant & C)const
{
    return(soldeCompte==C.soldeCompte);
}

void CompteCourant::SetTypeCompte(){
    typeCompte=1;
}

void CompteCourant::Agios()  // FONCTION QUI APPLIQUE LES AGIOS DIRECTEMENT AU SOLDE
{   
    if(soldeCompte<0 && -soldeCompte>decouvert)
    {
        double agios=(decouvert*0.18)/365;
        soldeCompte=soldeCompte-agios;
    }
    
}

void CompteCourant:: HistoriquePaiements(double paiement)
{
    TabHistoriquePaiement.push_back(paiement);
}

void CompteCourant::AfficherHistoriquePaiements(){
    cout<<"L'historique de paiements de ce compte est :"<<endl; 
    for(vector <double>::iterator it=TabHistoriquePaiement.begin(); it!=TabHistoriquePaiement.end(); it++){
        cout << *it << endl;
    }
}

void CompteCourant:: HistoriqueRetraits(double retrait)
{
    TabHistoriqueRetrait.push_back(retrait);
}

void CompteCourant::AfficherHistoriqueRetraits(){
    cout<<"L'historique de retraits de ce compte est :"<<endl; 
    for(vector <double>::iterator it=TabHistoriqueRetrait.begin(); it!=TabHistoriqueRetrait.end(); it++){
        cout << *it << endl;
    }
}

void CompteCourant::AfficherCompte(ostream &out)const
{
    double agios=(decouvert*0.18)/365;
    CompteBancaire::AfficherCompte(out);
    out << "Plafond de Paiement : " << plafondPaiement << endl;
    out << "Plafond de Retrait : "<< plafondRetrait << endl;
    if (autorisationDecouvert==true)
    {
        cout<<"Decouvert autorise!\nDecouvert Max: "<<decouvert << endl;
        cout<<"Nous vous prélèverons "<<agios<<"€ d'agios par jour de découvert !"<<endl;
    }
    else
        cout<<"Decouvert non autorise!"<<endl;
}

void CompteCourant::SaisirCompte(istream &in)
{   int verif;
    CompteBancaire::SaisirCompte(in);
    cout<<"Saisir le plafond de paiement"<<endl;
    in>>plafondPaiement;
    cout<<"Saisir le plafond de retrait"<<endl;
    in>>plafondRetrait;
    cout<<"Saisir 1 si droit au decouvert, 0 sinon"<<endl;
    cin>>verif;
    if (verif==1) {
        autorisationDecouvert=true;
        cout<<"Saisir le montant du découvert autorisé :"<<endl;
        cin>>decouvert;
    }
    else
        autorisationDecouvert=false;
}

void CompteCourant::Deposer()
{   
    int depot;
    cout<<"Saisir le montant à deposer sur le compte courant :"<<endl;
    cin>>depot;
    soldeCompte=soldeCompte+depot;
    HistoriqueDepots(depot);
}

void CompteCourant::Retrait()
{   
    int retrait;
    cout<<"Saisr le montant a retier ducompte courant:"<<endl;
    cin>>retrait;
    soldeCompte=soldeCompte-retrait;
    Agios();
    HistoriqueRetraits(retrait);
}

ostream & operator<<( ostream & out, const CompteCourant &C){
    C.AfficherCompte(out);
    return out;
}

istream & operator>>( istream & in, CompteCourant &C){
    C.SaisirCompte(in);
    return in;
}


