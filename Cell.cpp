#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "Cell.h"
using namespace std ;

#include <fstream>



void Cell::add_neighb(Cell *c,int k){ // permet de rajouter une cellule au tableau des voisins

	if(k<=1){
		if (m_nb_neighb==0){
			m_nb_neighb+=1;
			m_neighb=new Cell* [m_nb_neighb];
			m_neighb[0]=c;
		}
		else{

		
		m_nb_neighb+=1;
		Cell **tab_intermed=new Cell* [m_nb_neighb];
		for (int i=0; i<m_nb_neighb-1; i++) tab_intermed[i]=m_neighb[i];
		delete [] m_neighb;
		tab_intermed[m_nb_neighb-1]=c;
		m_neighb=tab_intermed;
		}
	k+=1;
	c->add_neighb(this,k);
	}

}

void Cell::add_neighb(Cell *c1,Cell *c2,int k){ // permet de rajouter 2 cellules au tableau des voisins

	this->add_neighb(c1);
	this->add_neighb(c2);

}


Cell::Cell(int x, int y){ // création d'un objet "cellule"
	m_x = x;
	m_y = y;
}

ofstream& operator<<(ofstream& stream, const Cell& c) // pour l'écriture des celules dans des fichiers
{

stream << "("<< c.m_x << "," << c.m_y << ")" ;
return stream;
}