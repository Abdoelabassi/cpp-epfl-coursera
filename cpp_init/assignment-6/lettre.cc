#include <iostream>
#include <string>


using namespace std;

void genereLettre(bool sex,string destinatiare, string sujet, int jour, int mois,string politesse ,string autheur)
{
if(sex){cout << "Bonjour cher " << destinatiare << "," << endl;}
else{cout << "Bonjour chère " << destinatiare << "," << endl;}
cout << "Je vous écris à propos de " << sujet << "." << endl;
cout << "Il faudrait que nous nous voyons le " << jour << "/" << mois << " pour en discuter." << endl;
cout << "Donnez-moi vite de vos nouvelles !" << endl;
cout << politesse << ", " << autheur  << "." <<endl;
}



int main()
{
    bool sex(true);
    string destination("Miles");
    string sujet("votre Spiderman franchise");
    int jour(2);
    int mois(6);
    string politesse("Amecalement");
    string autheur("Abderrazaq, Spiderman of universe 67858");

    genereLettre(sex, destination, sujet, jour, mois, politesse, autheur);






    return 0;
}