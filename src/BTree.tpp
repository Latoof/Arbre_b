#include "BTree.h"

template<typename T, class Cmp>
BTree<T,Cmp>::BTree( int lower, int upper ) : _dbg(0), _size(0), _lower(lower) {
	
	if ( upper == -1 ) {
		_upper = 2 * _lower;
	}

	_root = new Node<T,Cmp>();
	_Nodes.insert(_root);

}


template<typename T, class Cmp>
BTree<T,Cmp>::~BTree() {

	/* Destructors of each nodes are called */
	_Nodes.clear();

}

template<typename T, class Cmp>
void BTree<T,Cmp>::insert( const T& element ) {
	
	Node<T,Cmp>* node = this->findElementNode( element );

	if ( node != NULL && !node->contains(element) ) {
		
		this->addToNode( node, element );
		_size++;

	}

}



template<typename T, class Cmp>
void BTree<T,Cmp>::splitNode( Node<T,Cmp>* node ) {
		

	Node<T,Cmp>* parent_node;

	if ( node == _root ) {

		parent_node = new Node<T,Cmp>();

		_root = parent_node;
		//parent_node = _root;
		_Nodes.insert(_root);

	}
	else {

		parent_node = node->getParent();
		parent_node->unlinkSon(node);

	}

	Node<T,Cmp>* n_left_node = new Node<T,Cmp>();
	Node<T,Cmp>* n_right_node = new Node<T,Cmp>();


	std::vector<T> elts = node->getElements();

	typename
	std::vector<T>::iterator iterElements;

	int i;
	/* Transfert elements from original Node to two new nodes */
	T middle_elt;
	int middle_index = (elts.size() - 1) / 2 ;

	for ( iterElements = elts.begin(), i=0;
		  iterElements != elts.end();
		  iterElements++, i++		) {
		

		if ( i < middle_index ) {
			addToNode( n_left_node, (*iterElements) );
		}
		else if ( i == middle_index ) {
			middle_elt = (*iterElements);
		}
		else { // i > middle_index
			addToNode( n_right_node, (*iterElements) );
		}

	}

	std::vector< Node<T,Cmp>* > sons = node->getSons();
	
	typename
	std::vector< Node<T,Cmp>* >::iterator iterFils;

	/* Transfert sons Nodes from original Node to two new nodes */
	int middle_son = middle_index+1;
	for ( iterFils = sons.begin(), i=0 ;
		  iterFils != sons.end();
		  iterFils++, i++		) {
		
		if ( i <= middle_index ) {
			n_left_node->linkSon( (*iterFils) );
		}
		else { // i > middle_index
			n_right_node->linkSon( (*iterFils) );

		}

	}


	_Nodes.erase( node );
	delete node;

	_Nodes.insert(n_left_node);
	_Nodes.insert(n_right_node);


	parent_node->addElement( middle_elt );

	parent_node->linkSon( n_left_node );
	parent_node->linkSon( n_right_node );



	/* Recursive */
	if ( parent_node->isOverflowing(_upper)) {
		splitNode( parent_node );
	}

}

template<typename T, class Cmp>
void BTree<T,Cmp>::addToNode( Node<T,Cmp>* node, const T& element ) {

	std::vector< Node<T,Cmp>* > vReturn;

	node->addElement( element );
	
	if ( node->isOverflowing( _upper ) ) {

		this->splitNode( node );

	}

}

template<typename T, class Cmp>
void BTree<T,Cmp>::balanceNode( Node<T,Cmp>* node ) {
					
	/* If non-root intern node */
	if ( node != _root ) {

		Node<T,Cmp>* parent_node = node->getParent();
		
		typename
		std::vector<Node<T,Cmp>*> brother_nodes = parent_node->getSons();

		typename
		std::vector<Node<T,Cmp>*>::iterator iterFils;
		
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

		Node<T,Cmp>* left_brother = NULL;
		Node<T,Cmp>* right_brother = NULL;

		/* SWITCH */
		/* Let's run through bros [NEED OPT] */
		bool found = false;
		T brother_elt;
		for ( iterFils = brother_nodes.begin(), i=0;
			  iterFils != brother_nodes.end();
			  iterFils++, i++ ) {

			/* If we have left bro */
			if ( i == node_position - 1 ) {
				
				left_brother = (*iterFils);

				if ( !left_brother->isUnderflowing( _lower + 1 ) ) {

					brother_elt = left_brother->getElements().back();
					found = true;
				
					//node->delElement( element );
					node->addElement( left_father_elt );
					parent_node->delElement( left_father_elt );

					parent_node->addElement( brother_elt );
					(*iterFils)->delElement( brother_elt );

					/**/
					if ( !left_brother->isLeaf() ) {
						Node<T,Cmp>* subson = left_brother->getSons().back();
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
				
					//node->delElement( element );
					node->addElement( right_father_elt );
					parent_node->delElement( right_father_elt );

					parent_node->addElement( brother_elt );
					(*iterFils)->delElement( brother_elt );

					/**/
					if ( !right_brother->isLeaf() ) {
						Node<T,Cmp>* subson = right_brother->getSons().front();
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

			Node<T,Cmp>* choosen_bro;

			/* Transfert to left bro */
			if ( left_brother != NULL ) {

				choosen_bro = left_brother;

				choosen_bro->addElement( left_father_elt );

				this->mergeNodes( choosen_bro, node );

				parent_node->unlinkSon( node );
				parent_node->delElement( left_father_elt );

			}
			/* Transfert to right bro */
			else if ( right_brother != NULL ) {

				choosen_bro = right_brother;

				choosen_bro->addElement( right_father_elt );

				this->mergeNodes( choosen_bro, node );

				parent_node->unlinkSon( node );
				parent_node->delElement( right_father_elt );

			}
			else {
				return;
			}

			_Nodes.erase(node);
			delete node;
			/* RECURSIVE (we know that's not a leaf*/

			if ( parent_node->isUnderflowing( _lower)  ) {
				this->balanceNode( parent_node );
			}
			//this->removeFromNode( parent_node, father_elt );
			/*****************/

		}
	}
	/* If node == _root; */
	/* We will merge the subnodes in the root */
	else {
					/* Will contain all elements of each node */
		typename
		std::vector< Node<T,Cmp>* > node_sons = node->getSons();

		for ( int i=0; i<node_sons.size(); i++ ) {
			
			Node<T,Cmp>* current_son = node_sons.at(i);
			node->unlinkSon( current_son );

			this->mergeNodes( node, current_son );

			_Nodes.erase( current_son );
			delete current_son;

		}

		_root = node;

	}

	return;
}

template<typename T, class Cmp>
void BTree<T,Cmp>::mergeNodes( Node<T,Cmp>* targetNode, Node<T,Cmp>* sourceNode ) {
	
	typename
	std::vector<T> node_elements = sourceNode->getElements();

	typename
	std::vector< Node<T,Cmp>* > node_sons = sourceNode->getSons();

	int i;
	for ( i=0; i<node_elements.size(); i++ ) {
		targetNode->addElement( node_elements.at(i) );
	}

	for ( i=0; i<node_sons.size(); i++ ) {
		targetNode->linkSon( node_sons.at(i) );
	}

}

template<typename T, class Cmp>
int BTree<T,Cmp>::removeFromNode( Node<T,Cmp>* node, const T& element ) {
	
	/* Underflowing leaf */
	if ( node != _root && node->isLeaf() ) {

	/* To be or not to be a leaf. (Born, to be a leeaaf, to be a leeeaaf) */
		node->delElement( element );
		if ( node->isUnderflowing( _lower ) ) {

			this->balanceNode( node );
		}

	} 
	/* Underflowing intern node */
	else {


		typename
		std::vector<Node<T,Cmp>*> fils_Node_courant = node->getSons();

		typename
		std::vector<Node<T,Cmp>*>::iterator iterFils;
		
		int i;
		int right_element_node_position = node->getElementPosition( element ) + 1;



		/* Used to know leaf position between all bros */
		for ( iterFils = fils_Node_courant.begin(), i=0;
			  iterFils != fils_Node_courant.end();
			  iterFils++, i++ ) {
			
			if ( i == right_element_node_position ) {
				
				/**/
				Node<T,Cmp>* leftmost_leaf = (*iterFils)->leftmostLeaf();
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
	

template<typename T, class Cmp>
int BTree<T,Cmp>::erase( T element ) {
		
	Node<T,Cmp>* node = this->findElementNode( element );

	if ( node != NULL && node->contains(element) ) {
		
		this->removeFromNode( node, element );
		_size--;
	}

	return 0;
}

template<typename T, class Cmp>
Node<T,Cmp>* BTree<T,Cmp>::findElementNode( const T& element ) {
	
	Node<T,Cmp>* Node_courant;
	
	Node_courant = _root;
	/* Will contain all subNodes of current node */


	while ( !Node_courant->isLeaf() ) {

		/* Will contain all elements of each node */


		typename
		std::vector<T> elements_Node_courant = Node_courant->getElements();

		typename
		std::vector<T>::iterator iterElements;


		typename
		std::vector<Node<T,Cmp>*> fils_Node_courant = Node_courant->getSons();

		typename
		std::vector<Node<T,Cmp>*>::iterator iterFils;
		
		iterFils = fils_Node_courant.begin();


		/* All elements */
		for ( iterElements = elements_Node_courant.begin(); iterElements != elements_Node_courant.end() ; iterElements++ ) {


			if ( (*iterElements) == element ) {
				return Node_courant;
			}

			else if ( element < (*iterElements) ) { // Si l'element a inserer est plus petit, alors il sera situe dans le Node pointe "a gauche"

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

	return Node_courant;
}

template<typename T, class Cmp>
Node<T,Cmp>* BTree<T,Cmp>::getRootNode() {
	return _root;
}



template<typename T, class Cmp>
void BTree<T,Cmp>::draw(std::ostream &flux) const {
 	
 	/*
 	for ( int i=0; i < _Nodes.size(); i++) {
 		flux << "[" << i << "] NODE" << std::endl;
 		flux << *_Nodes.at(i);

 	}
 	*/
 	std::cout << _Nodes.size() << " nodes : " << std::endl;
 	std::cout << *_root;


 }

template<typename T, class Cmp>
std::ostream &operator<<( std::ostream &flux, BTree<T,Cmp> const& a)
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