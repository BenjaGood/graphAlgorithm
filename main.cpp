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
        {0, 1, 0, 0}, 
        {0, 0, 1, 0}, 
        {1, 0, 0, 1}, 
        {0, 1, 0, 0}
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
    newGraph.loadGraph();
    //verificar si es un arbol
    if(newGraph.isTree()){
        cout << "El grafo es un arbol" << endl;
    }else{
        cout << "El grafo no es un arbol" << endl;
    }
    //ordenamiento topologico
    newGraph.topologicalSort();
    //verificar si es bipartito
    if(newGraph.bipartiteGraph()){
        cout << "El grafo es bipartito" << endl;
        cout << "el grafo esta en 0 y 1" << endl;
    }else{
        cout << "El grafo no es bipartito" << endl;
    }

    return 0;
}

