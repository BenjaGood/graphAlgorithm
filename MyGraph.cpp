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
    numOfVertex = vecOfInt.size();
    numEdges = 0;
    for(int i = 0; i < numOfVertex; i++){
        for(int j = 0; j < numOfVertex; j++){
            if(vecOfInt[i][j] == 1) {
                numEdges++;
            }
        }
    }
    numEdges = numEdges / 2;
}

//Complejidad O(n^2) 
void MyGraph::DFS(int initial){
    std::vector<bool> ifVisit(numOfVertex, false);
    std::vector<int> pile;
    pile.push_back(initial);
    while (!pile.empty()){
        int conf = pile.back();
        pile.pop_back();
        if (!ifVisit[conf]) {
            ifVisit[conf] = true;
            std::cout << conf << ",";
            for (int i = numOfVertex - 1; i >= 0; i--){
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
    std::vector <bool> ifVisit(numOfVertex, false);
    std::vector <int> intOfQueue;
    intOfQueue.push_back(initial);
    while (!intOfQueue.empty()){
        int conf = intOfQueue.front();
        intOfQueue.erase(intOfQueue.begin());
        if (!ifVisit[conf]) {
            ifVisit[conf] = true;
            std::cout << conf << ",";
            for (int i = 0; i < numOfVertex; i++){
                if (vecOfInt[conf][i] == 1 && !ifVisit[i]){
                    intOfQueue.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}

void MyGraph::loadGraph(){
    for(int i = 0; i < numOfVertex; i++){
        for(int j = 0; j < numOfVertex; j++){
            std::cout << vecOfInt[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool MyGraph::isTree(){
    if(numOfVertex - 1 == numEdges){
        return true;
    }
    return false;
}

void MyGraph::topologicalSort(){
    std::vector<int> inDegree(numOfVertex, 0);
    for(int i = 0; i < numOfVertex; i++){
        for(int j = 0; j < numOfVertex; j++){
            if(vecOfInt[i][j] == 1){
                inDegree[j]++;
            }
        }
    }
    std::vector<int> pile;
    for(int i = 0; i < numOfVertex; i++){
        if(inDegree[i] == 0){
            pile.push_back(i);
        }
    }
    while(!pile.empty()){
        int conf = pile.back();
        pile.pop_back();
        std::cout << conf << ",";
        for(int i = 0; i < numOfVertex; i++){
            if(vecOfInt[conf][i] == 1){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    pile.push_back(i);
                }
            }
        }
    }
    std::cout << std::endl;
}

bool MyGraph::bipartiteGraph(){
    std::vector<int> color(numOfVertex, -1);
    color[0] = 1;
    std::vector<int> pile;
    pile.push_back(0);
    while(!pile.empty()){
        int conf = pile.back();
        pile.pop_back();
        if(vecOfInt[conf][conf] == 1){
            return false;
        }
        for(int i = 0; i < numOfVertex; i++){
            if(vecOfInt[conf][i] == 1 && color[i] == -1){
                color[i] = 1 - color[conf];
                pile.push_back(i);
            }
            else if(vecOfInt[conf][i] == 1 && color[i] == color[conf]){
                return false;
            }
        }
    }
    return true;
}
