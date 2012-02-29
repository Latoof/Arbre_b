#include "Noeud.h"
#include "Racine.h"
#include <vector>

template<typename T>
class BArbre {
public:
	BArbre();
	~BArbre();

	void ajouterElement( T element );
	int supprimerElement( T element );
	T chercherElement( T element );

private:
	std::vector<Noeud<T>*> noeuds; // Essai
	Racine<T>* racine; 
};