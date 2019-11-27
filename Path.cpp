#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "Path.h"
using namespace std ;


Path::Path(const Cell*c){
	m_c=c;
}

void Path::add_to_path(const Cell*c){
	if(m_next==NULL){
		m_next=new Path(c);
		last_path=m_next;
		
	}
	else{
		last_path->m_next=new Path(c);
		last_path=last_path->m_next;
	}
	
	
}

const Cell* Path::get_m_c(){
	return(m_c);
}

Path* Path::get_m_next(){
	return(m_next);
}

Path::~Path() // destructeur
{
	delete m_c;
	delete m_next;
}