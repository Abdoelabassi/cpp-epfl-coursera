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

		// constructeur copie

		Peluche(Peluche const& p)
		: espace(p.espace), name(p.name + "-copie"), prix(p.prix)
		
		{
			std::cout << "[Une Peluche est ete copie]" << std::endl;
			std::cout << "La Peluche " << p.name << " a ete copiee en " << name << std::endl;

		}
		~Peluche()
		{
			std::cout << "La Peluche " << name <<  " test cassee " << std::endl;
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

	Peluche p("barbie", "rocket", 3.99), p2(p);


	std::cout << "Etiquette :" << std::endl;
	p.etiquette(p);
	p2.etiquette(p2);








	return 0;
}
