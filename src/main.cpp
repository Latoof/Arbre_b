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


	BArbre<int> a;
	a.ajouterElement( 9 );
	a.ajouterElement( 8 );
	a.ajouterElement( 9	); // Duplicate
	a.ajouterElement( 1	);
	a.ajouterElement( 4	);

	std::cout << "Before adding 4" << std::endl << a << std::endl;


	a.ajouterElement( 6	);
	std::cout << "After adding 6" << std::endl << a << std::endl;

	a.ajouterElement( 7 );
	std::cout << "After adding 7" << std::endl << a << std::endl;

	a.ajouterElement( 3 );
	std::cout << "After adding 3" << std::endl << a << std::endl;


	a.ajouterElement( 11 );
	std::cout << "After adding 11" << std::endl << a << std::endl;

	a.ajouterElement( 12 );
	std::cout << "After adding 12" << std::endl << a << std::endl;

	a.ajouterElement( 14 );
	std::cout << "After adding 14" << std::endl << a << std::endl;

		a.ajouterElement( 17 );
	std::cout << "After adding 17" << std::endl << a << std::endl;

		a.ajouterElement( 32 );
	std::cout << "After adding 32" << std::endl << a << std::endl;


			a.ajouterElement( 2 );
	std::cout << "After adding 2" << std::endl << a << std::endl;

			a.ajouterElement( 5 );
	std::cout << "After adding 5" << std::endl << a << std::endl;
	return 0;

}