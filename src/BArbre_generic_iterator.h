#ifndef H_GENERIC_ITERATOR_H
	#define H_GENERIC_ITERATOR_H


	template<typename T>
	class BArbre<T>::generic_iterator {


		protected:

			BArbre<T>* _a;
			Noeud<T>* _current_node;
			int _current_index;

			bool _ended;

		public:

			generic_iterator() : _a(NULL), _current_node(NULL) {}
			generic_iterator( BArbre<T>* a, bool ended = false ) 
				: 
				_a(a), 
				_ended(ended)
				 {
				 	
				 	if ( !_ended ) {
				 		//this->toFirstElement();
				 	}

				 }

			~generic_iterator() {};
			const T& operator *() const { 
				return _current_node->getElements().at(_current_index);
			}


			virtual void next() = 0;
			virtual void previous() = 0;
			virtual void toFirstElement() = 0;


			BArbre<T>::generic_iterator operator +( int inc ) const {
				
				std::cout << "Dbg iter : Inc " << inc << std::endl;

				BArbre<T>::generic_iterator ret = (*this);
				for ( int i=0; i<inc && _current_node != NULL; i++ ) {
				
					ret.next();

				}

				return ret;

			}

			void operator++( int inc ) {
				
				this->next();
				
			}

			void operator--( int inc ) {
				this->previous();
			}

			bool operator<( const BArbre<T>::generic_iterator& itCmp ) {
				return ( _current_node != NULL );	
			}




		protected:

			void toLeft() {
				
				std::cout << "Dbg iter next from " << **this << std::endl;
				

				if ( _current_node->isFeuille() && _current_index > 0  ) {
										
					_current_index--;

				}
				else if ( !_current_node->isFeuille() && _current_index >= 0 ) {
										
					_current_node = _current_node->getFils().at( _current_index )->rightmostLeaf();
					this->toRightIndex();

				}
			
				/* Node finished */
				else {
				
					this->toParentL();

				}


				std::cout << "Dbg iter from next TO " << **this << std::endl;

			}

			void toRight() {
				std::cout << "Dbg iter next from " << **this << std::endl;
				

				if ( _current_node->isFeuille() && _current_index < _current_node->element_count() - 1  ) {
										
					_current_index++;

				}
				else if ( !_current_node->isFeuille() && _current_index < _current_node->element_count() ) {
										
					_current_node = _current_node->getFils().at( _current_index + 1 )->leftmostLeaf();
					_current_index = 0;

				}
			
				/* Node finished */
				else {
				
					this->toParentR();

				}


				std::cout << "Dbg iter from next TO " << **this << std::endl;
			}

			void toParentR() {
				
				if ( _current_node != _a->getRootNode() ) {

					Noeud<T>* parent = _current_node->getParent();
					
					if ( _current_node != parent->getFils().back() ) {
						
						_current_index = parent->getSonPosition( _current_node );
						_current_node = parent;

					}
					else {
						_current_node = parent;
						this->toParentR();
					}

				}
				else {
					std::cout << "Dbg Iter Racine Fini ? \n";
					_ended = true;
				}


			}

			void toParentL() {
				
				if ( _current_node != _a->getRootNode() ) {

					Noeud<T>* parent = _current_node->getParent();
					
					if ( _current_node != parent->getFils().front() ) {
						
						_current_index = parent->getSonPosition( _current_node ) - 1;
						_current_node = parent;

					}
					else {
						_current_node = parent;
						this->toParentL();
					}

				}
				else {
					std::cout << "Dbg Iter Racine Fini ? \n";
					_ended = true;

				}


			}

			void toRightIndex() {
				_current_index = _current_node->size() - 1;
			}

			void toLeftIndex() {
				_current_index = 0;
			}

			bool ended() {
				return _ended;
			}

			//T _elt;
	};

#endif