#include "Noeud.h"
#include "BArbre.h"

//#include "BArbre_generic_iterator.h"
#include "BArbre_iterator.h"
#include "BArbre_reverse_iterator.h"


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


	BArbre<int> a(2);


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

	std::cout << "Iterator initialized\n";

	int elt = *iterArbre;

	std::cout << "Dbg noob\n";
	std::cout << "\33[34m " << a._dbg << " Size : " << a.size() << "\33[0m" << std::endl;
	std::cout << "Elt : " << elt << "  " << *iterArbre << std::endl;

	
	for (int i=0; i<22; i++) {
		iterArbre++;
		std::cout << "--> ELT : " << *iterArbre << std::endl;

	}

	for (int i=0; i<22; i++) {
		iterArbre--;
		std::cout << "--> ELT : " << *iterArbre << std::endl;

	}

	std::cout << "REVERSE\n";

	BArbre<int>::reverse_iterator riterArbre;
	riterArbre = a.rbegin();

	for (int i=0; i<22; i++) {
		riterArbre++;
		std::cout << "--> ELT : " << *riterArbre << std::endl;

	}

	std::cout << "------ EEND\n";
	BArbre<int>::iterator it;
	BArbre<int>::iterator itEnd = a.end();

/** **/
	for ( it = a.begin(); it != itEnd; it++) {
		std::cout << "Will print element " << std::endl;
		std::cout << "--> ELT : " << *it << std::endl;

	}


	/** **/

		BArbre<int>::reverse_iterator itR;
	BArbre<int>::reverse_iterator itREnd = a.rend();

/** **/
	for ( itR = a.rbegin(); itR != a.rend(); itR++) {
		std::cout << "Will print R element " << std::endl;
		std::cout << "--> ELT : " << *itR << std::endl;

	}


	/** **/

	return 0;

}
