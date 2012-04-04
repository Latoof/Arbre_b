#include "Node.h"

template<typename T, class Cmp>
Node<T,Cmp>::Node() {
	
}

template<typename T, class Cmp>
int Node<T,Cmp>::addElement( T element ) {

	//template<typename T, class Cmp>
	typename
	std::vector<T>::iterator iterElements;

	int i;
	for ( iterElements = _elements_list.begin(); iterElements != _elements_list.end() ; iterElements++ ) {

 		if ( element < (*iterElements) ) {
 			_elements_list.insert( iterElements, element );
 			
 			return i+1;
 		}

 		i++;
 		
 	}
 	 _elements_list.push_back( element );

 	 return i;
}


template<typename T, class Cmp>
int Node<T,Cmp>::delElement( const T& element ) {

 	int pos = this->getElementPosition( element );

 	if ( pos != -1 ) {
 		_elements_list.erase( _elements_list.begin()+pos );
 	}

 	
	return pos;
}


template<typename T, class Cmp>
std::vector<T>& Node<T,Cmp>::getElements() {
	return _elements_list;
}


template<typename T, class Cmp>
int Node<T,Cmp>::size() const {
	return _elements_list.size();
}


template<typename T, class Cmp>
int Node<T,Cmp>::getSonPosition( const Node<T,Cmp>* son ) {
	
  	nodes_ptr_iterator iter_sons = std::find(_sons_list.begin(), _sons_list.end(), son);

    if ( iter_sons != _sons_list.end() ) {
    	return std::distance( _sons_list.begin(), iter_sons );
    } 
    else {
    	return -1;
    }

}

template<typename T, class Cmp>
std::vector< Node<T,Cmp>* >& Node<T,Cmp>::getSons() {
	return _sons_list;
}

template<typename T, class Cmp>
Node<T,Cmp>* Node<T,Cmp>::getParent() {
	return _parent;
}

template<typename T, class Cmp>
void Node<T,Cmp>::setParent( Node<T,Cmp>* parent ) {
	_parent = parent;
}

template<typename T, class Cmp>
bool Node<T,Cmp>::isLeaf() const {
	return ( _sons_list.empty() );
}

template<typename T, class Cmp>
bool Node<T,Cmp>::isOverflowing( int max_size ) const {
	return _elements_list.size() > max_size;
}

template<typename T, class Cmp>
bool Node<T,Cmp>::isUnderflowing( int min_size ) const {
	return _elements_list.size() < min_size;
}

template<typename T, class Cmp>
bool Node<T,Cmp>::contains( const T& element ) const {
	if ( !_elements_list.empty() 
		&& std::find(_elements_list.begin(), _elements_list.end(), element) != _elements_list.end()) {
		return true;
	} 
	else {
	    return false;
	}
}

template<typename T, class Cmp>
Node<T,Cmp>* Node<T,Cmp>::leftmostLeaf() {
	
	if ( this->isLeaf() ) {
		return this;
	}
	else {
		return _sons_list.front()->leftmostLeaf();
	}

}

template<typename T, class Cmp>
Node<T,Cmp>* Node<T,Cmp>::rightmostLeaf() {
	
	if ( this->isLeaf() ) {
		return this;
	}
	else {
		return _sons_list.back()->rightmostLeaf();
	}

}


template<typename T, class Cmp>
int Node<T,Cmp>::linkSon( Node<T,Cmp>* node ) {

	T lastEltFils = node->getElements().back();

	typename
	std::vector<T>::iterator iterElements;
	typename
	std::vector< Node<T,Cmp>* >::iterator iterFils;

	int i;
	for ( iterElements = _elements_list.begin(), iterFils = _sons_list.begin(); 
		iterElements != _elements_list.end(), iterFils != _sons_list.end() ; 
		iterElements++, iterFils++ ) {

 		if ( lastEltFils < (*iterElements) ) {
 			_sons_list.insert( iterFils, node );
 			node->setParent( this );
 			
 			return i+1;
 		}

 		i++;
 		
 	}
 	 //_sons_list.insert( _sons_list.end(), node );
 	_sons_list.push_back( node );
 	node->setParent( this );

 	 return i;
}

template<typename T, class Cmp>
void Node<T,Cmp>::unlinkSon( Node<T,Cmp>* node ) {

	typename
	std::vector< Node<T,Cmp>* >::iterator iterFindNode;
	for ( iterFindNode = _sons_list.begin(); iterFindNode != _sons_list.end() ; iterFindNode++) {
		
		if ( (*iterFindNode) == node ) {
			_sons_list.erase( iterFindNode );
			break;
		}

	}

}


/* May be useless or non pertinent. Used for node deletion */
template<typename T, class Cmp>
int Node<T,Cmp>::getElementPosition( const T& element ) const {

 	int pos = -1;
 	for ( int i=0; i<_elements_list.size(); i++ ) {
 		
 		if ( _elements_list.at(i) == element ) {
 			pos = i;
 		}

 	}

	return pos;
}


template<typename T, class Cmp>
void Node<T,Cmp>::draw(std::ostream &flux) {

	for ( int j=0; j < _elements_list.size(); j++) {
		flux << _elements_list.at(j) << " ";
	}

	flux << std::endl;

	flux << "Nb sons : " << _sons_list.size() << std::endl;

	flux << std::endl;


	//
	for ( int j=0; j < _sons_list.size(); j++) {
		flux << *_sons_list.at(j);
	}
	//
 	

 }

template<typename T, class Cmp>
std::ostream& operator<<( std::ostream& flux, Node<T,Cmp>& n) {
    n.draw(flux) ;
    return flux;
}

template<typename T, class Cmp>
Node<T,Cmp>::~Node() {
	
}