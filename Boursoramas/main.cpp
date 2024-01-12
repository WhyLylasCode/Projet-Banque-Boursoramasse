#include "banque.h"


int main(){
    int choix, choix2, choix3;
    Banque Boursoramasse;
    cout<<"*****************************************BIENVENUE*****************************************"<<endl;
    cin>>Boursoramasse;
    Boursoramasse.AjouterClient();
    cout<<Boursoramasse;
    do{
    cout<<"***************************************MENU****************************************"<<endl;
    cout<<"****** Tapez 1 ******* Afficher banque"<<endl;
    cout<<"****** Tapez 2 ******* Ajouter clients"<<endl;
    cout<<"****** Tapez 3 ******* Modifier client"<<endl;
    cout<<"****** Tapez 4 ******* Ouvrir un compte courant"<<endl;
    cout<<"****** Tapez 0 ******* Quitter"<<endl;

    cin >> choix;

    int positionClient;

    switch (choix)
    {
    case 1:
        cout << Boursoramasse;
        break;
    case 2:
        Boursoramasse.AjouterClient();
        break;
    case 3:
        positionClient=Boursoramasse.RechercherClient();
        if(positionClient!=-1)
        Boursoramasse.TabClient[positionClient].ModifierClient();
        break;
        if(positionClient=-1){
        cout<<"Le client n'existe pas"<<endl;
        break;}
    case 4:
        positionClient=Boursoramasse.RechercherClient();
        if(positionClient!=-1){
        Boursoramasse.TabClient[positionClient].OuvertureCompteCourant();
        do{
        cout<<"***********************************MENU COMPTE COURANT***********************************"<<endl;
        cout<<"****** Tapez 1 ******* Déposer dans le compte"<<endl;//aucun accès au tableau pointeur ou tant pis
        cout<<"****** Tapez 2 ******* Retirer dans le compte"<<endl;//de même 
        cout<<"****** Tapez 3 ******* Afficher les données du compte"<<endl;
        cout<<"****** Tapez 4 ******* Clôturer le compte"<<endl;
        cout<<"****** Tapez 5 ******* Ouvrir un autre compte"<<endl;
        cout<<"****** Tapez 0 ******* Retour au menu précédent"<<endl;
        cin>>choix2;
        switch (choix2)
        {
        case 1:
            Boursoramasse.TabClient[positionClient].TabCourant.back().Deposer();
            break;
        case 2:
            Boursoramasse.TabClient[positionClient].TabCourant.back().Retrait();
            break;
        case 3:
            cout<<Boursoramasse.TabClient[positionClient].TabCourant.back();
            Boursoramasse.TabClient[positionClient].TabCourant.back().AfficherHistoriqueDepots();
            Boursoramasse.TabClient[positionClient].TabCourant.back().AfficherHistoriqueRetraits();
            break;
        case 4:
            Boursoramasse.TabClient[positionClient].CloturerCompteCourant();
            break;
        case 5:
            cout<<"***** Tapez 1 ***** Pour ouvrir un autre compte courant \n***** Tapez 2 ***** Pour créer un compte épargne"<<endl;
            cin>>choix;
            if(choix==1){
                Boursoramasse.TabClient[positionClient].OuvertureCompteCourant();
                break;
            }
            else{
                Boursoramasse.TabClient[positionClient].OuvertureCompteEpargne();
                do{
                cout<<"***********************************MENU COMPTE EPARGNE*******************************"<<endl;
                cout<<"****** Tapez 1 ******* Afficher les données du compte épargne ouvert"<<endl;
                cout<<"****** Tapez 2 ******* Clôturer le compte épargne ouvert"<<endl;
                cout<<"****** Tapez 3 ******* Déposer de l'argent sur le compte épargne ouvert"<<endl;
                cout<<"****** Tapez 4 ******* Appliquer les taux d'intérêt"<<endl;
                cout<<"****** Tapez 0 ******* Retour au menu précédent"<<endl;
                cin>>choix3;
                switch (choix3)
                {
                case 1:
                    cout<<Boursoramasse.TabClient[positionClient].TabEpargne.back();
                    Boursoramasse.TabClient[positionClient].TabEpargne.back().AfficherHistoriqueDepots();
                    break;
                case 2:
                    Boursoramasse.TabClient[positionClient].CloturerCompteEpargne();
                    break;
                case 3:
                    cout<<"Entrer le montant que vous voulez déposer :"<<endl;
                    double montant;
                    cin>>montant;
                    Boursoramasse.TabClient[positionClient].TabEpargne.back().MettreAJourSolde(montant);
                    break;
                case 4:
                    Boursoramasse.TabClient[positionClient].TabEpargne.back().AppliquerTaux();
                    break;
                }
                if (choix3!=0 && choix3!=1 && choix3!=2 && choix3!=3 && choix3!=4)
                cout<<"Option non valide, veuillez entrer un des choix proposé"<<endl;
                }while(choix3!=0);
                break;
            }
            break;
        }
        if (choix2!=0 && choix2!=1 && choix2!=2 && choix2!=3 && choix2!=4 && choix2!=5)
        cout<<"Option non valide, veuillez entrer un des choix proposé"<<endl;
        }while(choix2!=0);
        break;
        }
        if(positionClient=-1){
        cout<<"Le client n'existe pas"<<endl;
        break;}
    }
    if(choix!=0 && choix!=1 && choix!=2 && choix!=3 && choix!=4)
    cout<<"Option non valide, veuillez entrer un des choix proposé"<<endl;
    }while(choix!=0);
cout<<"Aurevoir"<<endl;
cout<<"<3"<<endl;
}