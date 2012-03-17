#ifndef H_TESTITER_H
	#define H_TESTITER_H


	template<typename T>
	class BArbre<T>::iterator {
		
		typedef BArbre<T> BarbreG;
		typedef Noeud<T> NoeudG;
		
		public:
			iterator() : _a(NULL), _nodei(NULL) {}
			iterator( BarbreG* a, NoeudG* n ) : _a(a), _nodei(n) {}
			const T& operator *() const { return _nodei->getElements().front(); }
			//T& operator *() { return _nodei->getElements().front(); }

		private:
			BarbreG* _a;
			NoeudG* _nodei;
	};

#endif