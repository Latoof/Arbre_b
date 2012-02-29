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
			void addElement( T elt );


			std::vector<T> getElements();

			void addFils( Noeud<T>* node );
			void delFils( Noeud<T>* node );

			std::vector< Noeud<T>* > getFils();
			Noeud<T>* getParent();

			bool contains( const T& elt );
			bool isFeuille();
			void draw(std::ostream &flux) const;
		private:

			std::vector<T> _liste_elements;
			std::vector<Noeud<T>*> _liste_fils;
			Noeud<T>* _parent; // A debattre

			/* data */
		};

	#include "Noeud.tpp"
#endif