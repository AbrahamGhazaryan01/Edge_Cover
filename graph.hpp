#ifndef GRAPH_TASK_GRAPH_HPP
#define GRAPH_TASK_GRAPH_HPP

namespace Graph_Task
{
    class Graph
    {
    public:
        explicit Graph(const std::vector<std::vector<int>>&);
        int edge_cover() const;
        bool has_isolated() const;
        int vertex_count() const;
        int edges_count() const; 

    private:
        std::vector<std::vector<int>> adjacency;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> vertex;

        bool is_adjacent(const std::pair<int, int>& , const std::pair<int, int>&) const;
        int independency() const;
    };
} /// namespace Graph_Task

#endif /// GRAPH_TASK_GRAPH_HPP
