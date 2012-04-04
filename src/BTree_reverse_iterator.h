#ifndef H_REVERSE_ITERATOR_H
	#define H_REVERSE_ITERATOR_H

	#include "BTree_generic_iterator.h"

	template< typename T, class Cmp = std::less<T> >
	class BTree<T,Cmp>::reverse_iterator : public BTree<T,Cmp>::generic_iterator {

		typedef BTree<T,Cmp>::generic_iterator GIterator;

		public:
			reverse_iterator() : generic_iterator() {}
			reverse_iterator( BTree<T,Cmp>* a , bool ended = false ) 
				: generic_iterator(a,ended) {
					
					//this->toRightIndex();
					//_current_index = _current_node.size() - 1;
					this->toFirstElement();
				}

			virtual ~reverse_iterator() {};

			BTree<T,Cmp>::reverse_iterator operator +( int inc ) const {
				
				BTree<T,Cmp>::reverse_iterator ret = (*this);
				for ( int i=0; i<inc && !this->ended(); i++ ) {
				
					ret.next();

				}

				return ret;

			}

			virtual void previous() {
				this->toRight();
			}	

			virtual void next() {
				if ( !this->ended() ) {
					this->toLeft();
				}
			}

			virtual void toFirstElement() {
				GIterator::_current_node = GIterator::_a->getRootNode()->rightmostLeaf();
				GIterator::_current_index = GIterator::_current_node->size() - 1;
			}


	};


#endif