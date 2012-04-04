#include "Node.h"

template<typename T>
Node<T>::Node() {
	
}

template<typename T>
Node<T>::Node( Node<T>* parent ) : _parent(parent) {
	std::cout << "ADD SON" << std::endl;
	//parent->linkSon(this);
}

template<typename T>
int Node<T>::addElement( T elt ) {

	//template<typename T>
	typename
	std::vector<T>::iterator iterElements;

	int i;
	for ( iterElements = _liste_elements.begin(); iterElements != _liste_elements.end() ; iterElements++ ) {

 		if ( elt < (*iterElements) ) {
 			_liste_elements.insert( iterElements, elt );
 			
 			return i+1;
 		}

 		i++;

 		
 	}
 	 //_liste_elements.insert( _liste_elements.end(), elt );
 	 _liste_elements.push_back( elt );

 	 return i;

	//_liste_elements.push_back( elt );
}


template<typename T>
 T Node<T>::getElement( int i ) {
	return _liste_elements.at(i);
}

template<typename T>
std::vector<T>& Node<T>::getElements() {
	return _liste_elements;
}

template<typename T>
int Node<T>::size() const {
	return _liste_elements.size();
}


template<typename T>
int Node<T>::getSonPosition( const Node<T>* son ) {
	
  	nodes_ptr_iterator iter_sons = std::find(_liste_fils.begin(), _liste_fils.end(), son);

    if ( iter_sons != _liste_fils.end() ) {
    	return std::distance( _liste_fils.begin(), iter_sons );
    } 
    else {
    	return -1;
    }

}

template<typename T>
std::vector< Node<T>* >& Node<T>::getSons() {
	return _liste_fils;
}

template<typename T>
Node<T>* Node<T>::getParent() {
	return _parent;
}

template<typename T>
void Node<T>::setParent( Node<T>* parent ) {
	_parent = parent;
}

template<typename T>
bool Node<T>::isLeaf() const {
	return ( _liste_fils.empty() );
}

template<typename T>
bool Node<T>::isOverflowing( int max_size ) const {
	return _liste_elements.size() > max_size;
}

template<typename T>
bool Node<T>::isUnderflowing( int min_size ) const {
	return _liste_elements.size() < min_size;
}

template<typename T>
bool Node<T>::contains( const T& elt ) const {
	if ( !_liste_elements.empty() 
		&& std::find(_liste_elements.begin(), _liste_elements.end(), elt) != _liste_elements.end()) {
		return true;
	} 
	else {
	    return false;
	}
}

template<typename T>
Node<T>* Node<T>::leftmostLeaf() {
	
	if ( this->isLeaf() ) {
		return this;
	}
	else {
		return _liste_fils.front()->leftmostLeaf();
	}

}

template<typename T>
Node<T>* Node<T>::rightmostLeaf() {
	
	if ( this->isLeaf() ) {
		return this;
	}
	else {
		return _liste_fils.back()->rightmostLeaf();
	}

}

/*
template<typename T>
int Node<T>::element_count() {
	return _liste_elements.size();
}

/*
template<typename T>
void Node<T>::linkSon( Node<T>* node, int index ) {

	if ( index == -1 )
		_liste_fils.push_back(node);
	else {
		if ( _liste_fils.begin()+index <= _liste_fils.end() )
			_liste_fils.insert(_liste_fils.begin()+index,node);
		else
			_liste_fils.push_back(node);

	}
}
*/

template<typename T>
int Node<T>::linkSon( Node<T>* node, int index ) {

	std::cout << "Adding son ..." << std::endl;

	//typename
	T lastEltFils = node->getElements().back();

	typename
	std::vector<T>::iterator iterElements;
	typename
	std::vector< Node<T>* >::iterator iterFils;

	int i;
	for ( iterElements = _liste_elements.begin(), iterFils = _liste_fils.begin(); 
		iterElements != _liste_elements.end(), iterFils != _liste_fils.end() ; 
		iterElements++, iterFils++ ) {

 		if ( lastEltFils < (*iterElements) ) {
 			_liste_fils.insert( iterFils, node );
 			node->setParent( this );
 			
 			return i+1;
 		}

 		i++;

 		
 	}
 	 //_liste_fils.insert( _liste_fils.end(), node );
 	_liste_fils.push_back( node );
 	node->setParent( this );

 	 return i;
}

template<typename T>
void Node<T>::unlinkSon( Node<T>* node ) {

	typename
	std::vector< Node<T>* >::iterator iterFindNode;
	for ( iterFindNode = _liste_fils.begin(); iterFindNode != _liste_fils.end() ; iterFindNode++) {
		
		if ( (*iterFindNode) == node ) {
			std::cout << "Node found " << std::endl;
			_liste_fils.erase( iterFindNode );
			break;
		}

	}

}





/* May be useless or non pertinent. Used for node deletion */
template<typename T>
int Node<T>::getElementPosition( const T& element ) const {

 	int pos = -1;
 	for ( int i=0; i<_liste_elements.size(); i++ ) {
 		
 		if ( _liste_elements.at(i) == element ) {
 			pos = i;
 		}

 	}

	return pos;
}

template<typename T>
int Node<T>::delElement( const T& element ) {

 	int pos = this->getElementPosition( element );

 	if ( pos != -1 ) {
 		_liste_elements.erase( _liste_elements.begin()+pos );
 	}

 	
	return pos;
}

template<typename T>
void Node<T>::draw(std::ostream &flux) {

	for ( int j=0; j < _liste_elements.size(); j++) {
		flux << _liste_elements.at(j) << " ";
	}

	flux << std::endl;

	flux << "Nb sons : " << _liste_fils.size() << std::endl;

	flux << std::endl;


	//
	for ( int j=0; j < _liste_fils.size(); j++) {
		flux << *_liste_fils.at(j);
	}
	//
 	

 }

template<typename T>
std::ostream& operator<<( std::ostream& flux, Node<T>& n) {
    n.draw(flux) ;
    return flux;
}

template<typename T>
Node<T>::~Node() {
	
}