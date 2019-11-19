#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "vibes.h"
//#include "Cell.h"
#include "Path.h"

#include <unistd.h>
using namespace std;


#include <fstream>
#include <sstream>


struct Maze{
	
	Cell *c_init;
	Cell *c_end;
};
	
	Maze create_maze(){
		Cell *Content[4][4];

		for(int i=0 ; i<4; i++){
			for(int k=0;k<4;k++){
				Cell *c;
				c = new Cell(i,k);
				Content[i][k] = c;
			}
		}

		Content[0][0]->add_neighb(Content[0][1],Content[1][0]);
		Content[0][1]->add_neighb(Content[1][1]);
		Content[1][0]->add_neighb(Content[2][0]);
		Content[1][1]->add_neighb(Content[2][1],Content[1][2]);
		Content[2][1]->add_neighb(Content[2][2]);
		Content[0][2]->add_neighb(Content[1][2],Content[0][3]);


		Maze graph;
		graph.c_init = Content[0][0];
		graph.c_end  = Content[0][1];
		return graph;
		




	}




	void draw_gate(const Cell *n1, const Cell *n2){
	vibes::drawBox(min(n1->m_x, n2->m_x) + 0.1, max(n1->m_x, n2->m_x) + 0.9,min(n1->m_y, n2->m_y) + 0.1, max(n1->m_y, n2->m_y) + 0.9,"lightGray[lightGray]");
	}


	void display_cell(Cell *cell){

	vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[Black]");
	cell->m_displayed = true;
	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		if(!cell->m_neighb[i]->m_displayed)
		display_cell(cell->m_neighb[i]);
		draw_gate(cell, cell->m_neighb[i]);
	}
	}

	void display_cell_extrem(Cell *cell){

	vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[Blue]");
	cell->m_displayed = true;
	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		if(!cell->m_neighb[i]->m_displayed)
		display_cell_extrem(cell->m_neighb[i]);
		draw_gate(cell, cell->m_neighb[i]);
	}
	}

	void display(const Maze& m){
		display_cell(m.c_init);
		display_cell_extrem(m.c_init);
		display_cell_extrem(m.c_end);
	}

	


// fin class Maze


//Maintenant on gère les fonctions externe pour le path
void find_path(Cell *c,Cell *cf,Path *p){
	
}



/*
// je redéfinie les fonction de dessin propres au path.

void draw_gate(const Cell *n1, const Cell *n2){
	vibes::drawBox(min(n1->m_x, n2->m_x) + 0.1, max(n1->m_x, n2->m_x) + 0.9,min(n1->m_y, n2->m_y) + 0.1, max(n1->m_y, n2->m_y) + 0.9,"lightGray[lightGray]");
	}


void display_cell_path(Cell *cell){

vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[Green]");
cell->m_displayed = true;
for(int i = 0 ; i < cell->m_nb_neighb ; i++)
{
	if(!cell->m_neighb[i]->m_displayed)
	display_cell_path(cell->m_neighb[i]);
	draw_gate(cell, cell->m_neighb[i]);
}
}

// fonction qui permet de dessiner le chemin.
void draw_path(Path *p){
	Path *actual_Path=p;
	//const Cell *actual_Cell= p.get_m_c();
	while(actual_Path->get_m_next()!=NULL){
		display_cell_path((Cell*)actual_Path->get_m_c());
		actual_Path=actual_Path->get_m_next();
	}
	display_cell_path((Cell*)actual_Path->get_m_c());
}
*/


void save_cell(Cell *cell,ofstream& f){

	cell->deja_vu = true;
	f << *cell;
	int n = cell->m_nb_neighb;
	f << n;
	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		f << *cell->m_neighb[i];

	}
	f << endl;
	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		if(!cell->m_neighb[i]->deja_vu){
		save_cell(cell->m_neighb[i],f);
		
			}

		
	}

}




void save_maze(const Maze& maze, const string& file_name)
{



ofstream f(file_name); // tentative d’ouverture (constructeur)

if(!f.is_open())

	cout << "Erreur d’ouverture de " << file_name << endl;

else{


f << "#Start:" << endl;
f << *maze.c_init <<  endl;
f << "#faim:" << endl;
f << *maze.c_end << endl;
f << "Cells:" << endl;

save_cell(maze.c_init,f);



}
f.close(); // fermeture du fichier

}



Maze read_maze(const string& file_name){

string filename = "laby4x4.txt";
int i = 0;
int j = 0;
Maze graph;
//graph.c_init = Content[0][0];
//graph.c_end  = Content[0][1];
ifstream f(filename); // tentative d’ouverture (constructeur)
if(!f.is_open())
	cout << "Erreur d’ouverture de " << filename << endl;
else{
	string ligne; //Une variable pour stocker les lignes lues
	while(getline(f, ligne)){
		if (i == 1){
			
       		//graph.c_init = new Cell(x,y);
    		i = 0;

    	}
    	if (ligne.find("Start") != string::npos)
    		i = 1;
    	


}
f.close(); 
// fermeture du fichier // fermeture du fichier

}
}




int main(){
	vibes::beginDrawing();
	vibes::newFigure("Jam");
	vibes::setFigureProperties("Jam",vibesParams("x", 100, "y", 100, "width", 400, "height", 400));
	vibes::axisLimits(-0.5, 4.5, -0.5, 4.5);
	

	Maze M;
	M = create_maze();
	// on affiche le Maze;
	//display(M);
	//save_maze(M, "Trustttt.txt");
	read_maze("o");

/*
	string filename = "laby4x4.txt";
ifstream f(filename);


if(!f.is_open())
cout << "Erreur d’ouverture de " << filename << endl;

else{

float a; int b;f >> a >> b; // lecture de variables depuis le flux
string str;
getline(f, str); // lecture d’une ligne complète

}

f.close(); // fermeture du fichier 
*/


	//chemin à suivre pour vérifier si tout marche.
	//path.add_to_path(&M.Content[1]);
	//path.add_to_path(&M.Content[2]);
	//path.add_to_path(&M.Content[3]);
	//path.add_to_path(&M.Content[7]);
	//path.add_to_path(&M.Content[11]);
	//path.add_to_path(&M.Content[15]);
	//path.add_to_path(&M.Content[14]);
	//path.add_to_path(&M.Content[10]);
	//path.add_to_path(&M.Content[9]);
	//path.add_to_path(&M.Content[13]);
	//path.add_to_path(&M.Content[12]);
	//path.add_to_path(&M.Content[8]);
	//path.add_to_path(&M.Content[4]);

	
	
	//draw_path(&path);
	
}




