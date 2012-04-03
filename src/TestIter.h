#ifndef H_TESTITER_H
	#define H_TESTITER_H


	template<typename T>
	class BArbre<T>::iterator {
		
		typedef BArbre<T> BarbreG;
		typedef Noeud<T> NoeudG;
		
		public:
			iterator() : _a(NULL), _nodei(NULL) {}
			iterator( BarbreG* a, NoeudG* n ) 
				: _a(a), _nodei(n), _elt( n->getElements().front()), _current_elt_pos(0) {}
			const T& operator *() const { return _elt; }
			void operator++( int i ) { 
				
				if ( _current_elt_pos + 1 < _nodei->element_count() ) {
					_current_elt_pos++;
					_elt = _nodei->getElements().at(_current_elt_pos);
				}
				else {
					_nodei = _nodei->getFils().front();
					_current_elt_pos = 0;
					_elt = _nodei->getElements().front();
				}
					
			}
			//T& operator *() { return _nodei->getElements().front(); }

		private:
			BarbreG* _a;
			NoeudG* _nodei;
			T _elt;
			int _current_elt_pos;
	};

#endif