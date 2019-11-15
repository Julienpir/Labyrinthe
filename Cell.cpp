#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "Cell.h"
using namespace std ;

#include <fstream>



void Cell::add_neighb(Cell *c,int k){

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

void Cell::add_neighb(Cell *c1,Cell *c2,int k){
	this->add_neighb(c1);
	this->add_neighb(c2);

}


Cell::Cell(int x, int y){
	m_x=x;
	m_y=y;
}

ostream& operator<<(ostream& stream, const Cell& c)
{
stream << "ok pute" << endl;
//stream << "("<< c.m_x << "," << c.m_y << ")" << endl ;

return stream;
}