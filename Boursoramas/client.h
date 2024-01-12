#include <vector>
#include <string>
using namespace std;

#include "compteCourant.h"
#include "livretA.h"
#include "PEL.h"
#include "CAT.h"
 


#ifndef CLIENT_H
#define CLIENT_H

class Client{
    private :
        string nomClient;
        string prenomClient;
    protected:
        string idClient;
        string adresse;
        

    public:
        vector <CompteCourant> TabCourant;
        vector <CompteEpargne> TabEpargne;
        void AfficherClient(ostream &out) const;
        void SaisirClient(istream &in);
        void ModifierClient();
        string GetIdClient() const;

        void OuvertureCompteEpargne();
        void OuvertureCompteCourant();
        void AfficherComptesEpargne() const;
        void AfficherComptesCourant() const;
        void DeposerCompteEpargne();
        void DeposerCompteCourant();
        void CloturerCompteEpargne();
        void CloturerCompteCourant();
        int RechercherCompteEpargne();
        int RechercherCompteCourant();
        
        // Forme canonique
        ~Client();
        Client(string nomClient = "Wiame", string prenomClient = "ElAlami", string idClient = "00000", string adresse = "2 rue maria mombiola");
        Client(const Client &C);
        Client & operator =(const Client &C);

        bool operator<(const Client &S)const;
        bool operator==(const Client &S)const;
};

ostream & operator<<( ostream & out, const Client &C);
istream & operator>>( istream & in, Client &C);

#endif