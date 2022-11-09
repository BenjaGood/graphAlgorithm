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
    for(int i = 0; i < numVertex; i++){
        for(int j = 0; j < numVertex; j++){
            if(vecOfInt[i][j] == 1) {
                numEdges++;
            }
        }
    }
    numEdges /= 2;
}

//Complejidad O(n^2) 
void MyGraph::DFS(int initial){
    std::vector<bool> ifVisit(numVertex, false);
    std::vector<int> pile;
    pile.push_back(initial);
    while (!pile.empty()){
        int conf = pile.back();
        pile.pop_back();
        if (!ifVisit[conf]) {
            ifVisit[conf] = true;
            std::cout << conf << " ";
            for (int i = numVertex - 1; i >= 0; i--){
                if (vecOfInt[conf][i] == 1 && !ifVisit[i]){
                    pile.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}

//Complejidad O(m+n) 
void MyGraph::BFS(int initial){
    std::vector <bool> ifVisit(numVertex, false);
    std::vector <int> intOfQueue;
    intOfQueue.push_back(initial);
    while (!intOfQueue.empty()){
        int conf = intOfQueue.front();
        intOfQueue.erase(intOfQueue.begin());
        if (!ifVisit[conf]) {
            ifVisit[conf] = true;
            std::cout << conf << " ";
            for (int i = 0; i < numVertex; i++){
                if (vecOfInt[conf][i] == 1 && !ifVisit[i]){
                    intOfQueue.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}