#ifndef H_Node_H
	#define H_Node_H

	#include <vector>
	#include <iostream>
	#include <algorithm>

	/**
	*
	* \class Node<T,Cmp>
	* \author Maxime OUAIRY
	* \brief BTree Node. Contains Elements/Keys
	*
	*/
	template< typename T, class Cmp = std::less<T> >
	class Node {

		
		typedef typename std::vector< Node<T,Cmp>* > nodes_ptr_vector ;

		
		typedef typename nodes_ptr_vector::iterator nodes_ptr_iterator ;


		public:
			/**
			*
			* \brief Make an new empty Node
			*
			*/
			Node();
			~Node();

			/**
			*
			* \brief Add an element to the Node (not safe)
			* \param element Element to insert in the Node
			* \returns Index of inserted element 
			*
			*/
			int addElement( T element );

			/**
			*
			* \brief Remove an element from the Node (not safe)
			* \param element Element to delete from the Node
			* \returns Old index of deleted element, if found. -1 otherwise
			*
			*/
			int delElement( const T& element );

			/**
			*
			* \brief Add a Node as son
			* \param node Future son Node
			* \returns Index of inserted son 
			*
			*/
			int linkSon( Node<T,Cmp>* node );

			/**
			*
			* \brief Unlink a son Node from this one
			* \param node Son Node to unlink
			*
			*/
			void unlinkSon( Node<T,Cmp>* node );

			/**
			*
			* \brief Get a list of sons Nodes
			* \returns A vector reference of sons list
			*
			*/
			std::vector< Node<T,Cmp>* >& getSons();

			/**
			*
			* \brief Get a list of elements
			* \returns A vector reference of elements list
			*
			*/
			std::vector<T>& getElements();

			/**
			*
			* \brief Get parent node.
			* \returns A pointer to parent Node. NULL if Root.
			*
			*/
			Node<T,Cmp>* getParent();

			/**
			*
			* \brief Get the leftmost leaf from this node
			* \returns A pointer to leftmost leaf node
			*
			*/
			Node<T,Cmp>* leftmostLeaf();

			/**
			*
			* \brief Get the rightmost leaf from this node
			* \returns A pointer to rightmost leaf node
			*
			*/
			Node<T,Cmp>* rightmostLeaf();

			/**
			*
			* \brief Get an element position in the element list
			* \param element Reference to the element to locate
			* \returns Index of element in list. -1 otherwise 
			*
			*/
			int getElementPosition( const T& element ) const;

			/**
			*
			* \brief Get an son node position in the son node list
			* \param son Reference to the element to son node
			* \returns Index of son node in list. -1 otherwise 
			*
			*/
			int getSonPosition( const Node<T,Cmp>* son );

			/**
			*
			* \brief Detect if node size exceeds the limit
			* \param max_size Maximum node size
			* \returns true if node size exceeds max_size. false otherwise
			*
			*/
			bool isOverflowing( int max_size ) const;

			/**
			*
			* \brief Detect if node size deceeds the limit
			* \param min_size Minimum node size
			* \returns true if node size deceeds max_size. false otherwise
			*
			*/
			bool isUnderflowing( int min_size ) const;

			/**
			*
			* \brief Search for an element
			* \param element Reference to searched element
			* \returns true if element is in this node, false otherwise
			*
			*/
			bool contains( const T& element ) const;

			/**
			*
			* \brief Detect if node is a leaf
			* \param element Reference to searched element
			* \returns true if element is in this node, false otherwise
			*
			*/
			bool isLeaf() const;


			void draw(std::ostream &flux);

			/**
			*
			* \brief Get number of elements in the Node
			* \returns Current number of elements inserted
			*
			*/
			int size() const;


		private:

			/**
			*
			* \brief Set a node as parent
			* \param parent Node to set as parent
			*
			*/
			void setParent( Node<T,Cmp>* parent );

			/**
			* \attribute _elements_list Contains all elements of the Node
			*/
			std::vector<T> _elements_list;

			/**
			* \attribute _sons_list Contains pointers of all sons nodes of this Node
			*/
			std::vector<Node<T,Cmp>*> _sons_list;

			/**
			* \attribute _parent Parent of this Node.
			*/
			Node<T,Cmp>* _parent;

		};

	#include "Node.tpp"
#endif