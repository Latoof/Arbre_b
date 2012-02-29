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
	

	Noeud<T>* noeud_courant = this->racine;

	while ( !noeud_courant->isFeuille() ) {

		/* Will contain all elements of each node */
		typename
		std::vector<T>::iterator iterElements;

		/* Will contain all subNodes of current node */
		typename
		std::vector<Noeud<T>*>::iterator iterFils = noeud_courant->getFils()->begin();

		/* All elements */
		for ( iterElements = noeud_courant->getElements().begin(); iterElements != noeud_courant->getElements().end() ; iterElements++ ) {

			if ( (*iterElements) == element ) {
				// Trouve
				return (*iterElements);
			}
			/// Je bloque la. Mais sur le princope, on parcours a la fois les pointeurs vers les fils et les elements contenus dans le Noeud courant
			else if ( (*iterElements) < element ) { // Si l'element a inserer est plus petit, alors il sera situe dans le noeud pointe "a gauche"
				// On descend dans le Noeud a gauche de l'element en cours.
				noeud_courant = (*iterFils);

			}
			else if ( iterElements == noeud_courant->getElements()->end() ) {
				// On descend dans le noeud tout a droite.
				noeud_courant = iterFils->end();

			}
			else {
				iterFils++;
			}
			
		}

	}

	return element;
}