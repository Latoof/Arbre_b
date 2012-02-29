#include "BArbre.h"

template<typename T>
BArbre<T>::BArbre() {
	
}


template<typename T>
BArbre<T>::~BArbre() {
	
}

template<typename T>
void BArbre<T>::ajouterElement( T element ) {
	
	typename
	std::vector<Noeud<T>*>::iterator iterNoeuds;

	Noeud<T>* noeud_courant = this->racine;

	for ( iterNoeuds = noeud_courant->begin() ; iterNoeuds != noeud_courant->end() ; ) {
		typename
		std::vector<T>::iterator iterElements;

		for ( iterElements = iterNoeuds->getElements().begin(); iterElements != iterNoeuds->getElements().end() ; ) {
			
			/// Je bloque la. Mais sur le princope, on parcours a la fois les pointeurs vers les fils et les elements contenus dans le Noeud courant
			if ( (*iterElements) > element ) { // Si l'element a inserer est plus petit, alors il sera situe dans le noeud pointe "a gauche"
				
				//iterNoeuds = noeud_courant.

			}

		}

	}

}

template<typename T>
int BArbre<T>::supprimerElement( T element ) {
	
	return 0;
}

template<typename T>
T BArbre<T>::chercherElement( T element ) {
	
	return element;
}