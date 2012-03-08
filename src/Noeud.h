#ifndef H_NOEUD_H
	#define H_NOEUD_H

	#include <vector>
		#include <iostream>

	#include <algorithm>

	template<typename T>
	class Noeud {
		public:
			Noeud();
			Noeud( Noeud<T>* parent );
			~Noeud();

			T getElement( int i );
			int addElement( T elt );
			int delElement( const T& element );


			std::vector<T> getElements();

			int addFils( Noeud<T>* node, int index = -1 );
			void delFils( Noeud<T>* node );

			std::vector< Noeud<T>* > getFils();

			void setParent( Noeud<T>* parent );
			Noeud<T>* getParent();

			bool contains( const T& elt );
			bool isFeuille();
			bool isOverflowing( int size );
			bool isUnderflowing( int min_size );

			/* Useless */
			int getElementPosition( const T& element );

			void draw(std::ostream &flux) const;
		private:

			std::vector<T> _liste_elements;
			std::vector<Noeud<T>*> _liste_fils;
			Noeud<T>* _parent; // A debattre

			/* data */
		};

	#include "Noeud.tpp"
#endif