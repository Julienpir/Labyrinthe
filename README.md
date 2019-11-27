# Décoouverte du langage C++

Robotique/UE 3.1  Septembre 2019

Supports de cours disponibles sur
www.simon-rohou.fr/cours/c++



# Objectif du projet:

 L'objetif de se projet est de créer un labyrinthe et de trouver le chemin entre un point de départ et d'arrivé. Il faudra aussi veiller à l'affichage du labyrinthe, créer des dossiers permettant de ecrire et lire le labyrinthe. 

Plus de détails dans les tds disponibles sur www.simon-rohou.fr/cours/c++


# Modélisation

Les  murs  du  labyrinthe  étudié  sont  sans  épaisseur.    
On choisit donc une représentation par graphe plutôt que parmatrice (ou double tableau).  
Chaque nœud du graphe correspond à une cellule du labyrinthe, i.e.une case carrée de côté 1.  
Les connexions entre les cellules sont matérialisées par des arcs entre les nœuds.
Un labyrinthe se définit par:
–  un graphe non orienté de cellules
–  une cellule de départ
–  une cellule d’arrivée

Le chemin entre la cellule de départ et celle d’arrivée est matérialisé par une liste chaînée de cellules à parcourir.


# Pré-requis

_ vibes.cpp: s'occupant de l'affichage

_ Cell.cpp: s'occupant de la définition des cellules du labyrinthe

_ Path.cpp: s'occupant d'implémenter une liste chaînée de pointeurs sur des objets Cell

_ main.cpp: s'occupant de regrouper toutes les classes


# Auteurs 

Paul PINEAU
Julien PIRANDA








