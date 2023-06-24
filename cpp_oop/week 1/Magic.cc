#include <iostream>
#include <string>

using namespace std;


class Spectateur {

    private:
        int age;
        int argent;

    public:

        int demander_age(){

            int age(0);

            do{
                cout << "Quel age ai-je ?:  ";
                cin >> age;
            }while(age < 0);

            return age;

        }

        int demander_argent(){
            int argent(0);

            do{
                cout << "Combient d'argent ai-je  en poche ? (<100): ";
                cin >> argent;
            }while(argent > 100);

            return argent;

        }

};

class Papier{

    private:
        int age;
        int argent;
    public:
        int getAge() const {return age;}
        int getArgent() const {return argent;}

        Spectateur sp;


        void setAge(){this->age = sp.demander_age();}
        void setArgent(){this->argent = sp.demander_argent();}


};

class Assistant{

    private:
        int age;
        int argent;
    public:
    
        int magic_calcule(){

            Papier p;

            p.setAge();
            p.setAge();

            int somme = (p.getAge()*2 + 5)*50 * p.getArgent();

            return somme;





        }


};

class Magecien {

    private:
        int age;
        int argent;

    public:
        Assistant ass;
        int getSomme(){
            int somme = ass.magic_calcule() + 115;
            return somme;
        }
        void getResult(int somme){
            string resultat = std::to_string(somme);

            cout << "hum... je vois que vous êtes agé de " << resultat[0,2] << " ans " << " et que vous avez " << resultat[2,4] << " francs en poche !" << endl;
           

        }

      



};


int main(){

    Assistant ass;
    Magecien mag;
    Spectateur sp;



    cout << "[Spectateur] (J'entrer en scene) " << endl;
    sp.demander_age();
    sp.demander_argent();

    cout << "[Spectateur] (Je suis la) " << endl;
    cout << "[Magecian] (Un petit tour de magie) " << endl;
    cout << "[Spectateur] (j'écris le papier) " << endl; 
    cout << "[Spectateur] (je montre le papier) "  << endl;
    cout << "[Assistant] (je lis le papier) " << endl;

    int ass_somme = ass.magic_calcule();

    cout << "[Assistant] (je calcule mentalement) " << endl;
    cout << "[Assistant] J'annonce : "  << ass_somme << "!" << endl;

    int mag_somme = mag.getSomme();

    cout << "[Magecien]" << endl;
    mag.getResult(mag_somme);













    return 0;
}