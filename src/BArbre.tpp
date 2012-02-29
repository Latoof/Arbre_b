#include "BArbre.h"

template<typename T>
BArbre<T>::BArbre( int lower, int upper ) : _lower(lower) {
	
	if ( upper == -1 ) {
		_upper = 2 * _lower;
	}

	_racine = new Racine<T>( );
	_noeuds.push_back(_racine);

						std::cout << "Racine : " << *_racine << std::endl;


}


template<typename T>
BArbre<T>::~BArbre() {
	
}

template<typename T>
void BArbre<T>::ajouterElement( const T& element ) {

	std::cout << "We want to add " << element << std::endl;
	
	Noeud<T>* node = this->chercherElementN( element );
	std::cout << "Search returned" << std::endl;

	if ( node != NULL && !node->contains(element) ) {
		
		this->addToNode( node, element );

	}
	else {
		std::cout << "Dbg : Elt already present : " << element << std::endl;
		
	}

}

template<typename T>
void BArbre<T>::addToNode( Noeud<T>* node, const T& element ) {

	std::cout << "Adding/moving " << element << std::endl;
	
	if ( node->getElements().size() < _upper ) {
			node->addElement( element );
			std::cout << "Add Successfull" << std::endl;
	}
	else {
		
		std::cout << "Node full. Expanding !" << std::endl;
		/* HARD */

		Noeud<T>* parent_node = node->getParent();
		/* If node has no parent, that's root */
		/* So let's create a new root in order to replace this one */
		if ( parent_node == NULL ) {
			std::cout << "Rebuilding root ..." << std::endl;
			_racine = new Racine<T>();
			parent_node = _racine;
			_noeuds.push_back(parent_node);

		}
		else {
			std::cout << "_____ Pas la racine !" << std::endl;
			parent_node->delFils(node);
		}

		Noeud<T>* n_left_node = new Noeud<T>( parent_node );
		Noeud<T>* n_right_node = new Noeud<T>( parent_node );

		parent_node->addFils(n_left_node);
		parent_node->addFils(n_right_node);


		std::vector<T> elts = node->getElements();

		typename
		std::vector<T>::iterator iterElements;

		int middle = ( elts.size() / 2 );

		int i=0;
		bool n_element_inserted = false;
		for ( iterElements = elts.begin(); iterElements != elts.end() ; iterElements++ ) {
			
			std::cout << "[Add] Element count : " << i << std::endl;
			Noeud<T>* target_node;

			if ( i < middle ) {
				target_node = n_left_node;
			}
			else if ( i == middle ) {
				target_node = parent_node;
			}
			else { // i > middle
				target_node = n_right_node;
			}

			if ( element < (*iterElements) && !n_element_inserted ) {

				addToNode( target_node, element );
				n_element_inserted = true;

				if ( iterElements != elts.begin() ) {
					iterElements--;
				}

			}
			else {

				std::cout << "Pushing " << (*iterElements) << std::endl;
				addToNode( target_node, (*iterElements) );

			}
			i++;


		}

		if ( !n_element_inserted ) {
			addToNode( n_right_node, element );
		}

		/* //HARD */

		// TODO find a solution : Use a Set ?
		//_noeuds.remove(node);
		typename
		std::vector< Noeud<T>* >::iterator iterFindNode;
		for ( iterFindNode = _noeuds.begin(); iterFindNode != _noeuds.end() ; iterFindNode++) {
			
			if ( (*iterFindNode) == node ) {
				_noeuds.erase( iterFindNode );
				break;
			}

		}

		_noeuds.push_back(n_left_node);
		_noeuds.push_back(n_right_node);

							std::cout << "NEW Racine : " << *_racine << std::endl;


	}


}


template<typename T>
int BArbre<T>::supprimerElement( T element ) {
	
	return 0;
}

template<typename T>
T BArbre<T>::chercherElement( const T& element ) {
	

	Noeud<T>* noeud_courant = _racine;

	while ( !noeud_courant->isFeuille() ) {

		/* Will contain all elements of each node */
		typename
		std::vector<T>::iterator iterElements;

		/* Will contain all subNodes of current node */
		typename
		std::vector<Noeud<T>*>::iterator iterFils = noeud_courant->getFils().begin();

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

template<typename T>
Noeud<T>* BArbre<T>::chercherElementN( const T& element ) {
	
	std::cout << "Starts here" << std::endl;

	Noeud<T>* noeud_courant;
	
	noeud_courant = dynamic_cast<Noeud<T>*>(_racine);
	/* Will contain all subNodes of current node */


	while ( !noeud_courant->isFeuille() ) {

		std::cout << "Loop" << std::endl;

		/* Will contain all elements of each node */


		typename
		std::vector<T> elements_noeud_courant = noeud_courant->getElements();

		typename
		std::vector<T>::iterator iterElements;


		typename
		std::vector<Noeud<T>*> fils_noeud_courant = noeud_courant->getFils();

		typename
		std::vector<Noeud<T>*>::iterator iterFils;
		
		iterFils = fils_noeud_courant.begin();


		/* All elements */
		for ( iterElements = elements_noeud_courant.begin(); iterElements != elements_noeud_courant.end() ; iterElements++ ) {


			if ( (*iterElements) == element ) {
				// Trouve
				std::cout << "SearchN : Already exists" << std::endl;
				return (*iterFils);
			}
			/// Je bloque la. Mais sur le princope, on parcours a la fois les pointeurs vers les fils et les elements contenus dans le Noeud courant
			else if ( element < (*iterElements) ) { // Si l'element a inserer est plus petit, alors il sera situe dans le noeud pointe "a gauche"
				// On descend dans le Noeud a gauche de l'element en cours.
				noeud_courant = (*iterFils);

				break;

			}
			else if ( (*iterElements) == elements_noeud_courant.back() ) {
				// On descend dans le noeud tout a droite.
				noeud_courant = fils_noeud_courant.back();
				break;

			}
			else {
				iterFils++;
			}
			
		}

	}

	std::cout << "SearchN : Sending current node" << std::endl;
	return noeud_courant;
}

template<typename T>
void BArbre<T>::draw(std::ostream &flux) const {
 	
 	for ( int i=0; i < _noeuds.size(); i++) {
 		flux << "[" << i << "] NODE" << std::endl;
 		flux << *_noeuds.at(i);

 	}

 }

template<typename T>
std::ostream &operator<<( std::ostream &flux, BArbre<T> const& a)
{
    a.draw(flux) ;
    return flux;
}

/* 
Wiki : Une variante consiste à éclater préventivement chaque nœud « plein » (possédant le 
nombre maximal de clés) rencontré lors de la recherche du nœud où se réalisera l'insertion. 
De cette manière on évite une remontée dans l'arbre, puisque l'on assure que le père d'un 
nœud à scinder en deux peut accueillir une clé supplémentaire. 
La contrepartie en est une légère augmentation de la hauteur moyenne de l'arbre.
*/