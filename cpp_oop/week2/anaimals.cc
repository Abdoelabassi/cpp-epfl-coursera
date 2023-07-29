#include <iostream>

class Peluche {


	private:
		std::string espace;
		std::string name;
		double prix;



	public:
		Peluche(std::string spacy, std::string name, double price)
			: espace(spacy), name(name), prix(price) {
				std::cout << "[un Peluche est fabriquee]" << std::endl;
			}


		std::string getName()const{return name;}
		std::string getEspece()const{return espace;}
		double getPrix()const{return prix; }

		void setPrix(double valeur){prix=valeur;}

		void etiquette(Peluche p){

			std::cout << "Hello, mon nom est " << p.getName() << std::endl
				  << "Je suis un " << p.getEspece() << " et je coute " << p.getPrix() << " francs. " << std::endl;
		}


};


int main(){

	Peluche p("barbie", "rocket", 3.99);

	std::cout << "Etiquette :" << std::endl;
	p.etiquette(p);








	return 0;
}
