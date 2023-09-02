#include <iostream>
using namespace std;

int main()
{
	cout << "Donnez l'heure de début de la location (un entier) : ";
	int debut;
	cin >> debut;

	cout << "Donnez l'heure de fin de la location (un entier) : ";
	int fin;
	cin >> fin;

	/*****************************************************
	 * Compl�ter le code � partir d'ici
	 *****************************************************/

	int f1(0);
	if (debut < 0 || fin > 24 || debut > 24 || fin < 0)
	{
		cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
	}
	else
	{
		if (fin < debut)
		{
			cout << "Bizarre, le début de la location est après la fin ..." << endl;
		}
		else if (fin == debut)
		{
			cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
		}
		else if (debut >= 0 and fin <= 24)
		{
			cout << "Vous avez loué votre vélo pendant" << endl;

			if ((debut >= 0 and fin <= 7) || debut >= 17 and fin <= 24)
			{
				cout << fin - debut << " heure(s) au tarif horaire de 1 franc(s)" << endl;
				f1 += fin - debut;
			}
			else if (debut >= 7 and fin <= 17)
			{
				cout << fin - debut << " heure(s) au tarif horaire de 2 franc(s)" << endl;
				f1 += 2 * (fin - debut);
			}
			else
			{
				if ((debut >= 0 and debut <= 7) and (fin >= 7 and fin <= 17))
				{
					cout << 7 - debut << " heure(s) au tarif horaire de 1 franc(s)" << endl;
					f1 += 7 - debut;
					cout << fin - 7 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
					f1 += 2 * (fin - 7);
				}
				else if ((debut >= 7 and debut <= 17) and (fin >= 17 and fin <= 24))
				{
					cout << fin - 17 << " heure(s) au tarif horaire de 1 franc(s)" << endl;
					f1 += fin - 17;
					cout << 17 - debut << " heure(s) au tarif horaire de 2 franc(s)" << endl;
					f1 += 2 * (17 - debut);
				}
				else if ((debut >= 0 and debut <= 7) and (fin >= 17 and fin <= 24))
				{
					cout << (7 - debut) + (fin - 17) << " heure(s) au tarif horaire de 1 franc(s)" << endl;
					f1 += (7 - debut) + (fin - 17);
					cout << 10 << " heure(s) au tarif horaire de 2 franc(s)" << endl;
					f1 += 2 * (10);
				}
			}

			cout << "Le montant total à payer est de " << f1 << " franc(s)." << endl;
		}
	}

	/*******************************************
	 * Ne rien modifier apr�s cette ligne.
	 *******************************************/

	return 0;
}
