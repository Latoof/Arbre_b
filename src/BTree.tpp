#include "BTree.h"

template<typename T>
BTree<T>::BTree( int lower, int upper ) : _dbg(0), _size(0), _lower(lower) {
	
	if ( upper == -1 ) {
		_upper = 2 * _lower;
	}

	_racine = new Node<T>( );
	_Nodes.insert(_racine);

	std::cout << "Racine : " << *_racine << std::endl;

}


template<typename T>
BTree<T>::~BTree() {

	/* Destructors of each nodes are called */
	_Nodes.clear();

}

template<typename T>
void BTree<T>::insertElement( const T& element ) {

	std::cout << "We want to add " << element << std::endl;
	
	Node<T>* node = this->findElementNode( element );
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
void BTree<T>::splitNode( Node<T>* node ) {
		
	std::cout << "[SPLIT] Node full. Expanding this node : " << *node << std::endl;
	/* HARD */

	
	Node<T>* parent_node;

	if ( node == _racine ) {
		std::cout << "Rebuilding root ..." << std::endl;
		parent_node = new Node<T>();

		_racine = parent_node;
		//parent_node = _racine;
		_Nodes.insert(_racine);
	}
	else {

		parent_node = node->getParent();
		std::cout << "Pas la racine !!! Pere : " << *parent_node << std::endl;
		parent_node->unlinkSon(node);
		std::cout << "Son unlinked" << std::endl;
	}

	Node<T>* n_left_node;
	n_left_node = new Node<T>( parent_node );
	Node<T>* n_right_node;
	n_right_node = new Node<T>( parent_node );


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

	std::vector< Node<T>* > sons = node->getSons();

	std::cout << "-- Need to move " << sons.size() << " sons !" << std::endl;
	
	typename
	std::vector< Node<T>* >::iterator iterFils;

	/* Transfert sons Nodes from original Node to two new nodes */
	int middle_son = middle_index+1;
	for ( iterFils = sons.begin(), i=0 ;
		  iterFils != sons.end();
		  iterFils++, i++		) {
		
		std::cout << "[Add] Element count : " << i << std::endl;

		if ( i <= middle_index ) {
			n_left_node->linkSon( (*iterFils), 0 );
			std::cout << "** Adding a son to left" << std::endl;
		}
		else { // i > middle_index
			n_right_node->linkSon( (*iterFils), 0 );
			std::cout << "// Adding a son to right" << std::endl;

		}

	}


	_Nodes.erase( node );

	_Nodes.insert(n_left_node);
	_Nodes.insert(n_right_node);

	std::cout << "PUSHING UP " << middle_elt << std::endl;

	parent_node->addElement( middle_elt );

	parent_node->linkSon( n_left_node );
	parent_node->linkSon( n_right_node );



	/* Recursive */
	if ( parent_node->isOverflowing(_upper)) {
		splitNode( parent_node );
	}

}

template<typename T>
void BTree<T>::addToNode( Node<T>* node, const T& element ) {

	std::cout << "Adding/moving " << element << std::endl;
	std::vector< Node<T>* > vReturn;

	node->addElement( element );
	std::cout << "Add Successfull" << std::endl;
	
	if ( node->isOverflowing( _upper ) ) {

		this->splitNode( node );

	}

}

template<typename T>
void BTree<T>::balanceNode( Node<T>* node ) {
	
	std::cout << "Balancing Node" << *node << std::endl;
				
	/* If non-root intern node */
	if ( node != _racine ) {

		Node<T>* parent_node = node->getParent();
		
		typename
		std::vector<Node<T>*> brother_nodes = parent_node->getSons();

		typename
		std::vector<Node<T>*>::iterator iterFils;
		
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

		Node<T>* left_brother = NULL;
		Node<T>* right_brother = NULL;

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
					if ( !left_brother->isLeaf() ) {
						Node<T>* subson = left_brother->getSons().back();
						left_brother->unlinkSon( subson );
						node->linkSon( subson );		
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
					if ( !right_brother->isLeaf() ) {
						Node<T>* subson = right_brother->getSons().front();
						right_brother->unlinkSon( subson );
						node->linkSon( subson );			
					}		
					/**/
					break;
				}

			}
			  

		}


		/* If no bro with enough elts */
		if ( !found ) {

			Node<T>* choosen_bro;

			/* Transfert to left bro */
			if ( left_brother != NULL ) {

				choosen_bro = left_brother;
				std::cout << " Push Left Bro = " << *choosen_bro << std::endl;

				choosen_bro->addElement( left_father_elt );

				this->mergeNodes( choosen_bro, node );

				parent_node->unlinkSon( node );
				parent_node->delElement( left_father_elt );

			}
			/* Transfert to right bro */
			else if ( right_brother != NULL ) {

				choosen_bro = right_brother;
				std::cout << " Push Right Bro = " << *choosen_bro << std::endl;

				choosen_bro->addElement( right_father_elt );

				this->mergeNodes( choosen_bro, node );

				parent_node->unlinkSon( node );
				parent_node->delElement( right_father_elt );

			}
			else {
				std::cout << "Sorry, I failed" << std::endl;
				return;
			}

			_Nodes.erase(node);
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
		std::cout << "ROOOOOT (" << node->getSons().size() << " sons)" << std::endl;
					/* Will contain all elements of each node */
		typename
		std::vector< Node<T>* > node_sons = node->getSons();

		for ( int i=0; i<node_sons.size(); i++ ) {
			
			Node<T>* current_son = node_sons.at(i);
			node->unlinkSon( current_son );

			this->mergeNodes( node, current_son );

			_Nodes.erase( current_son );

		}

		_racine = node;

	}

	return;
}

template<typename T>
void BTree<T>::mergeNodes( Node<T>* targetNode, Node<T>* sourceNode ) {
	
	typename
	std::vector<T> node_elements = sourceNode->getElements();

	typename
	std::vector< Node<T>* > node_sons = sourceNode->getSons();

	int i;
	for ( i=0; i<node_elements.size(); i++ ) {
		targetNode->addElement( node_elements.at(i) );
	}

	for ( i=0; i<node_sons.size(); i++ ) {
		targetNode->linkSon( node_sons.at(i) );
	}

}

template<typename T>
int BTree<T>::removeFromNode( Node<T>* node, const T& element ) {
	
	std::cout << std::endl << "--- Removing " << element << " from " << *node << std::endl;

	/* Underflowing leaf */
	if ( node != _racine && node->isLeaf() ) {

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
		std::vector<Node<T>*> fils_Node_courant = node->getSons();

		typename
		std::vector<Node<T>*>::iterator iterFils;

		std::cout << "Intern node : Switching with son : " << std::endl;

		
		int i;
		int right_element_node_position = node->getElementPosition( element ) + 1;



		/* Used to know leaf position between all bros */
		for ( iterFils = fils_Node_courant.begin(), i=0;
			  iterFils != fils_Node_courant.end();
			  iterFils++, i++ ) {
			
			if ( i == right_element_node_position ) {
				
				/**/
				Node<T>* leftmost_leaf = (*iterFils)->leftmostLeaf();
				T leftmost_elt = leftmost_leaf->getElements().front();

				// Switch element between node and his son 
				leftmost_leaf->delElement( leftmost_elt );
				leftmost_leaf->addElement( element );

				node->delElement( element );
				node->addElement( leftmost_elt );

				this->removeFromNode( leftmost_leaf, element );

				break;

			}			  

		}


	}


}
	

template<typename T>
int BTree<T>::removeElement( T element ) {
	
	std::cout << "We want to del " << element << std::endl;
	
	Node<T>* node = this->findElementNode( element );
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

/*
template<typename T>
T BTree<T>::chercherElement( const T& element ) {
	

	Node<T>* Node_courant = _racine;

	while ( !Node_courant->isLeaf() ) {

		/* Will contain all elements of each node 
		typename
		std::vector<T>::iterator iterElements;

		/* Will contain all subNodes of current node 
		typename
		std::vector<Node<T>*>::iterator iterFils = Node_courant->getSons().begin();

		/* All elements 
		for ( iterElements = Node_courant->getElements().begin(); iterElements != Node_courant->getElements().end() ; iterElements++ ) {

			if ( (*iterElements) == element ) {
				// Trouve
				return (*iterElements);
			}
			/// Je bloque la. Mais sur le princope, on parcours a la fois les pointeurs vers les fils et les elements contenus dans le Node courant
			else if ( (*iterElements) < element ) { // Si l'element a inserer est plus petit, alors il sera situe dans le Node pointe "a gauche"
				// On descend dans le Node a gauche de l'element en cours.
				Node_courant = (*iterFils);

			}
			else if ( iterElements == Node_courant->getElements()->end() ) {
				// On descend dans le Node tout a droite.
				Node_courant = iterFils->end();

			}
			else {
				iterFils++;
			}
			
		}


	}

	return element;
}
*/

template<typename T>
Node<T>* BTree<T>::findElementNode( const T& element ) {
	
	std::cout << "Starts here" << std::endl;

	Node<T>* Node_courant;
	
	Node_courant = _racine;
	/* Will contain all subNodes of current node */


	while ( !Node_courant->isLeaf() ) {

		std::cout << "Loop" << std::endl;

		/* Will contain all elements of each node */


		typename
		std::vector<T> elements_Node_courant = Node_courant->getElements();

		typename
		std::vector<T>::iterator iterElements;


		typename
		std::vector<Node<T>*> fils_Node_courant = Node_courant->getSons();

		typename
		std::vector<Node<T>*>::iterator iterFils;
		
		iterFils = fils_Node_courant.begin();


		/* All elements */
		for ( iterElements = elements_Node_courant.begin(); iterElements != elements_Node_courant.end() ; iterElements++ ) {


			if ( (*iterElements) == element ) {
				// Trouve
				std::cout << "SearchN : Already exists" << std::endl;
				return Node_courant;
			}
			/// Je bloque la. Mais sur le princope, on parcours a la fois les pointeurs vers les fils et les elements contenus dans le Node courant
			else if ( element < (*iterElements) ) { // Si l'element a inserer est plus petit, alors il sera situe dans le Node pointe "a gauche"
				// On descend dans le Node a gauche de l'element en cours.
				Node_courant = (*iterFils);

				break;

			}
			else if ( (*iterElements) == elements_Node_courant.back() ) {
				// On descend dans le Node tout a droite.
				Node_courant = fils_Node_courant.back();
				break;

			}
			else {
				iterFils++;
			}
			
		}

	}

	std::cout << "SearchN : Sending current node" << std::endl;
	return Node_courant;
}

template<typename T>
Node<T>* BTree<T>::getRootNode() {
	return _racine;
}



template<typename T>
void BTree<T>::draw(std::ostream &flux) const {
 	
 	/*
 	for ( int i=0; i < _Nodes.size(); i++) {
 		flux << "[" << i << "] NODE" << std::endl;
 		flux << *_Nodes.at(i);

 	}
 	*/
 	std::cout << _Nodes.size() << " nodes : " << std::endl;
 	std::cout << *_racine;


 }

template<typename T>
std::ostream &operator<<( std::ostream &flux, BTree<T> const& a)
{
    a.draw(flux) ;
    return flux;
}

/* 
Wiki : Une variante consiste à éclater préventivement chaque nœud « plein » (possédant le 
nombre maximal de clés) rencontré lors de la recherche du nœud où se réalisera l'insertion. 
De cette manière on évite une remontée dans l'Tree, puisque l'on assure que le père d'un 
nœud à scinder en deux peut accueillir une clé supplémentaire. 
La contrepartie en est une légère augmentation de la hauteur moyenne de l'Tree.
*/