#ifndef H_Node_H
	#define H_Node_H

	#include <vector>
		#include <iostream>

	#include <algorithm>

	template<typename T>
	class Node {

		
		typedef typename std::vector< Node<T>* > nodes_ptr_vector ;

		
		typedef typename nodes_ptr_vector::iterator nodes_ptr_iterator ;


		public:
			Node();
			Node( Node<T>* parent );
			~Node();

			T getElement( int i );
			int addElement( T elt );
			int delElement( const T& element );


			int linkSon( Node<T>* node, int index = -1 );
			void unlinkSon( Node<T>* node );

			std::vector< Node<T>* >& getSons();
			std::vector<T>& getElements();

			Node<T>* getParent();

			Node<T>* leftmostLeaf();
			Node<T>* rightmostLeaf();

			int getElementPosition( const T& element ) const;
			int getSonPosition( const Node<T>* son );

			bool contains( const T& elt ) const;
			bool isLeaf() const;
			bool isOverflowing( int size ) const;
			bool isUnderflowing( int min_size ) const;

			void draw(std::ostream &flux);

			int size() const;


		private:

			void setParent( Node<T>* parent );


			std::vector<T> _liste_elements;
			std::vector<Node<T>*> _liste_fils;
			Node<T>* _parent;

			/* data */
		};

	#include "Node.tpp"
#endif