#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "Cell.h"

using namespace std ;


/**
* \class 	Path
* \author 	Piranda Julien, Pineau Paul
* \brief 	Classe permettant d'enregistrer un chemin de cellules en cellules
* \date 	24 nov 2019
*/

class Path{
	public:
		/**
 		* \brief	Initialise un chemin élémentaire entre la cellule courante et une cellule voisine
 		* \param	*c	Pointeur vers la cellule courante
 		*/
		Path(const Cell *c);

		/**
 		* \brief	Permet d'ajouter une cellule voisine pour le chemin élémentaire
 		* \param	*c	Pointeur vers la cellule voisine
 		* \return	Ne retourne rien
 		*/
		void add_to_path(const Cell *c);
 		
 		~Path();

 		/**
 		* \brief	Permet d'accéder à la cellule suivante du chemin
 		* \param	*p	Pointeur vers le chemon
 		* \return	Ne retourne rien
 		*/
		void set_m_next(Path* p);
		Path* get_m_next();
		const Cell* get_m_c();

	protected:

		const Cell *m_c;
		Path *m_next= NULL;
		Path *last_path=m_next;
		int nb_path=0;
};