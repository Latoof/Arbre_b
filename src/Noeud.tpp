//#include "Noeud.h"

template<typename T>
Noeud<T>::Noeud() {
	
}

template<typename T>
 void Noeud<T>::addElement( T elt ) {
	this->liste_elements.push_back( elt );
}


template<typename T>
 T Noeud<T>::getElement( int i ) {
	return this->liste_elements.at(i);
}

template<typename T>
std::vector<T> Noeud<T>::getElements() {
	return this->liste_elements;
}

template<typename T>
Noeud<T>::~Noeud() {
	
}