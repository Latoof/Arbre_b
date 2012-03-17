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


		a.ajouterElement( 97 );
	std::cout << "[[[[[[ After adding 97" << std::endl << a << std::endl;


	a.ajouterElement( 98 );
	std::cout << "[[[[[[ After adding 98" << std::endl << a << std::endl;

	a.ajouterElement( 45 );
	std::cout << "[[[[[[ After adding 45" << std::endl << a << std::endl;


	a.ajouterElement( 26 );
	std::cout << "[[[[[[ After adding 24" << std::endl << a << std::endl;



	a.ajouterElement( 33 );
	std::cout << "[[[[[[ After adding 33" << std::endl << a << std::endl;

	a.ajouterElement( 41 );
	std::cout << "[[[[[[ After adding 41" << std::endl << a << std::endl;


	a.ajouterElement( 43 );
	std::cout << "[[[[[[ After adding 43" << std::endl << a << std::endl;

	a.ajouterElement( 19 );
	std::cout << "[[[[[[ After adding 19" << std::endl << a << std::endl;


	a.ajouterElement( 32 );
	std::cout << "[[[[[[ After adding 32" << std::endl << a << std::endl;


	a.ajouterElement( 38 );
	std::cout << "[[[[[[ After adding 38" << std::endl << a << std::endl;

	a.ajouterElement( 58 );
	std::cout << "[[[[[[ After adding 58" << std::endl << a << std::endl;

	a.ajouterElement( 54 );
	std::cout << "[[[[[[ After adding 54" << std::endl << a << std::endl;

	a.ajouterElement( 66 );
	std::cout << "[[[[[[ After adding 66" << std::endl << a << std::endl;


	a.ajouterElement( 63 );
	std::cout << "[[[[[[ After adding 63" << std::endl << a << std::endl;


			a.supprimerElement( 45 );
	std::cout << "[[[[[[ After deleting 45" << std::endl << a << std::endl;



			a.supprimerElement( 8 );
	std::cout << "[[[[[[ After deleting 8" << std::endl << a << std::endl;


				a.supprimerElement( 58 );
	std::cout << "[[[[[[ After deleting 58" << std::endl << a << std::endl;



		a.supprimerElement( 12 );
	std::cout << "[[[[[[ After deleting 12" << std::endl << a << std::endl;


		a.ajouterElement( 17 );
	std::cout << "[[[[[[ After adding 17" << std::endl << a << std::endl;

	a.ajouterElement( 13 );
	std::cout << "[[[[[[ After adding 13" << std::endl << a << std::endl;


		a.ajouterElement( 18 );
	std::cout << "[[[[[[ After adding 18" << std::endl << a << std::endl;


	a.ajouterElement( 15 );
	std::cout << "[[[[[[ After adding 15" << std::endl << a << std::endl;


		a.ajouterElement( 14 );
	std::cout << "[[[[[[ After adding 14" << std::endl << a << std::endl;

	a.ajouterElement( 20 );
	std::cout << "[[[[[[ After adding 20" << std::endl << a << std::endl;


	a.supprimerElement( 33 );
		std::cout << "[[[[[[ After deleting 33" << std::endl << a << std::endl;

	a.supprimerElement( 26 );
		std::cout << "[[[[[[ After deleting 26" << std::endl << a << std::endl;


		a.ajouterElement( 25 );
	std::cout << "[[[[[[ After adding 25" << std::endl << a << std::endl;

	a.ajouterElement( 21 );
	std::cout << "[[[[[[ After adding 21" << std::endl << a << std::endl;

	a.ajouterElement( 50 );
	std::cout << "[[[[[[ After adding  50" << std::endl << a << std::endl;




	BArbre<int>::iterator iterArbre;
	iterArbre = a.begin();

	int elt = *iterArbre;
	std::cout << "\33[34m " << a._dbg << " Size : " << a.size() << "\33[0m" << std::endl;
	std::cout << "Elt : " << elt << "  " << *iterArbre << std::endl;




	return 0;

}