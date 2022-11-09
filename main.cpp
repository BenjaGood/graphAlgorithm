/*
Tecnologico de Monterrey Campus GDA
Act 4.1 - Grafo
Benjamin Gutierrez Mendoza - A01642356
*/

#include <iostream>
#include "MyGraph.h"

using namespace std;

int main() {
    //Inizializacion de la matriz
    vector <vector<int>> matrixOfPositions = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0}
    };
    //Creacion del objeto en grafo
    MyGraph newGraph(matrixOfPositions);
    cout << "Impresioes del grafo" << endl;
    cout << "En DFS: ";
    //uso de DFS
    newGraph.DFS(0);
    cout << "En BFS: ";
    //uso de BFS
    newGraph.BFS(0);
    return 0;
}

