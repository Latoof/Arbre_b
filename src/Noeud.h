#ifndef H_NOEUD_H
	#define H_NOEUD_H

	#include <vector>
		#include <iostream>

	#include <algorithm>

	template<typename T>
	class Noeud {

		
		typedef typename std::vector< Noeud<T>* > nodes_ptr_vector ;

		
		typedef typename nodes_ptr_vector::iterator nodes_ptr_iterator ;


		public:
			Noeud();
			Noeud( Noeud<T>* parent );
			~Noeud();

			T getElement( int i );
			int addElement( T elt );
			int delElement( const T& element );


			std::vector<T>& getElements();

			int linkSon( Noeud<T>* node, int index = -1 );
			void unlinkSon( Noeud<T>* node );

			std::vector< Noeud<T>* >& getSons();

			void setParent( Noeud<T>* parent );
			Noeud<T>* getParent();

			bool contains( const T& elt );
			bool isLeaf();
			bool isOverflowing( int size );
			bool isUnderflowing( int min_size );

			/* Useless */
			int getElementPosition( const T& element );

			Noeud<T>* leftmostLeaf();
			Noeud<T>* rightmostLeaf();

			int element_count();
			int getSonPosition( Noeud<T>* son );

			int size();

			void draw(std::ostream &flux) const;
		private:

			std::vector<T> _liste_elements;
			std::vector<Noeud<T>*> _liste_fils;
			Noeud<T>* _parent;

			/* data */
		};

	#include "Noeud.tpp"
#endif