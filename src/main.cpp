#include "Node.h"
#include "BTree.h"

//#include "BTree_generic_iterator.h"
#include "BTree_iterator.h"
#include "BTree_reverse_iterator.h"


#include <iostream>

int main( int argc, char** argv ) {
	
	BTree<int> a(2);


	std::cout << "Before adding 4" << std::endl << a << std::endl;


	a.insertElement( 6	);
	std::cout << "[[[[[[ After adding 6" << std::endl << a << std::endl;


	a.insertElement( 7 );
	std::cout << "[[[[[[ After adding 7" << std::endl << a << std::endl;

	a.insertElement( 3 );
	std::cout << "[[[[[[ After adding 3" << std::endl << a << std::endl;



	a.insertElement( 11 );
	std::cout << "[[[[[[ After adding 11" << std::endl << a << std::endl;

	a.insertElement( 12 );
	std::cout << "[[[[[[ After adding 12" << std::endl << a << std::endl;


	a.removeElement( 7 );
	std::cout << "[[[[[[ After deleting 7" << std::endl << a << std::endl;


	a.insertElement( 7 );
	std::cout << "[[[[[[ After adding 7" << std::endl << a << std::endl;




	a.insertElement( 8 );
	std::cout << "[[[[[[ After adding 8" << std::endl << a << std::endl;

	a.insertElement( 10 );
	std::cout << "[[[[[[ After adding 10" << std::endl << a << std::endl;



	a.removeElement( 11 );
	std::cout << "[[[[[[ After deleting 11" << std::endl << a << std::endl;


		a.insertElement( 97 );
	std::cout << "[[[[[[ After adding 97" << std::endl << a << std::endl;


	a.insertElement( 98 );
	std::cout << "[[[[[[ After adding 98" << std::endl << a << std::endl;

	a.insertElement( 45 );
	std::cout << "[[[[[[ After adding 45" << std::endl << a << std::endl;


	a.insertElement( 26 );
	std::cout << "[[[[[[ After adding 24" << std::endl << a << std::endl;



	a.insertElement( 33 );
	std::cout << "[[[[[[ After adding 33" << std::endl << a << std::endl;

	a.insertElement( 41 );
	std::cout << "[[[[[[ After adding 41" << std::endl << a << std::endl;


	a.insertElement( 43 );
	std::cout << "[[[[[[ After adding 43" << std::endl << a << std::endl;

	a.insertElement( 19 );
	std::cout << "[[[[[[ After adding 19" << std::endl << a << std::endl;


	a.insertElement( 32 );
	std::cout << "[[[[[[ After adding 32" << std::endl << a << std::endl;


	a.insertElement( 38 );
	std::cout << "[[[[[[ After adding 38" << std::endl << a << std::endl;

	a.insertElement( 58 );
	std::cout << "[[[[[[ After adding 58" << std::endl << a << std::endl;

	a.insertElement( 54 );
	std::cout << "[[[[[[ After adding 54" << std::endl << a << std::endl;

	a.insertElement( 66 );
	std::cout << "[[[[[[ After adding 66" << std::endl << a << std::endl;


	a.insertElement( 63 );
	std::cout << "[[[[[[ After adding 63" << std::endl << a << std::endl;


			a.removeElement( 45 );
	std::cout << "[[[[[[ After deleting 45" << std::endl << a << std::endl;



			a.removeElement( 8 );
	std::cout << "[[[[[[ After deleting 8" << std::endl << a << std::endl;


				a.removeElement( 58 );
	std::cout << "[[[[[[ After deleting 58" << std::endl << a << std::endl;



		a.removeElement( 12 );
	std::cout << "[[[[[[ After deleting 12" << std::endl << a << std::endl;


		a.insertElement( 17 );
	std::cout << "[[[[[[ After adding 17" << std::endl << a << std::endl;

	a.insertElement( 13 );
	std::cout << "[[[[[[ After adding 13" << std::endl << a << std::endl;


		a.insertElement( 18 );
	std::cout << "[[[[[[ After adding 18" << std::endl << a << std::endl;


	a.insertElement( 15 );
	std::cout << "[[[[[[ After adding 15" << std::endl << a << std::endl;


		a.insertElement( 14 );
	std::cout << "[[[[[[ After adding 14" << std::endl << a << std::endl;

	a.insertElement( 20 );
	std::cout << "[[[[[[ After adding 20" << std::endl << a << std::endl;


	a.removeElement( 33 );
		std::cout << "[[[[[[ After deleting 33" << std::endl << a << std::endl;

	a.removeElement( 26 );
		std::cout << "[[[[[[ After deleting 26" << std::endl << a << std::endl;


		a.insertElement( 25 );
	std::cout << "[[[[[[ After adding 25" << std::endl << a << std::endl;

	a.insertElement( 21 );
	std::cout << "[[[[[[ After adding 21" << std::endl << a << std::endl;

	a.insertElement( 50 );
	std::cout << "[[[[[[ After adding  50" << std::endl << a << std::endl;




	BTree<int>::iterator iterTree;
	iterTree = a.begin();

	std::cout << "Iterator initialized\n";

	int elt = *iterTree;

	std::cout << "Dbg noob\n";
	std::cout << "\33[34m " << a._dbg << " Size : " << a.size() << "\33[0m" << std::endl;
	std::cout << "Elt : " << elt << "  " << *iterTree << std::endl;

	
	for (int i=0; i<22; i++) {
		iterTree++;
		std::cout << "--> ELT : " << *iterTree << std::endl;

	}

	for (int i=0; i<22; i++) {
		iterTree--;
		std::cout << "--> ELT : " << *iterTree << std::endl;

	}

	std::cout << "REVERSE\n";

	BTree<int>::reverse_iterator riterTree;
	riterTree = a.rbegin();

	for (int i=0; i<22; i++) {
		riterTree++;
		std::cout << "--> ELT : " << *riterTree << std::endl;

	}

	std::cout << "------ EEND\n";
	BTree<int>::iterator it;
	BTree<int>::iterator itEnd = a.end();

/** **/
	for ( it = a.begin(); it != itEnd; it++) {
		std::cout << "Will print element " << std::endl;
		std::cout << "--> ELT : " << *it << std::endl;

	}


	/** **/

		BTree<int>::reverse_iterator itR;
	BTree<int>::reverse_iterator itREnd = a.rend();

/** **/
	for ( itR = a.rbegin(); itR != a.rend(); itR++) {
		std::cout << "Will print R element " << std::endl;
		std::cout << "--> ELT : " << *itR << std::endl;

	}


	/** **/

	return 0;

}
