#ifndef H_GENERIC_ITERATOR_H
	#define H_GENERIC_ITERATOR_H


	template<typename T, class Cmp = std::less<T> >
	class BTree<T,Cmp>::generic_iterator {
		friend class BTree<T,Cmp>;

		public:

			generic_iterator() : _a(NULL), _current_node(NULL) {}

			~generic_iterator() {};

			const T& operator *() const { 
				return _current_node->getElements().at(_current_index);
			}

			bool operator==( const BTree<T,Cmp>::generic_iterator& itCmp ) const {

				if ( _a == itCmp._a ) {
						
					std::cout << "Ended ? --> " << this->ended() << "\n";
					if ( this->ended() ) {
						return ( itCmp.ended() );
					}

					return ( _current_node == itCmp._current_node
							&& _current_index == itCmp._current_index );

				}
				else {
					return false;
				}

	
			}

			bool operator!=( const BTree<T,Cmp>::generic_iterator& itCmp ) const {
				
				return ( ! this->operator==( itCmp ) );

			}

			void operator++( int ba ) {
				
				this->next();
				
			}

			void operator--( int ba ) {
				this->previous();
			}

			bool operator<( const BTree<T,Cmp>::generic_iterator& itCmp ) {
				return ( itCmp.ended() && !this->ended() );
			}


		protected:
			generic_iterator( BTree<T,Cmp>* a, bool ended = false ) 
				: 
				_a(a), 
				_ended(ended)
				 {
				 	
				 	

				 }

			virtual void next() = 0;
			virtual void previous() = 0;
			virtual void toFirstElement() = 0;
			virtual void toEnd() = 0;


			void toParentR() {
				
				if ( _current_node != _a->getRootNode() ) {

					Node<T,Cmp>* parent = _current_node->getParent();
					
					if ( _current_node != parent->getSons().back() ) {
						
						_current_index = parent->getSonPosition( _current_node );
						_current_node = parent;

					}
					else {
						_current_node = parent;
						this->toParentR();
					}

				}
				else {
					std::cout << "Dbg Iter root Fini ? \n";
					_ended = true;
					_current_index++;
				}


			}

			void toParentL() {
				
				if ( _current_node != _a->getRootNode() ) {

					Node<T,Cmp>* parent = _current_node->getParent();
					
					if ( _current_node != parent->getSons().front() ) {
						
						_current_index = parent->getSonPosition( _current_node ) - 1;
						_current_node = parent;

					}
					else {
						_current_node = parent;
						this->toParentL();
					}

				}
				else {
					std::cout << "Dbg Iter root Fini ? \n";
					_ended = true;
					_current_index--;

				}


			}

		protected:

			BTree<T,Cmp>* _a;
			Node<T,Cmp>* _current_node;
			int _current_index;

			bool _ended;



			void toLeft() {
				
				std::cout << "Dbg iter next from " << **this << std::endl;
				

				if ( _current_node->isLeaf() && _current_index > 0  ) {
										
					_current_index--;

				}
				else if ( !_current_node->isLeaf() && _current_index >= 0 ) {
										
					_current_node = _current_node->getSons().at( _current_index )->rightmostLeaf();
					this->toRightIndex();

				}
			
				/* Node finished */
				else {
				
					this->toParentL();

				}


				if ( !_ended) std::cout << "Dbg iter from next TO " << **this << std::endl;

			}

			void toRight() {
				std::cout << "Dbg iter next from " << **this << std::endl;
				

				if ( _current_node->isLeaf() && _current_index < _current_node->size() - 1  ) {
										
					_current_index++;

				}
				else if ( !_current_node->isLeaf() && _current_index < _current_node->size() ) {
										
					_current_node = _current_node->getSons().at( _current_index + 1 )->leftmostLeaf();
					_current_index = 0;

				}
			
				/* Node finished */
				else {
				
					this->toParentR();

				}


				if ( !_ended) std::cout << "Dbg iter from next TO " << **this << std::endl;
			}

			void toRightIndex() {
				_current_index = _current_node->size() - 1;
			}

			void toLeftIndex() {
				_current_index = 0;
			}

			bool ended() const {
				return _ended;
			}

			//T _elt;
	};

#endif