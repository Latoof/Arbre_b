#include "Noeud.h"
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

	return 0;

}