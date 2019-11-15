#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>

using namespace std ;

#include <fstream>

 class Cell{
 public:
 	Cell(int x, int y );
 	void add_neighb(Cell *c, int k=0);
 	void add_neighb(Cell *c1, Cell *c2, int k=0);


 	friend ofstream& operator<<(ofstream& stream, const Cell& c);
 	//friend istream& operator>>(istream& stream, Cell& r);


 	int m_nb_neighb=0;
 	Cell **m_neighb=nullptr;
 	int m_x;
 	int m_y;
 	bool m_displayed = false;
 	bool deja_vu = false;
 };

