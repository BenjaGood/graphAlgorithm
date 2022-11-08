#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <iostream>
#include <vector>

class MyGraph {
    private:
        std::vector<std::vector<int>> vecOfInt;
        int numVertex;
        int numEdges;
    public:
        MyGraph(std::vector<std::vector<int>>& vecOfInt);
        void load(std::vector<std::vector<int>>& vecOfInt);
        void DFS(int initial);
        void BFS(int initial);
};
#endif // MYGRAPH_H





