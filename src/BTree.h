#ifndef H_BTree_H
	#define H_BTree_H

	#include "Node.h"
	#include <vector>
	#include <set>

	#include <iostream>
	#include <ostream>
	#include <algorithm>

	/**
	*
	* \class BTree<T,Cmp>
	* \author Maxime OUAIRY
	* \brief Conainter class. Store Nodes in a Tree.
	*
	*/
	template< typename T, class Cmp = std::less<T> >
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
		Node<T,Cmp>* findElementNode( const T& element );

		/**
		*
		* \brief Access to root Node
		* \param element Element to be removed
		* \return The root Node in the Tree
		*
		*/
		Node<T,Cmp>* getRootNode();

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

		iterator root() { return iterator(this,_root); }

		int _dbg;

	protected:

		/* Operations on nodes */
		
		/**
		*
		* \brief Safe element insertion in a Node. Call automatically splitNode when necessary.
		*
		*/
		void addToNode( Node<T,Cmp>* node, const T& element );

		/**
		*
		* \brief Safe element deletion in a Node. Call automatically balanceNode when necessary
		*
		*/
		int removeFromNode( Node<T,Cmp>* node, const T& element );

		/**
		*
		* \brief Merge a source Node in a target Node. SubNodes are also transferred
		* \param targetNode Node which will contains all elements and son of sourceNode
		* \param sourceNode Node which will transfert all sons/elements to bros-node or parent node
		*
		*/
		void mergeNodes( Node<T,Cmp>* targetNode, Node<T,Cmp>* sourceNode );

		/**
		*
		* \brief Split a node in two Nodes. Can be recursive.
		* \param node Node to split.
		*
		*/
		void splitNode( Node<T,Cmp>* node );

		/**
		*
		* \brief Do a local rotation, in order to balance the entire Tree. Recursive.
		* \param node Node to balance.
		*
		*/
		void balanceNode( Node<T,Cmp>* node );


	private:
		/**
		* \attribute _lower Minimum number of Elements per Node
		*/
		int _lower;

		/**
		* \attribute _upper Maximum number of Elements per Node. By default 2 * lower.
		*/
		int _upper;

		/**
		* \attribute _size Element counter
		*/
		int _size;

		/**
		* \attribute _Nodes Contains all Nodes of the Tree
		*/
		std::set<Node<T,Cmp>*> _Nodes;

		/**
		* \attribute _root Pointer to root Node
		*/
		Node<T,Cmp>* _root; 

	};

	#include "BTree.tpp"


#endif