#ifndef H_ITERATOR_H
	#define H_ITERATOR_H

	#include "BArbre_generic_iterator.h"

	template<typename T>
	class BArbre<T>::iterator : public BArbre<T>::generic_iterator {

		typedef BArbre<T>::generic_iterator GIterator;

		public:
			iterator() : generic_iterator() {}
			iterator( BArbre<T>* a , bool ended = false ) 
				: generic_iterator(a,ended) {
					
					//this->toLeftIndex();
					//_current_index = 0;
					this->toFirstElement();
					
				}


			virtual ~iterator() {};


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