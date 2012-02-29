#ifndef H_RACINE_H
	#define H_RACINE_H

	#include "Noeud.h"
	#include <iostream>
	#include <vector>

	template<typename T>
	class Racine : public Noeud<T> {
		public:
			Racine();
			~Racine();

			/* data */
		};

		#include "Racine.tpp"

#endif