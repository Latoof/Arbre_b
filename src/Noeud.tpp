#include "Noeud.h"

template<typename T>
Noeud<T>::Noeud() {
	
}

template<typename T>
Noeud<T>::Noeud( Noeud<T>* parent ) : _parent(parent) {
	std::cout << "ADD SON" << std::endl;
	//parent->addFils(this);
}

template<typename T>
void Noeud<T>::addElement( T elt ) {

	//template<typename T>
	typename
	std::vector<T>::iterator iterElements;

	int i;
	for ( iterElements = _liste_elements.begin(); iterElements != _liste_elements.end() ; iterElements++ ) {

 		if ( elt < (*iterElements) ) {
 			_liste_elements.insert( iterElements, elt );
 			return;
 		}
 		
 	}
 	 _liste_elements.insert( _liste_elements.end(), elt );

	//_liste_elements.push_back( elt );
}


template<typename T>
 T Noeud<T>::getElement( int i ) {
	return _liste_elements.at(i);
}

template<typename T>
std::vector<T> Noeud<T>::getElements() {
	return _liste_elements;
}

template<typename T>
std::vector< Noeud<T>* > Noeud<T>::getFils() {
	return _liste_fils;
}

template<typename T>
Noeud<T>* Noeud<T>::getParent() {
	return _parent;
}

template<typename T>
bool Noeud<T>::isFeuille() {
	return ( _liste_fils.empty() );
}

template<typename T>
bool Noeud<T>::contains( const T& elt ) {
	if ( !_liste_elements.empty() 
		&& std::find(_liste_elements.begin(), _liste_elements.end(), elt) != _liste_elements.end()) {
		return true;
	} 
	else {
	    return false;
	}
}

template<typename T>
void Noeud<T>::addFils( Noeud<T>* node ) {
	_liste_fils.push_back(node);
}

template<typename T>
void Noeud<T>::delFils( Noeud<T>* node ) {

	typename
	std::vector< Noeud<T>* >::iterator iterFindNode;
	for ( iterFindNode = _liste_fils.begin(); iterFindNode != _liste_fils.end() ; iterFindNode++) {
		
		if ( (*iterFindNode) == node ) {
			_liste_fils.erase( iterFindNode );
			break;
		}

	}

}



template<typename T>
void Noeud<T>::draw(std::ostream &flux) const {

	for ( int j=0; j < _liste_elements.size(); j++) {
		flux << _liste_elements.at(j) << " ";
	}

	flux << std::endl;

	flux << "Nb sons : " << _liste_fils.size() << std::endl;

	flux << std::endl;
 	

 }

template<typename T>
std::ostream &operator<<( std::ostream &flux, Noeud<T> const& n)
{
    n.draw(flux) ;
    return flux;
}


template<typename T>
Noeud<T>::~Noeud() {
	
}