#ifndef H_REVERSE_ITERATOR_H
	#define H_REVERSE_ITERATOR_H

	#include "BArbre_generic_iterator.h"

	template<typename T>
	class BArbre<T>::reverse_iterator : public BArbre<T>::generic_iterator {

		typedef BArbre<T>::generic_iterator GIterator;

		public:
			reverse_iterator() : generic_iterator() {}
			reverse_iterator( BArbre<T>* a , bool ended = false ) 
				: generic_iterator(a,ended) {
					
					//this->toRightIndex();
					//_current_index = _current_node.size() - 1;
					this->toFirstElement();
				}

			virtual ~reverse_iterator() {};

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