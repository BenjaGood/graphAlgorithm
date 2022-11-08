#include "MyGraph.h"
#include <iostream>
#include <vector>

//Complejidad O(n^2)
MyGraph::MyGraph(std::vector<std::vector<int>>& vecOfInt){
    load(vecOfInt);
}

//Complejidad O(n^2)
void MyGraph::load(std::vector<std::vector<int>>& vecOfInt){
    this -> vecOfInt = vecOfInt;
    numVertex = vecOfInt.size();
    numEdges = 0;
    for (int i = 0; i < numVertex; i++){
        for (int j = 0; j < numVertex; j++) {
            if (vecOfInt[i][j] == 1) {
                numEdges++;
            }
        }
    }
    numEdges /= 2;
}

//Complejidad O(n^2) 
void MyGraph::DFS(int initial){
    std::vector<bool> visited(numVertex, false);
    std::vector<int> stack;
    stack.push_back(initial);
    while (!stack.empty()){
        int v = stack.back();
        stack.pop_back();
        if (!visited[v]) {
            visited[v] = true;
            std::cout << v << " ";
            for (int i = numVertex - 1; i >= 0; i--){
                if (vecOfInt[v][i] == 1 && !visited[i]){
                    stack.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}

//Complejidad O(m+n) 
void MyGraph::BFS(int initial){
    std::vector<bool> visited(numVertex, false);
    std::vector<int> queue;
    queue.push_back(initial);
    while (!queue.empty()){
        int v = queue.front();
        queue.erase(queue.begin());
        if (!visited[v]) {
            visited[v] = true;
            std::cout << v << " ";
            for (int i = 0; i < numVertex; i++){
                if (vecOfInt[v][i] == 1 && !visited[i]){
                    queue.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}