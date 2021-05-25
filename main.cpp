#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "input.hpp"
#include "graph.hpp"
using namespace Graph_Task;


int main()
{
    std::ifstream input("input.txt");
    std::vector<std::vector<int>> adjacency;
    if (!input.is_open())
    {
        std::cerr << "File is not open !!! " << std::endl;
        exit(0);
    }

    get_adjacency(input, adjacency);
    if (is_valid_input(adjacency))
    {
        Graph G{adjacency};
        if(G.has_isolated())
        {
            std::cout << "Graph G has an isolated vertex !!!" << std::endl;
            exit(0);
        }
        std::cout << "Graph G has " << G.vertex_count() << " vertex" << std::endl;
        std::cout << "Graph G has " << G.edges_count() << " edges" << std::endl;
        std::cout << "The number of edge covers in graph G is " << G.edge_cover() << std::endl;
        
    }
    else
    {
        std::cerr << "Input is not correct !!!" << std::endl;
        exit(0);
    }
    return 0;
}
