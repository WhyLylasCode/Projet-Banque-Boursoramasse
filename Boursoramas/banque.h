#include <iostream>
#include <string>
#include <vector> 
using namespace std;

#include "client.h" 
 
#ifndef BANQUE_H
#define BANQUE_H

class Banque {
    private :
        string nomBanque;
    public :
        vector <Client> TabClient;
        void AjouterClient();
        void AfficherBanque(ostream &out);
        void SaisirBanque(istream &in);
        int RechercherClient();
        void AfficherClients(ostream &out);

        // Forme Canonique
        ~Banque();
        Banque(string nom = "Banque");
        Banque(Banque & Acopier);
        Banque & operator =(Banque &B);
        bool operator<(const Banque &B)const;
        bool operator==(const Banque &B)const;
};

ostream & operator<<(ostream & out, Banque &B);
istream & operator>>(istream & in, Banque &B);

#endif