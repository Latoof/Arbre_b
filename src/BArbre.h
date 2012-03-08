#ifndef H_BARBRE_H
	#define H_BARBRE_H

	#include "Noeud.h"
	#include "Racine.h"
	#include <vector>

	/* DEBUG */
	#include <iostream>
	#include <ostream>
	#include <algorithm>
	/* //DEBUG */

	template<typename T>
	class BArbre {
	public:
		BArbre( int lower = 2, int upper = -1 );
		~BArbre();

		void ajouterElement( const T& element );
		int supprimerElement( T element );
		T chercherElement( const T& element );
		Noeud<T>* chercherElementN( const T& element );
		void draw(std::ostream &flux) const;

		std::vector< Noeud<T>* > addToNodeOld( Noeud<T>* node, const T& element );
		std::vector< Noeud<T>* > addToNode( Noeud<T>* node, const T& element );

		std::vector< Noeud<T>* > splitNode( Noeud<T>* node );
		std::vector< Noeud<T>* > balanceNode( Noeud<T>* node );

		int removeFromNode( Noeud<T>* node, const T& element );

	private:
		int _lower;
		int _upper;
		std::vector<Noeud<T>*> _noeuds; // Essai
		Racine<T>* _racine; 

	};

	#include "BArbre.tpp"

#endif