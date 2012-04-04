#ifndef H_ITERATOR_H
	#define H_ITERATOR_H

	#include "BTree_generic_iterator.h"

	template< typename T, class Cmp = std::less<T> >
	class BTree<T,Cmp>::iterator : public BTree<T,Cmp>::generic_iterator {

		typedef BTree<T,Cmp>::generic_iterator GIterator;

		public:
			iterator() : generic_iterator() {}
			iterator( BTree<T,Cmp>* a , bool ended = false ) 
				: generic_iterator(a,ended) {

					this->toFirstElement();
					
				}

			/* to protect */
			iterator( BTree<T,Cmp>* a, Node<T,Cmp>* n, int index ) : generic_iterator(a,false) {
				
				GIterator::_current_node = n;
				GIterator::_current_index = index;

			}


			virtual ~iterator() {};


			BTree<T,Cmp>::iterator operator +( int inc ) const {
				
				BTree<T,Cmp>::iterator ret = (*this);
				for ( int i=0; i<inc && !this->ended(); i++ ) {
				
					ret.next();

				}

				return ret;

			}

			virtual void previous() {
				this->toLeft();
			}

			virtual void next() {
				if ( !this->ended() ) {
					this->toRight();
				}
			}

			virtual void toFirstElement() {
				GIterator::_current_node = GIterator::_a->getRootNode()->leftmostLeaf();
				GIterator::_current_index = 0;
			}

	};

#endif