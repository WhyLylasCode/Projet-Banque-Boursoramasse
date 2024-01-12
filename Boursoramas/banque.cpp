#include "banque.h"
 
void Banque::AjouterClient(){
    Client Clients;
    int nbClients;
    cout << "Saisissez le nombre de clients"<<endl;
    cin >> nbClients;
    for(int i = 0; i < nbClients; i++){
        cin >> Clients;
        TabClient.push_back(Clients);
    }
}

void Banque::AfficherClients(ostream &out){
    out << "Ses clients sont : " << endl;
    for(vector <Client>::iterator it=TabClient.begin(); it!=TabClient.end(); it++){
        out << *it << endl;
    }
}

void Banque::AfficherBanque(ostream &out){
    out << "Le nom de la banque est : " << nomBanque << endl;
    AfficherClients(out);
}

void Banque::SaisirBanque(istream &in){
    cout << "Saisissez le nom de la banque : ";
    in.ignore(); // evite les problemes de getline apres cin
    getline(in, nomBanque);
}

int Banque::RechercherClient(){
    string rechercheId;
    int trouver;
    cout << "Saisissez l'identifiant du client que vous recherchez : ";
    cin >> rechercheId;

    for (int i=0; i<TabClient.size(); i++) {
        if (TabClient[i].GetIdClient() == rechercheId) {
            cout << "Client trouvé : " << TabClient[i] << endl;
            trouver = 1;
            return i;
        } 
    } 
    if(trouver != 1){
    cout << "Client non trouvé.";
    return -1;
    }
} 

// Forme Canonique
Banque::~Banque(){
    #ifdef DEBUG
    cout << "Destructeur de la classe banque";
    #endif
}

Banque::Banque(string nom){
    this -> nomBanque = nom;
}

Banque::Banque(Banque & Acopier){
    this -> nomBanque = Acopier.nomBanque;
    // Supprimer les anciens clients pour éviter les fuites de mémoire
    TabClient.clear();
    for(vector <Client>::iterator it=Acopier.TabClient.begin(); it!=Acopier.TabClient.end(); it++){
        this -> TabClient.push_back(*it);
    } 
}

Banque & Banque::operator =(Banque &B){
    this -> nomBanque = B.nomBanque;

    // Supprimer les anciens clients pour éviter les fuites de mémoire
    TabClient.clear();

    // Copier les nouveaux clients
    for (vector<Client>::iterator it = B.TabClient.begin(); it != B.TabClient.end(); ++it) {
    TabClient.push_back(*it);
    }
    return *this;
}

bool Banque::operator<(const Banque &B)const{
    return (nomBanque < B.nomBanque);
}

bool Banque::operator==(const Banque &B)const{
    return (nomBanque == B.nomBanque);
    return (TabClient == B.TabClient);
}

ostream & operator<<(ostream & out, Banque &B){
    B.AfficherBanque(out);
    return out;
}

istream & operator>>(istream & in, Banque &B){
    B.SaisirBanque(in);
    return in;
}