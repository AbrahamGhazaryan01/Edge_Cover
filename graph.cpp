#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "graph.hpp"

namespace Graph_Task
{

    Graph::Graph(const std::vector<std::vector<int>>& adj)
        : adjacency{adj}
    {
        for (int i = 0; i < adjacency.size(); ++i)
        {
            vertex.push_back(i);
            for (int j = i; j < adjacency.size(); ++j)
            {
                if (adjacency[i][j] == 1)
                {
                    auto  edge = std::make_pair(i, j);
                    edges.push_back(edge);
                }
            }
        }
    }


    bool Graph::is_adjacent(const std::pair<int, int>& f, const std::pair<int, int>& s) const
    {
        if (f.first == s.first || f.first == s.second || f.second == s.first || f.second == s.second)
        {
            return true;
        }
        return false;
    }


    int Graph::independency() const
    {
        std::list<std::pair<int, int>> lst;
        for (int i = 0; i < edges.size(); ++i)
        {
            lst.push_back(edges[i]);
        }
       
        for( auto it = lst.begin(); it != lst.end(); ++it)
        {
            for (auto iter = it; iter != lst.end();) 
            {
                if(is_adjacent(*it,*iter))
                {   
                    if(it == iter)
                    {
                        ++iter;
                    }  
                    else
                    {
                        iter = lst.erase(iter);
                    } 
                }  
                else
                {
                    ++iter;
                }
            }   
        }
        return lst.size();
    }

    int Graph::edge_cover() const
    {
        int vertex_count = vertex.size();
        return vertex_count - independency();
    }


    bool Graph::has_isolated() const
    {
        bool flag;
        for (int i = 0; i < adjacency.size(); ++i)
        {
            flag = true;
            for (int j = 0; j < adjacency.size(); ++j)
            {
                if (adjacency[j][i] == 1)
                {
                    flag = false;  
                    break;  
                }
            }
            if (flag)
            {
                return true;
            }
        }
        return false;
    }

    int Graph::vertex_count() const
    {
        return vertex.size();
    }
    int Graph::edges_count() const
    {
        return edges.size();
    } 
} /// namespace Graph_Task
