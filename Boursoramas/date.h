//fait par Elisa
#include <iostream>
using namespace std;
 
#ifndef DATE_H
#define DATE_H

class Date{
    private:
    int jour;
    int mois;
    int an; 
    protected:
    public:
    Date(int jour=14, int mois=10, int an=1996);
    Date(const Date &Acopier);
    ~Date();
    Date & operator=(const Date & D);
    bool operator<(const Date & D)const;
    bool operator==(const Date & D)const;
    int GetAnnee();
    void Afficher(ostream &out)const;
    void Saisir(istream &in);
};
    ostream & operator <<(ostream &out, const Date &D);
    istream & operator >>(istream &in, Date &D);

#endif
