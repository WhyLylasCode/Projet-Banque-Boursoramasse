#include <iostream>
using namespace std;

#include "compteEpargne.h"

#ifndef PEL_H
#define PEL_H
 
class PEL:public CompteEpargne{
    private: 
        int dureeBlocage;
        static int plafondDepot;
        static int depotMin;
        static double tauxInteret;
 
    protected:

    public:
        int verifDuree;
        
        PEL(int dureeBlocage=4, bool verifDuree=false, double soldeCompte=900, double tauxInteret=0.02, int plafondDepot=61200, int depotMin=540, string numeroCompte="4", int j=14, int m=10, int a=1996);
        PEL(const PEL &Acopier);
        ~PEL();
        PEL & operator=(const PEL & C);
        bool operator<(const PEL & C)const;
        bool operator==(const PEL & C)const;

        void AfficherCompte(ostream &out);
        void SaisirCompte(istream &in);
        void Deposer();
        void Retrait();
        int VerifierDuree();
        void AppliquerPenalites();
};

ostream & operator <<(ostream &out, PEL &C);
istream & operator >>(istream &in, PEL &C);

#endif
