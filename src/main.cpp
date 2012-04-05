#include "BTree.h"

//#include "BTree_generic_iterator.h"
#include "BTree_iterator.h"
#include "BTree_reverse_iterator.h"


#include <iostream>

int main( int argc, char** argv ) {
	
	//Node<int> n1;
	BTree<int> a(2);


	//BTree<int>::iterator iter1(&a);

	std::cout << "Before adding 4" << std::endl << a << std::endl;


	a.insert( 6	);
	std::cout << "[[[[[[ After adding 6" << std::endl << a << std::endl;


	a.insert( 7 );
	std::cout << "[[[[[[ After adding 7" << std::endl << a << std::endl;

	a.insert( 3 );
	std::cout << "[[[[[[ After adding 3" << std::endl << a << std::endl;



	a.insert( 11 );
	std::cout << "[[[[[[ After adding 11" << std::endl << a << std::endl;

	a.insert( 12 );
	std::cout << "[[[[[[ After adding 12" << std::endl << a << std::endl;


	a.erase( 7 );
	std::cout << "[[[[[[ After deleting 7" << std::endl << a << std::endl;


	a.insert( 7 );
	std::cout << "[[[[[[ After adding 7" << std::endl << a << std::endl;




	a.insert( 8 );
	std::cout << "[[[[[[ After adding 8" << std::endl << a << std::endl;

	a.insert( 10 );
	std::cout << "[[[[[[ After adding 10" << std::endl << a << std::endl;



	a.erase( 11 );
	std::cout << "[[[[[[ After deleting 11" << std::endl << a << std::endl;


		a.insert( 97 );
	std::cout << "[[[[[[ After adding 97" << std::endl << a << std::endl;


	a.insert( 98 );
	std::cout << "[[[[[[ After adding 98" << std::endl << a << std::endl;

	a.insert( 45 );
	std::cout << "[[[[[[ After adding 45" << std::endl << a << std::endl;


	a.insert( 26 );
	std::cout << "[[[[[[ After adding 24" << std::endl << a << std::endl;



	a.insert( 33 );
	std::cout << "[[[[[[ After adding 33" << std::endl << a << std::endl;

	a.insert( 41 );
	std::cout << "[[[[[[ After adding 41" << std::endl << a << std::endl;


	a.insert( 43 );
	std::cout << "[[[[[[ After adding 43" << std::endl << a << std::endl;

	a.insert( 19 );
	std::cout << "[[[[[[ After adding 19" << std::endl << a << std::endl;


	a.insert( 32 );
	std::cout << "[[[[[[ After adding 32" << std::endl << a << std::endl;


	a.insert( 38 );
	std::cout << "[[[[[[ After adding 38" << std::endl << a << std::endl;

	a.insert( 58 );
	std::cout << "[[[[[[ After adding 58" << std::endl << a << std::endl;

	a.insert( 54 );
	std::cout << "[[[[[[ After adding 54" << std::endl << a << std::endl;

	a.insert( 66 );
	std::cout << "[[[[[[ After adding 66" << std::endl << a << std::endl;


	a.insert( 63 );
	std::cout << "[[[[[[ After adding 63" << std::endl << a << std::endl;


			a.erase( 45 );
	std::cout << "[[[[[[ After deleting 45" << std::endl << a << std::endl;



			a.erase( 8 );
	std::cout << "[[[[[[ After deleting 8" << std::endl << a << std::endl;


				a.erase( 58 );
	std::cout << "[[[[[[ After deleting 58" << std::endl << a << std::endl;



		a.erase( 12 );
	std::cout << "[[[[[[ After deleting 12" << std::endl << a << std::endl;


		a.insert( 17 );
	std::cout << "[[[[[[ After adding 17" << std::endl << a << std::endl;

	a.insert( 13 );
	std::cout << "[[[[[[ After adding 13" << std::endl << a << std::endl;


		a.insert( 18 );
	std::cout << "[[[[[[ After adding 18" << std::endl << a << std::endl;


	a.insert( 15 );
	std::cout << "[[[[[[ After adding 15" << std::endl << a << std::endl;


		a.insert( 14 );
	std::cout << "[[[[[[ After adding 14" << std::endl << a << std::endl;

	a.insert( 20 );
	std::cout << "[[[[[[ After adding 20" << std::endl << a << std::endl;


	a.erase( 33 );
		std::cout << "[[[[[[ After deleting 33" << std::endl << a << std::endl;

	a.erase( 26 );
		std::cout << "[[[[[[ After deleting 26" << std::endl << a << std::endl;


		a.insert( 25 );
	std::cout << "[[[[[[ After adding 25" << std::endl << a << std::endl;

	a.insert( 21 );
	std::cout << "[[[[[[ After adding 21" << std::endl << a << std::endl;

	a.insert( 50 );
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

	BTree<int>::iterator itF;
	if ( (itF = a.find(46854) ) != a.end() ) {
		std::cout << "---> FOUND : " << *(itF + 6) << std::endl;
		std::cout << "---> FOUND : " << *(itF) << std::endl;

	}
	else {
		std::cout << "NOT FOUND\n";
	}

	/** **/


	BTree<int*> ap;

	int* i3 = new int(3);
	int* i6 = new int(6);

	int* i78 = new int(78);
	int* i66 = new int(66);
	int* i2 = new int(2);
	int* i40 = new int(40);

	ap.insert(i6);
	ap.insert(i3);
		ap.insert(i78);
	ap.insert(i66);
		ap.insert(i2);
	ap.insert(i40);

	BTree<int*>::iterator itP;

	for ( itP = ap.begin(); itP != ap.end(); itP++) {
		std::cout << "Will print element " << std::endl;
		std::cout << "--> PELT : " << **itP << std::endl;

	}
	
	std::cout << "Finished\n";
	

	return 0;

}
