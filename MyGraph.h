#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <iostream>
#include <vector>

class MyGraph {
    private:
        std::vector<std::vector<int>> mat;
        int numVertices;
        int numEdges;
    public:
        MyGraph(std::vector<std::vector<int>>& mat);
        void load(std::vector<std::vector<int>>& mat);
        void DFS();
        void BFS();
};
#endif // MYGRAPH_H





