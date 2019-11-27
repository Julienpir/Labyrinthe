#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>

using namespace std ;

#include <fstream>


/**
* \class 	Cell
* \author 	Piranda Julien, Pineau Paul
* \brief 	Classe implémentant l'objet cellule
* \date 	27 nov 2019
*/


 class Cell{
 public:
 	/**
 		* \brief	Initialise une cellule via ses coordonnées
 		* \param	x	Abscisse
 		* \param	y	Ordonnée
 		*/

 	Cell(int x, int y );
 	/**
 		* \brief	Permet d'ajouter un voisin à la cellule courante
 		* \details	Par double appel de la méthode set_neighb pour ajouter les voisins symétriquement
 		* \param	*c	Pointeur vers la cellule voisine
 		* \return	Ne retourne rien
 		*/

 	void add_neighb(Cell *c, int k=0);
 	/**
 		* \brief	Permet d'ajouter deux voisins 
 		* \details	Par double appel de la méthode add_neighb(Cell *c)
 		* \param	*c1	Pointeur vers la première cellule voisine
 		* \param	*c2	Pointeur vers la seconde cellule voisine
 		* \return	Ne retourne rien
 		*/
 	void add_neighb(Cell *c1, Cell *c2, int k=0);
	/**
 		* \brief	Ajoute une cellule voisine au tableau de pointeurs des voisins
 		* \param	*c	Pointeur vers la cellule voisine
 		* \return	Ne retourne rien
 		*/

 	friend ofstream& operator<<(ofstream& stream, const Cell& c);//surcharge le flux d'écriture
 	//friend istream& operator>>(istream& stream, Cell& r);


 	int m_nb_neighb=0;
 	Cell **m_neighb=nullptr;
 	int m_x;
 	int m_y;
 	bool m_displayed = false;
 	bool deja_vu = false;
 };

