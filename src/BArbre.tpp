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
		
		std::cout << "Choosen node : " << *node << std::endl;
		this->addToNode( node, element );

	}
	else {
		std::cout << "Dbg : Elt already present : " << element << std::endl;
		
	}

}

template<typename T>
std::vector< Noeud<T>* > BArbre<T>::addToNodeOld( Noeud<T>* node, const T& element ) {

	std::cout << "Adding/moving " << element << std::endl;
	std::vector< Noeud<T>* > vReturn;
	
	if ( node->getElements().size() < _upper ) {

		node->addElement( element );
		std::cout << "Add Successfull" << std::endl;

	}
	else {

		node->addElement( element );
		
		std::cout << "[SPLIT] Node full. Expanding this node : " << *node << std::endl;
		/* HARD */

		
		Noeud<T>* parent_node = node->getParent();
		/* If node has no parent, that's root */
		/* So let's create a new root in order to replace this one */
		if ( parent_node == NULL ) {
			std::cout << "Rebuilding root ..." << std::endl;
			_racine = new Racine<T>();
			parent_node = _racine;
			_noeuds.insert(_noeuds.begin(),_racine);

		}
		else {
			std::cout << "_____ Pas la racine !" << std::endl;
			parent_node->delFils(node);
		}

		Noeud<T>* n_left_node = new Noeud<T>( parent_node );
		Noeud<T>* n_right_node = new Noeud<T>( parent_node );


		std::vector<T> elts = node->getElements();

		typename
		std::vector<T>::iterator iterElements;

		typename
		std::vector< Noeud<T>* > parent_split;

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
				std::cout << "WILL PUSHING UP " << (*iterElements) << std::endl;
				middle_elt = (*iterElements);
			}
			else { // i > middle_index
				std::cout << "To right " << (*iterElements) << std::endl;
				addToNode( n_right_node, (*iterElements) );
			}

		}

		std::cout << "PUSHING UP " << middle_elt << std::endl;
		parent_split = addToNode( parent_node, middle_elt );


		std::vector< Noeud<T>* > sons = node->getFils();
		
		typename
		std::vector< Noeud<T>* >::iterator iterFils;

		Noeud<T>* parent_left_splitted_node;
		Noeud<T>* parent_right_splitted_node;

		if ( parent_split.size() == 2 ) {
			parent_left_splitted_node = parent_split.at(0);
			parent_right_splitted_node = parent_split.at(1);
		}
		else {
			parent_left_splitted_node = parent_node;
			parent_right_splitted_node = parent_node;
		}

		parent_left_splitted_node->addFils(n_left_node,0);
		parent_right_splitted_node->addFils(n_right_node,0);

		/* Transfert sons Nodes from original Node to two new nodes */
		int middle_son = middle_index+1;
		for ( iterFils = sons.begin(), i=0 ;
			  iterFils != sons.end();
			  iterFils++, i++		) {
			
			std::cout << "[Add] Element count : " << i << std::endl;

			if ( i < middle_index ) {
				n_left_node->addFils( (*iterFils), 0 );

			}
			else { // i > middle_index
				
				n_right_node->addFils( (*iterFils), 0 );

			}


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

		vReturn.push_back(n_left_node);
		vReturn.push_back(n_right_node);

		std::cout << "NEW Racine : " << *_racine << std::endl;

	}

	return vReturn;


}

template<typename T>
std::vector< Noeud<T>* > BArbre<T>::splitNode( Noeud<T>* node ) {
	
	std::vector< Noeud<T>* > vReturn;
	
	std::cout << "[SPLIT] Node full. Expanding this node : " << *node << std::endl;
	/* HARD */

	
	Noeud<T>* parent_node = node->getParent();
	/* If node has no parent, that's root */
	/* So let's create a new root in order to replace this one */
	if ( parent_node == NULL ) {
		std::cout << "Rebuilding root ..." << std::endl;
		_racine = new Racine<T>();
		parent_node = _racine;
		_noeuds.insert(_noeuds.begin(),_racine);

	}
	else {
		std::cout << "_____ Pas la racine !" << std::endl;
		parent_node->delFils(node);
	}

	Noeud<T>* n_left_node = new Noeud<T>( parent_node );
	Noeud<T>* n_right_node = new Noeud<T>( parent_node );


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
int BArbre<T>::removeFromNode( Noeud<T>* node, const T& element ) {
	
	/* To be or not to be a leaf. (Born, to be a leeaaf, to be a leeeaaf) */
	if ( node != _racine && node->isFeuille() ) {
		
		node->delElement( element );

		if ( node->isUnderflowing( _lower ) ) {
				
			Noeud<T>* parent_node = node->getParent();
			
			typename
			std::vector<Noeud<T>*> fils_noeud_courant = parent_node->getFils();

			typename
			std::vector<Noeud<T>*>::iterator iterFils;
			
			int node_position = -3;

			int i;
			/* Used to know leaf position between all bros */
			for ( iterFils = fils_noeud_courant.begin(), i=0;
				  iterFils != fils_noeud_courant.end();
				  iterFils++, i++ ) {

				if ( *iterFils == node ) {
					node_position = i;
				}
				  

			}

			T father_elt;
			if ( node_position <= fils_noeud_courant.size() / 2 ) {
				father_elt = node->getParent()->getElements().back();
			}
			else {
				father_elt = node->getParent()->getElements().front();
			}

			/* SWITCH */
			bool found = false;
			T son_elt;
			for ( iterFils = fils_noeud_courant.begin(), i=0;
				  iterFils != fils_noeud_courant.end();
				  iterFils++, i++ ) {

				if ( i == node_position - 1 && !(*iterFils)->isUnderflowing( _lower - 1 )  ) {
					
					son_elt = (*iterFils)->getElements().back();

				}
				else if ( i == node_position + 1 && !(*iterFils)->isUnderflowing( _lower - 1 )  ) {
					
					son_elt = (*iterFils)->getElements().front();

				}
				  
				if ( found ) {

					std::cout << "Bro found" << std::endl;
					
					node->addElement( father_elt );
					parent_node->delElement( father_elt );
					parent_node->addElement( son_elt );
					(*iterFils)->delElement( son_elt );

					break;

				}
				
			}

			/* WELL DONE */


		}

	}
	else {


		typename
		std::vector<Noeud<T>*> fils_noeud_courant = node->getFils();

		typename
		std::vector<Noeud<T>*>::iterator iterFils;
		
		int i;
		int left_element_node_position = node->getElementPosition( element );
		/* Used to know leaf position between all bros */
		for ( iterFils = fils_noeud_courant.begin(), i=0;
			  iterFils != fils_noeud_courant.end();
			  iterFils++, i++ ) {

			if ( i = left_element_node_position ) {
				
				T son_elt = (*iterFils)->getElements().back();

				/* Switch element between node and his son */
				(*iterFils)->delElement( son_elt );
				(*iterFils)->addElement( element );
				node->addElement( son_elt );

				/* Re-execute for son */
				this->removeFromNode( (*iterFils), element );
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