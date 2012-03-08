#include "Noeud.h"
#include "Racine.h"
#include "BArbre.h"

#include <iostream>

int main( int argc, char** argv ) {
	
	// Here
	Noeud<int> feuille;

	feuille.addElement( 9 );
	feuille.addElement( 7 );

	std::cout << feuille.getElement(0) << std::endl;


	Noeud<std::string> feuille2;

	feuille2.addElement( "premier" );
	feuille2.addElement( "second" );

	std::cout << feuille2.getElement(0) << std::endl;


	BArbre<int> a(1);


	std::cout << "Before adding 4" << std::endl << a << std::endl;


	a.ajouterElement( 6	);
	std::cout << "[[[[[[ After adding 6" << std::endl << a << std::endl;

	a.ajouterElement( 7 );
	std::cout << "[[[[[[ After adding 7" << std::endl << a << std::endl;

	a.ajouterElement( 3 );
	std::cout << "[[[[[[ After adding 3" << std::endl << a << std::endl;



	a.ajouterElement( 11 );
	std::cout << "[[[[[[ After adding 11" << std::endl << a << std::endl;

	a.ajouterElement( 12 );
	std::cout << "[[[[[[ After adding 12" << std::endl << a << std::endl;

									a.supprimerElement( 7 );
	std::cout << "[[[[[[ After deleting 7" << std::endl << a << std::endl;


		a.ajouterElement( 7 );
	std::cout << "[[[[[[ After adding 7" << std::endl << a << std::endl;


	a.ajouterElement( 8 );
	std::cout << "[[[[[[ After adding 8" << std::endl << a << std::endl;





	a.ajouterElement( 10 );
	std::cout << "[[[[[[ After adding 10" << std::endl << a << std::endl;

										a.supprimerElement( 11 );
	std::cout << "[[[[[[ After deleting 11" << std::endl << a << std::endl;

	a.supprimerElement( 8 );
	std::cout << "[[[[[[ After deleting 8" << std::endl << a << std::endl;


	a.supprimerElement( 6 );
	std::cout << "[[[[[[ After deleting 6" << std::endl << a << std::endl;

		a.supprimerElement( 10 );
	std::cout << "[[[[[[ After deleting 10" << std::endl << a << std::endl;
/*
	a.ajouterElement( 2 );
	std::cout << "[[[[[[ After adding 2" << std::endl << a << std::endl;

	a.ajouterElement( 4 );
	std::cout << "[[[[[[ After adding 4" << std::endl << a << std::endl;


		a.ajouterElement( 13 );
	std::cout << "[[[[[[ After adding 13" << std::endl << a << std::endl;

		a.ajouterElement( 14 );
	std::cout << "[[[[[[ After adding 14" << std::endl << a << std::endl;



		a.ajouterElement( 0 );
	std::cout << "[[[[[[ After adding 0" << std::endl << a << std::endl;

			a.ajouterElement( 1 );
	std::cout << "[[[[[[ After adding 1" << std::endl << a << std::endl;


		a.ajouterElement( 19 );
	std::cout << "[[[[[[ After adding 19" << std::endl << a << std::endl;


				a.ajouterElement( 20 );
	std::cout << "[[[[[[ After adding 20" << std::endl << a << std::endl;




					a.ajouterElement( 72 );
	std::cout << "[[[[[[ After adding 72" << std::endl << a << std::endl;

					a.ajouterElement( 99 );
	std::cout << "[[[[[[ After adding 99" << std::endl << a << std::endl;

	

						a.ajouterElement( 5 );
	std::cout << "[[[[[[ After adding  5" << std::endl << a << std::endl;
	

						a.ajouterElement( 97 );
	std::cout << "[[[[[[ After adding  97" << std::endl << a << std::endl;

							a.ajouterElement( 96 );
	std::cout << "[[[[[[ After adding  96" << std::endl << a << std::endl;

							a.ajouterElement( 95 );
	std::cout << "[[[[[[ After adding  95" << std::endl << a << std::endl;


						a.ajouterElement( 97 );
	std::cout << "[[[[[[ After adding  97" << std::endl << a << std::endl;

							a.ajouterElement( 96 );
	std::cout << "[[[[[[ After adding  96" << std::endl << a << std::endl;

							a.ajouterElement( 95 );
	std::cout << "[[[[[[ After adding  95" << std::endl << a << std::endl;

							a.ajouterElement( 94 );
	std::cout << "[[[[[[ After adding  94" << std::endl << a << std::endl;

							a.ajouterElement( 93 );
	std::cout << "[[[[[[ After adding  93" << std::endl << a << std::endl;

							a.ajouterElement( 92 );
	std::cout << "[[[[[[ After adding  92" << std::endl << a << std::endl;


							a.ajouterElement( 91 );
	std::cout << "[[[[[[ After adding  91" << std::endl << a << std::endl;

							a.ajouterElement( 90 );
	std::cout << "[[[[[[ After adding  90" << std::endl << a << std::endl;

							a.ajouterElement( 89 );
	std::cout << "[[[[[[ After adding  89" << std::endl << a << std::endl;


								a.supprimerElement( 19 );
	std::cout << "[[[[[[ After deleting 19" << std::endl << a << std::endl;

									a.supprimerElement( 14 );
	std::cout << "[[[[[[ After deleting 14" << std::endl << a << std::endl;

*/

	return 0;

}