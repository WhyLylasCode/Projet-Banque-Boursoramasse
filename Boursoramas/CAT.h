//fait par Elisa
#include <iostream>
using namespace std;

#include "compteEpargne.h"

#ifndef CAT_H
#define CAT_H
 
class CAT:public CompteEpargne{
    private: 
        int dureeBlocage;
        static int plafondDepot;
        static int depotMin;
        static double tauxInteret;

    protected:

    public:
        bool verifDuree;
        
        CAT(int dureeBlocage=5, bool verifDuree=false, double soldeCompte=900, double tauxInteret=0.045, int plafondDepot=500000, int depotMin=5000, string numeroCompte="4", int j=14, int m=10, int a=1996);
        CAT(const CAT &Acopier);
        ~CAT();
        CAT & operator=(const CAT & C);
        bool operator<(const CAT & C)const;
        bool operator==(const CAT & C)const;

        void AfficherCompte(ostream &out);
        void SaisirCompte(istream &in);
        void Deposer();
        void Retrait();
        bool VerifierDuree();
        void AppliquerPenalites();
};

ostream & operator <<(ostream &out, CAT &C);
istream & operator >>(istream &in, CAT &C);

#endif
