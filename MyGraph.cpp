#include "MyGraph.h"
#include <iostream>
#include <vector>

//Complejidad O(n^2)
MyGraph::MyGraph(std::vector<std::vector<int>>& mat) {
    load(mat);
}

//Complejidad O(n^2)
void MyGraph::load(std::vector<std::vector<int>>& mat) {
    this->mat = mat;
    numVertices = mat.size();
    numEdges = 0;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (mat[i][j] == 1) {
                numEdges++;
            }
        }
    }
    numEdges /= 2;
}

//Complejidad O(n^2) 
void MyGraph::DFS() {
    std::vector<bool> visited(numVertices, false);
    std::vector<int> stack;
    stack.push_back(0);
    while (!stack.empty()) {
        int v = stack.back();
        stack.pop_back();
        if (!visited[v]) {
            visited[v] = true;
            std::cout << v << " ";
            for (int i = numVertices - 1; i >= 0; i--) {
                if (mat[v][i] == 1 && !visited[i]) {
                    stack.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}

//Complejidad O(m+n) 
void MyGraph::BFS() {
    std::vector<bool> visited(numVertices, false);
    std::vector<int> queue;
    queue.push_back(0);
    while (!queue.empty()) {
        int v = queue.front();
        queue.erase(queue.begin());
        if (!visited[v]) {
            visited[v] = true;
            std::cout << v << " ";
            for (int i = 0; i < numVertices; i++) {
                if (mat[v][i] == 1 && !visited[i]) {
                    queue.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}