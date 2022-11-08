/*
Tecnologico de Monterrey Campus GDA
Act 4.1 - Grafo
Benjamin Gutierrez Mendoza - A01642356
*/

#include <iostream>
#include "MyGraph.h"

using namespace std;

int main() {
    vector <vector<int>> mat = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 0}
    };
    MyGraph g(mat);
    cout << "Impresioes del grafo" << endl;
    cout << "DFS: ";
    g.DFS(0);
    cout << "BFS: ";
    g.BFS(0);
    return 0;
}

