#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
	// Réduire le format d'affichage
	cout << setprecision(4);

	// Paramètres
	double taux_croissance_lapins(0.3);
	double taux_attaque(0.01);
	double taux_croissance_renards(0.008);
	double taux_mortalite(0.1);
	int duree(50);

	double renards_i(0.0);
	double lapins_i(0.0);

	/*****************************************************
	 * Compléter le code à partir d'ici
	 *****************************************************/

	 // ===== PARTIE 1 =====
	 // Saisie des populations initiales

	do {
		cout << "Combien de renards au départ (>= 2) ? ";
		cin >> renards_i;
	} while (renards_i < 2);

	do {
		cout << "Combien de lapins au départ  (>= 5) ? ";
		cin >> lapins_i;
	} while (lapins_i < 5);

	// ===== PARTIE 2 =====
	// Première simulation

	double nb_lapins = lapins_i, nb_renards = renards_i, r, l;

	cout << endl << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;

	if (nb_lapins != 0)
	{
		nb_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * renards_i);
	}
	if (nb_renards != 0)
	{
		nb_renards *= (1.0 + taux_attaque * lapins_i * taux_croissance_renards - taux_mortalite);
	}

	for (int i = 1; i <= duree; ++i)
	{
		if (nb_renards <= 0)
		{
			nb_renards = 0;
		}
		if (nb_lapins <= 0)
		{
			nb_lapins = 0;
		}

		cout << "Aprés " << i << " mois, il y a " << nb_lapins << " lapins et "
			<< nb_renards << " renards" << endl;

		l = nb_lapins;
		r = nb_renards;

		nb_renards *= (1.0 + taux_attaque * l * taux_croissance_renards - taux_mortalite);
		nb_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * r);
	}


	// ===== PARTIE 3 =====
	// Variation du taux d'attaque
	cout << endl;
	double taux1 = 0, taux2 = 0, j = 0;


	do {
		cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
		cin >> taux1;
	} while (taux1 < 0.5 or taux1 > 6);

	do {
		cout << "taux d'attaque à la fin  en % (entre " << taux1 << " et 6) ? ";
		cin >> taux2;
	} while (taux2 < taux1 or taux2 > 6);


	for (j = taux1; j <= taux2; j++)
	{
		nb_lapins = lapins_i;
		nb_renards = renards_i;

		int i = 1, flag1 = 0, flagexr = 0, flagexl = 0;

		cout << endl << "***** Le taux d'attaque vaut " << j << "%" << endl;

		nb_renards *= (1.0 + (j / 100) * lapins_i * taux_croissance_renards - taux_mortalite);
		nb_lapins *= (1.0 + taux_croissance_lapins - (j / 100) * renards_i);

		for (i = 1; i < duree; ++i)
		{

			l = nb_lapins;
			r = nb_renards;

			nb_renards *= (1.0 + (j / 100) * l * taux_croissance_renards - taux_mortalite);
			nb_lapins *= (1.0 + taux_croissance_lapins - (j / 100) * r);

			if (nb_lapins == 0 and nb_renards == 0)
			{
				break;
			}
			if ((l < 5 and nb_lapins > 5) or (r < 5 and nb_renards > 5))
			{
				flag1 = 1;
			}
			if (nb_lapins < 5)
			{
				flagexl = 1;
			}
			if (nb_renards < 5)
			{
				flagexr = 1;
			}
			if (nb_renards < 2)
			{
				nb_renards = 0;
			}
			if (nb_lapins < 2)
			{
				nb_lapins = 0;
			}
		}

		cout << "Aprés " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;

		if (flagexr == 1)
		{
			cout << "Les renards ont été en voie d'extinction" << endl;
		}
		if (nb_renards == 0)
		{
			cout << "et les renards ont disparu :-(" << endl;
		}
		if (flagexl == 1)
		{
			cout << "Les lapins ont été en voie d'extinction" << endl;
		}	
		if (nb_lapins == 0)
		{
			cout << "et les lapins ont disparu :-(" << endl;
		}
		if (flag1 == 1)
		{
			cout << "mais la population est remontée ! Ouf !" << endl;
		}
		if (flagexr == 0 and flagexl == 0 and flag1 == 0 and nb_lapins != 0 and nb_renards != 0)
		{
			cout << "Les lapins et les renards ont des populations stables." << endl;
		}
		if (nb_lapins == 0 and nb_renards == 0)
		{
			return 0;
		}
	}

	/*******************************************
	 * Ne rien modifier aprés cette ligne.
	 *******************************************/

	return 0;
}