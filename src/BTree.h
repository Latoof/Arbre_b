#ifndef H_BTree_H
	#define H_BTree_H

	#include "Node.h"
	#include <vector>
	#include <set>

	/* DEBUG */
	#include <iostream>
	#include <ostream>
	#include <algorithm>
	/* //DEBUG */

	/**
	*
	* \class BTree<T>
	* \author Maxime OUAIRY
	* \brief Conainter class. Store Nodes in a Tree.
	*
	*/
	template<typename T>
	class BTree {
	public:
		/**
		*
		* \brief Make an new empty Tree
		* \param lower Minimum number of Elements per Node
		* \param upper Maximum number of Elements per Node. By default 2 * lower.
		*
		*/
		BTree( int lower = 2, int upper = -1 );

		/**
		*
		* \brief Destroy the entire Tree, and its Nodes.
		*
		*/
		~BTree();

		/**
		*
		* \brief Insert and sort a new element in the Tree
		* \param element Element to be inserted
		*
		*/
		void insertElement( const T& element );

		/**
		*
		* \brief Find and remove an element from the Tree
		* \param element Element to be removed
		* \return 0 if element found and removed, 1 otherwise
		*
		*/
		int removeElement( T element );

		/**
		*
		* \brief Find an element in the Tree
		* \param element Element to find
		* \return The Node containing element if found. NULL pointer otherwise
		*
		*/
		Node<T>* findElementNode( const T& element );

		/**
		*
		* \brief Access to root Node
		* \param element Element to be removed
		* \return The root Node in the Tree
		*
		*/
		Node<T>* getRootNode();

		void draw(std::ostream &flux) const;


		/**
		*
		* \brief Get number of elements in the Tree
		* \return Current number of elements inserted
		*
		*/
		int size() { return _size; }

		/* Iterators */

		class generic_iterator;
		class iterator;
		class reverse_iterator;

		/**
		*
		* \brief Create a new iterator refering to the first element
		* \return An iterator refering to the lower element in the Tree
		*
		*/
		iterator begin() { return iterator( this ); }

		/**
		*
		* \brief Create a new reverse_iterator refering to the last element
		* \return An iterator refering to the higher element in the Tree
		*
		*/
		reverse_iterator rbegin() { return reverse_iterator( this ); }

		/**
		*
		* \brief Create a new iterator refering to end
		* \return An iterator refering to the past-the-end element
		*
		*/
		iterator end() { return iterator( this, true); }

		/**
		*
		* \brief Create a new reverse_iterator refering to end
		* \return An iterator refering to the right before first element
		*
		*/
		reverse_iterator rend() { return reverse_iterator( this, true); }

		iterator root() { return iterator(this,_racine); }

		int _dbg;

	protected:

		/* Operations on nodes */
		void addToNode( Node<T>* node, const T& element );
		int removeFromNode( Node<T>* node, const T& element );

		void mergeNodes( Node<T>* targetNode, Node<T>* sourceNode );
		void splitNode( Node<T>* node );

		void balanceNode( Node<T>* node );


	private:
		int _lower;
		int _upper;
		int _size;
		std::set<Node<T>*> _Nodes; // Essai
		Node<T>* _racine; 

	};

	#include "BTree.tpp"


#endif