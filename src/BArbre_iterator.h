#ifndef H_ITERATOR_H
	#define H_ITERATOR_H

	#include "BArbre_generic_iterator.h"

	template<typename T>
	class BArbre<T>::iterator : public BArbre<T>::generic_iterator {

		public:
			iterator() : generic_iterator() {}
			iterator( BArbre<T>* a , bool ended = false ) 
				: generic_iterator(a,ended) {
					
					//this->toLeftIndex();
					//_current_index = 0;
					
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
				_current_node = _a->getRoot()->leftmostLeaf();
				_current_index = 0;
			}




	};

#endif