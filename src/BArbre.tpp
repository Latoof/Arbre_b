#include "BArbre.h"

template<typename T>
BArbre<T>::BArbre( int lower, int upper ) : _dbg(0), _size(0), _lower(lower) {
	
	if ( upper == -1 ) {
		_upper = 2 * _lower;
	}

	_racine = new Noeud<T>( );
	_noeuds.insert(_racine);

	std::cout << "Racine : " << *_racine << std::endl;

}


template<typename T>
BArbre<T>::~BArbre() {

	/* Destructor of each nodes are called */
	_noeuds.clear();

}

template<typename T>
void BArbre<T>::ajouterElement( const T& element ) {

	std::cout << "We want to add " << element << std::endl;
	
	Noeud<T>* node = this->chercherElementN( element );
	std::cout << "Search returned" << std::endl;

	if ( node != NULL && !node->contains(element) ) {
		
		std::cout << "Choosen node : " << *node << std::endl;
		this->addToNode( node, element );
		_size++;

	}
	else {
		std::cout << "Dbg : Elt already present : " << element << std::endl;
		
	}

}



template<typename T>
std::vector< Noeud<T>* > BArbre<T>::splitNode( Noeud<T>* node ) {
	
	std::vector< Noeud<T>* > vReturn;
	
	std::cout << "[SPLIT] Node full. Expanding this node : " << *node << std::endl;
	/* HARD */

	
	Noeud<T>* parent_node;

	//std::cout << "Node i : " << node << "| Root i : " << _racine << std::endl;

	if ( node == _racine ) {
		std::cout << "Rebuilding root ..." << std::endl;
		parent_node = new Noeud<T>();

		_racine = parent_node;
		//parent_node = _racine;
		_noeuds.insert(_racine);
	}
	else {

		parent_node = node->getParent();
		std::cout << "Pas la racine !!! Pere : " << *parent_node << std::endl;
		parent_node->delFils(node);
		std::cout << "Son unlinked" << std::endl;
	}

	Noeud<T>* n_left_node;
	n_left_node = new Noeud<T>( parent_node );
	Noeud<T>* n_right_node;
	n_right_node = new Noeud<T>( parent_node );


	std::vector<T> elts = node->getElements();

	typename
	std::vector<T>::iterator iterElements;

	int i;
	/* Transfert elements from original Node to two new nodes */
	int middle_elt;
	int middle_index = (elts.size() - 1) / 2 ;
	std::cout << "middle_index : " << middle_index << std::endl;
	for ( iterElements = elts.begin(), i=0;
		  iterElements != elts.end();
		  iterElements++, i++		) {
		
		std::cout << "[Add] Element count : " << i << std::endl;

		if ( i < middle_index ) {
			std::cout << "To left " << (*iterElements) << std::endl;
			addToNode( n_left_node, (*iterElements) );
		}
		else if ( i == middle_index ) {
			middle_elt = (*iterElements);
		}
		else { // i > middle_index
			std::cout << "To right " << (*iterElements) << std::endl;
			addToNode( n_right_node, (*iterElements) );
		}

	}

	std::vector< Noeud<T>* > sons = node->getFils();

	std::cout << "-- Need to move " << sons.size() << " sons !" << std::endl;
	
	typename
	std::vector< Noeud<T>* >::iterator iterFils;

	/* Transfert sons Nodes from original Node to two new nodes */
	int middle_son = middle_index+1;
	for ( iterFils = sons.begin(), i=0 ;
		  iterFils != sons.end();
		  iterFils++, i++		) {
		
		std::cout << "[Add] Element count : " << i << std::endl;

		if ( i <= middle_index ) {
			n_left_node->addFils( (*iterFils), 0 );
			std::cout << "** Adding a son to left" << std::endl;
		}
		else { // i > middle_index
			n_right_node->addFils( (*iterFils), 0 );
			std::cout << "// Adding a son to right" << std::endl;

		}

	}


	_noeuds.erase( node );

	_noeuds.insert(n_left_node);
	_noeuds.insert(n_right_node);

	vReturn.push_back(n_left_node);
	vReturn.push_back(n_right_node);



	std::cout << "PUSHING UP " << middle_elt << std::endl;

	parent_node->addElement( middle_elt );

	parent_node->addFils( n_left_node );
	parent_node->addFils( n_right_node );



	/* Recursive */
	if ( parent_node->isOverflowing(_upper)) {
		splitNode( parent_node );
	}

	return vReturn;


}

template<typename T>
std::vector< Noeud<T>* > BArbre<T>::addToNode( Noeud<T>* node, const T& element ) {

	std::cout << "Adding/moving " << element << std::endl;
	std::vector< Noeud<T>* > vReturn;

	node->addElement( element );
	std::cout << "Add Successfull" << std::endl;
	
	if ( node->isOverflowing( _upper ) ) {

		this->splitNode( node );

	}

	return vReturn;
}

template<typename T>
std::vector< Noeud<T>* > BArbre<T>::balanceNode( Noeud<T>* node ) {
	
	std::vector< Noeud<T>* > vReturn;

	std::cout << "Balancing Node" << *node << std::endl;
				
	/* If non-root intern node */
	if ( node != _racine ) {

		Noeud<T>* parent_node = node->getParent();
		
		typename
		std::vector<Noeud<T>*> brother_nodes = parent_node->getFils();

		typename
		std::vector<Noeud<T>*>::iterator iterFils;
		
		int node_position = -3;

		int i;
		/* Used to know node position between all bros */
		for ( iterFils = brother_nodes.begin(), i=0;
			  iterFils != brother_nodes.end();
			  iterFils++, i++ ) {

			if ( *iterFils == node ) {
				node_position = i;
			}

		}

		typename
		std::vector<T> father_elts = parent_node->getElements();

		/* We want to know which elements are sep-keys in parent node */
		T left_father_elt;
		T right_father_elt;
		if ( node_position > 0 ) {
			left_father_elt = father_elts.at(node_position-1);
		}
		if ( node_position < father_elts.size() ) {
			right_father_elt = father_elts.at(node_position);
		}

		Noeud<T>* left_brother = NULL;
		Noeud<T>* right_brother = NULL;

		/* SWITCH */
		/* Let's run through bros [NEED OPT] */
		bool found = false;
		T brother_elt;
		for ( iterFils = brother_nodes.begin(), i=0;
			  iterFils != brother_nodes.end();
			  iterFils++, i++ ) {

			std::cout << "Viewing node " << i << std::endl;

			/* If we have left bro */
			if ( i == node_position - 1 ) {
				
				left_brother = (*iterFils);

				if ( !left_brother->isUnderflowing( _lower + 1 ) ) {

					brother_elt = left_brother->getElements().back();
					found = true;

					std::cout << "Left Bro with sufficient elts found : " << **iterFils << std::endl;
				
					//node->delElement( element );
					node->addElement( left_father_elt );
					parent_node->delElement( left_father_elt );
					std::cout << left_father_elt << " to node " << std::endl;

					parent_node->addElement( brother_elt );
					(*iterFils)->delElement( brother_elt );
					std::cout << brother_elt << " to parent " << std::endl;

					/**/
					if ( !left_brother->isFeuille() ) {
						Noeud<T>* subson = left_brother->getFils().back();
						left_brother->delFils( subson );
						node->addFils( subson );		
					}			
					/**/
					break;
				}

			}
			/* If we have right bro */
			else if ( i == node_position + 1 ) {
				
				right_brother = (*iterFils);
				
				if (  !right_brother->isUnderflowing( _lower + 1 ) ) {

					brother_elt = right_brother->getElements().front();
					found = true;

					std::cout << "Right Bro with sufficient elts found : " << **iterFils << std::endl;
				
					//node->delElement( element );
					node->addElement( right_father_elt );
					parent_node->delElement( right_father_elt );
					std::cout << right_father_elt << " to node " << std::endl;

					parent_node->addElement( brother_elt );
					(*iterFils)->delElement( brother_elt );
					std::cout << brother_elt << " to parent " << std::endl;

					/**/
					if ( !right_brother->isFeuille() ) {
						Noeud<T>* subson = right_brother->getFils().front();
						right_brother->delFils( subson );
						node->addFils( subson );			
					}		
					/**/
					break;
				}

			}
			  

		}


		/* If no bro with enough elts */
		if ( !found ) {

			Noeud<T>* choosen_bro;

			/* Transfert to left bro */
			if ( left_brother != NULL ) {

				choosen_bro = left_brother;
				std::cout << " Push Left Bro = " << *choosen_bro << std::endl;

				choosen_bro->addElement( left_father_elt );

				this->mergeNodes( choosen_bro, node );

				parent_node->delFils( node );
				parent_node->delElement( left_father_elt );

			}
			/* Transfert to right bro */
			else if ( right_brother != NULL ) {

				choosen_bro = right_brother;
				std::cout << " Push Right Bro = " << *choosen_bro << std::endl;

				choosen_bro->addElement( right_father_elt );

				this->mergeNodes( choosen_bro, node );

				parent_node->delFils( node );
				parent_node->delElement( right_father_elt );

			}
			else {
				std::cout << "Sorry, I failed" << std::endl;
				return vReturn;
			}

			_noeuds.erase(node);
			/* RECURSIVE (we know that's not a leaf*/

			if ( parent_node->isUnderflowing( _lower)  ) {
				this->balanceNode( parent_node );
			}
			//this->removeFromNode( parent_node, father_elt );
			/*****************/

		}
	}
	/* If node == _racine; */
	/* We will merge the subnodes in the root */
	else {
		std::cout << "ROOOOOT (" << node->getFils().size() << " sons)" << std::endl;
					/* Will contain all elements of each node */
		typename
		std::vector< Noeud<T>* > node_sons = node->getFils();

		for ( int i=0; i<node_sons.size(); i++ ) {
			
			Noeud<T>* current_son = node_sons.at(i);
			node->delFils( current_son );

			this->mergeNodes( node, current_son );

			_noeuds.erase( current_son );

		}

		_racine = node;

	}

	return vReturn;
}

template<typename T>
void BArbre<T>::mergeNodes( Noeud<T>* targetNode, Noeud<T>* sourceNode ) {
	
	typename
	std::vector<T> node_elements = sourceNode->getElements();

	typename
	std::vector< Noeud<T>* > node_sons = sourceNode->getFils();

	int i;
	for ( i=0; i<node_elements.size(); i++ ) {
		targetNode->addElement( node_elements.at(i) );
	}

	for ( i=0; i<node_sons.size(); i++ ) {
		targetNode->addFils( node_sons.at(i) );
	}

}

template<typename T>
int BArbre<T>::removeFromNode( Noeud<T>* node, const T& element ) {
	
	std::cout << std::endl << "--- Removing " << element << " from " << *node << std::endl;

	/* Underflowing leaf */
	if ( node != _racine && node->isFeuille() ) {

	/* To be or not to be a leaf. (Born, to be a leeaaf, to be a leeeaaf) */
		std::cout << "Leaf node, ";
		node->delElement( element );
		if ( node->isUnderflowing( _lower ) ) {
						std::cout << "underflow, balancing ..." << std::endl;

			this->balanceNode( node );
		}
		else {
			std::cout << "enought elts." << std::endl;
		}

	} 
	/* Underflowing intern node */
	else {


		typename
		std::vector<Noeud<T>*> fils_noeud_courant = node->getFils();

		typename
		std::vector<Noeud<T>*>::iterator iterFils;

		std::cout << "Intern node : Switching with son : " << std::endl;

		
		int i;
		//int left_element_node_position = node->getElementPosition( element );
		int right_element_node_position = node->getElementPosition( element ) + 1;



		/* Used to know leaf position between all bros */
		for ( iterFils = fils_noeud_courant.begin(), i=0;
			  iterFils != fils_noeud_courant.end();
			  iterFils++, i++ ) {

			//if ( i == left_element_node_position ) {
			
			if ( i == right_element_node_position ) {
				
				/**/
				Noeud<T>* leftmost_leaf = (*iterFils)->leftmostLeaf();
				T leftmost_elt = leftmost_leaf->getElements().front();

				// Switch element between node and his son 
				leftmost_leaf->delElement( leftmost_elt );
				leftmost_leaf->addElement( element );

				node->delElement( element );
				node->addElement( leftmost_elt );

				// RECURSIVE
				this->removeFromNode( leftmost_leaf, element );

				/**/

				/*

				//T son_elt = (*iterFils)->getElements().back();
				T son_elt = (*iterFils)->getElements().front();


				Noeud<T>* son_node = (*iterFils);
				std::cout << "Choosen son : " << *son_node << std::endl;
				// Switch element between node and his son 
				son_node->delElement( son_elt );
				son_node->addElement( element );

				node->delElement( element );
				node->addElement( son_elt );

				// RECURSIVE
				this->removeFromNode( son_node, element );
				*/

				break;

			}			  

		}


	}


}
	

template<typename T>
int BArbre<T>::supprimerElement( T element ) {
	
	std::cout << "We want to del " << element << std::endl;
	
	Noeud<T>* node = this->chercherElementN( element );
	std::cout << "Search returned" << std::endl;

	if ( node != NULL && node->contains(element) ) {
		
		std::cout << "Choosen node : " << *node << std::endl;
		this->removeFromNode( node, element );
		_size--;
	}
	else {
		std::cout << "Dbg : Elt not present : " << element << std::endl;
		
	}

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
	
	noeud_courant = _racine;
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
				return noeud_courant;
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
 	
 	/*
 	for ( int i=0; i < _noeuds.size(); i++) {
 		flux << "[" << i << "] NODE" << std::endl;
 		flux << *_noeuds.at(i);

 	}
 	*/
 	std::cout << _noeuds.size() << " nodes : " << std::endl;
 	std::cout << *_racine;


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