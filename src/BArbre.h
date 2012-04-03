#ifndef H_BARBRE_H
	#define H_BARBRE_H

	#include "Noeud.h"
	#include <vector>
	#include <set>

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

		std::vector< Noeud<T>* > addToNode( Noeud<T>* node, const T& element );

		std::vector< Noeud<T>* > splitNode( Noeud<T>* node );
		std::vector< Noeud<T>* > balanceNode( Noeud<T>* node );
		void mergeNodes( Noeud<T>* targetNode, Noeud<T>* sourceNode );

		int removeFromNode( Noeud<T>* node, const T& element );
		int size() { return _size; }

		Noeud<T>* getRootNode();

		class generic_iterator;
		class iterator;
		class reverse_iterator;

		iterator begin() { return iterator( this ); }
		reverse_iterator rbegin() { return reverse_iterator( this ); }

		iterator end() { return iterator( this, true); }
		reverse_iterator rend() { return reverse_iterator( this, true); }

		iterator root() { return iterator(this,_racine); }


		int _dbg;

	protected:


	private:
		int _lower;
		int _upper;
		int _size;
		std::set<Noeud<T>*> _noeuds; // Essai
		Noeud<T>* _racine; 

	};

	#include "BArbre.tpp"

	//#include "BArbre_generic_iterator.h"

/*
	#include "BArbre_iterator.h"
	#include "BArbre_reverse_iterator.h"
*/



#endif