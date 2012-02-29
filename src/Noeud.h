#ifndef H_NOEUD_H
	#define H_NOEUD_H

	#include <vector>

	template<typename T>
	class Noeud {
		public:
			Noeud();
			~Noeud();

			T getElement( int i );
			void addElement( T elt );
			std::vector<T> getElements();
			std::vector< Noeud<T>* > getFils() ;
		private:

			std::vector<T> liste_elements;
			std::vector<Noeud<T>*> liste_fils;
			Noeud<T>* pere; // A debattre

			/* data */
		};

	#include "Noeud.tpp"
#endif