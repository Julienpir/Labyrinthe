#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "Cell.h"

using namespace std ;
class Path{
	public:
		Path(const Cell *c);
		void add_to_path(const Cell *c);
		void set_m_next(Path* p);
		Path* get_m_next();
		const Cell* get_m_c();
	protected:
	const Cell *m_c;
	Path *m_next= NULL;
	Path *last_path=m_next;
	int nb_path=0;
};