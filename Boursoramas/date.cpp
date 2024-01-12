//fait par Elisa
#include "date.h"

int Date::GetAnnee(){
    return an;
}
 
 
Date ::Date (int jour, int mois, int an){
   this->jour=jour;
   this->mois=mois;
   this->an=an;
}
Date::Date(const Date &Acopier){
    jour=Acopier.jour;
    mois=Acopier.mois;
    an=Acopier.an;
} 
Date::~Date(){
    #ifdef DEBUG // utiliser avec g++ -D DEBUG pour l'afficher
    cout<<"Destructeur de la classe date"<<endl;
    #endif
}
Date & Date:: operator=(const Date & D){
    jour=D.jour;
    mois=D.mois;
    an=D.an;
    return *this;
}

bool Date:: operator<(const Date & D)const{
    return(an<D.an);
}
bool Date:: operator==(const Date & D)const{
    return((jour==D.jour)&&(mois==D.mois)&&(an==D.an));
}

void Date:: Afficher(ostream &out)const{
    out<<jour<<"/"<<mois<<"/"<<an;
  //les chevrons sont utilisés comme opérateur de la date
}

void Date:: Saisir(istream &in){
    cout<<"Saisissez le jour, le mois et l'année (au format JJ MM AAAA): "<<endl;
    in>>jour>>mois>>an;
}

ostream & operator <<(ostream &out, const Date &D){
    D.Afficher(out);
    return out;
}
istream & operator >>(istream &in, Date &D){
    D.Saisir(in);
    return in;
}
