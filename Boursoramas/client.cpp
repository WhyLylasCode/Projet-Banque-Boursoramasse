// Wiame
#include "client.h"
 
void Client::AfficherClient(ostream &out) const{
    out << "Le nom du client est : " << nomClient << endl;
    out << "Son prénom est : " << prenomClient << endl;
    out << "Son identifiant est : " << idClient << endl;
    out << "Son adresse postale est : " << adresse << endl;
}

void Client::SaisirClient(istream &in){
    cout << "Saisissez le nom du client : " << endl;
    in >> nomClient;
    cout << "Saisissez son prénom : " << endl;
    in >> prenomClient;
    cout << "Saisissez son identifiant : " << endl;
    in >> idClient;
    cout << "Saisissez son adresse postale : " << endl;
    cin.ignore(); // evite les problemes de getline apres cin
    getline(cin, adresse);
}

string Client::GetIdClient()const{
    return idClient;
}

void Client::OuvertureCompteCourant(){
    CompteCourant nouveauCompte;
    nouveauCompte.SetTypeCompte();
    cout << "Détails du compte courant : " << endl;
    cin >> nouveauCompte;
    // Ajout du nouveau compte à la liste des comptes du client
    TabCourant.push_back(nouveauCompte);
    cout << "Le compte courant a été ouvert avec succès." << endl;
}

void Client::OuvertureCompteEpargne(){
        int choixType;
        cout << "1- Pour ouvrir un LivretA \n2- Pour ouvrir un Plan Epargne Logement \n3- Pour ouvrir un Compte à Terme : ";
        cin >> choixType;
            if(choixType == 1){
                LivretA nouveauLivretA;
                nouveauLivretA.SetTypeCompte();
                cin >> nouveauLivretA;
                // Ajout du nouveau compte à la liste des comptes du client
                TabEpargne.push_back(nouveauLivretA);
                cout << "Le LivretA a été ouvert avec succès." << endl;
            }
            else if(choixType == 2){
                PEL nouveauPEL;
                nouveauPEL.SetTypeCompte();
                cin >> nouveauPEL;
                // Ajout du nouveau compte à la liste des comptes du client
                TabEpargne.push_back(nouveauPEL);
                cout << "Le PEL a été ouvert avec succès." << endl;
            }
            else if(choixType == 3){
                CAT nouveauCAT;
                cin >> nouveauCAT;
                nouveauCAT.SetTypeCompte();
                // Ajout du nouveau compte à la liste des comptes du client
                TabEpargne.push_back(nouveauCAT);
                cout << "Le CAT a été ouvert avec succès." << endl;
            }
        }

void Client::DeposerCompteCourant(){
    int depot;
    cout << "Saisir le montant à déposer : "<<endl;
    cin >> depot;
        int position;
        position = RechercherCompteCourant();
        if (position!=-1){
        // Mettre à jour le solde du compte courant
        TabCourant[position].MettreAJourSolde(depot);
        cout << "Dépôt effectué avec succès sur le compte courant." << endl;
        }
        else
        cout<<"Veuillez renouveler l'opération"<<endl;  
}

void Client::DeposerCompteEpargne(){
    int depot;
    cout << "Saisir le montant à déposer : ";
    cin >> depot;

    int choixType;
    int position;
        position = RechercherCompteEpargne();
        if (position!=-1){
        // Mettre à jour le solde du compte Epargne
        TabEpargne[position].MettreAJourSolde(depot);
        cout << "Dépôt effectué avec succès sur le compte courant." << endl;
        }
         else
        cout<<"Veuillez renouveler l'opération"<<endl;  
}
 
void Client::AfficherComptesCourant() const{
    if (TabEpargne.empty()) {
        cout << "Le client n'a aucun compte épargne." << endl;
    } else {
        cout << "Les comptes épargnes du client sont : " << endl;
        for (const CompteCourant &compte : TabCourant) {
            cout << compte;
        }
    }
}

void Client::AfficherComptesEpargne() const{
    if (TabCourant.empty()) {
        cout << "Le client n'a aucun compte courant." << endl;
    } else {
        cout << "Les comptes courant du client sont : " << endl;
        for (const CompteEpargne &compte : TabEpargne) {
            cout << compte;
        }
    }
} 

void Client::CloturerCompteEpargne(){
   cout << "Entrez l'identifiant du compte à fermer : ";
    string idCompte;
    cin >> idCompte;

        // Recherche du compte dans le tableau TabEpargne
        for (auto it = TabEpargne.begin(); it != TabEpargne.end(); ++it) {
            if ((*it).GetNumeroCompte() == idCompte) {
                // Supprimer le compte du tableau et libérer la mémoire
                TabEpargne.erase(it);

                cout << "Compte épargne " << idCompte << " fermé avec succès." << endl;
                return;
            } 
        cout << "Compte non trouvé. Opération annulée." << endl;
    }
}

void Client::CloturerCompteCourant(){
    cout << "Entrez l'identifiant du compte à fermer : ";
    string idCompte;
    cin >> idCompte;
    int trouve;

    // Recherche du compte dans le tableau TabCompte
    for (auto it = TabCourant.begin(); it != TabCourant.end(); ++it) {
        if ((*it).GetNumeroCompte() == idCompte) {
            // Supprimer le compte du tableau et libérer la mémoire
            TabCourant.erase(it);
            cout << "Compte courant n°" << idCompte << " fermé avec succès." << endl;
            return;
        } 
    }
    // Si le compte n'est pas trouvé
    cout << "Compte non trouvé. Opération annulée." << endl;
}

int Client::RechercherCompteEpargne(){
    string rechercheId;
    int trouver;
    cout << "Saisissez l'identifiant du compte épargne que vous voulez : ";
    cin >> rechercheId;

   for (int i=0; i<TabEpargne.size(); i++) {
        if (TabEpargne[i].GetNumeroCompte() == rechercheId) {
            cout << "Compte épargne trouvé : " << TabEpargne[i] << endl;
            trouver = 1;
            return i;
        } 
    } 
        if(trouver != 1){
            return -1;
            cout << "Compte non trouvé.";
    }
}

int Client::RechercherCompteCourant(){
    string rechercheId;
    int trouver;
    cout << "Saisissez l'identifiant du compte courant que vous voulez : ";
    cin >> rechercheId;

    for (int i=0; i<TabCourant.size(); i++) {
        if (TabCourant[i].GetNumeroCompte() == rechercheId) {
            cout << "Compte courant trouvé : " << TabCourant[i]<< endl;
            trouver = 1;
            return i;
        } 
    } 
        if(trouver != 1){
            return -1;
            cout << "Compte non trouvé.";
        }
    }


void Client::ModifierClient(){
    cout << "Entrez la nouvelle adresse postale : ";
    cin.ignore(); // evite les problemes de getline apres cin
    getchar();
    getline(cin, adresse);

    cout << "Adresse postale modifiée avec succès." << endl;
}


// Forme canonique

Client:: ~Client(){
    #ifdef DEBUG
    cout << "Destructeur de la classe client";
    #endif
}

Client::Client(string nomClient, string prenomClient, string idClient, string adresse)
{
    this -> nomClient = nomClient;
    this -> prenomClient = prenomClient;
    this -> idClient = idClient;
    this -> adresse = adresse;
}

Client::Client(const Client &C){
    this -> nomClient = C.nomClient;
    this -> prenomClient = C.prenomClient;
    this -> idClient = C.idClient;
    this -> adresse = C.adresse;
}

Client & Client::operator =(const Client &C){
    this -> nomClient = C.nomClient;
    this -> prenomClient = C.prenomClient;
    this -> idClient = C.idClient;
    this -> adresse = C.adresse;
    return *this;
}

bool Client::operator<(const Client &S)const{
    return (idClient < S.idClient);
}

bool Client::operator==(const Client &S)const{
    return (idClient == S.idClient);
}

ostream & operator<<( ostream & out, const Client &C){
    C.AfficherClient(out);
    return out;
}

istream & operator>>( istream & in, Client &C){
    C.SaisirClient(in);
    return in;
}