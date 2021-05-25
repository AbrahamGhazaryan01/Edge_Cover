#ifndef INPUT_HPP
#define INPUT_HPP

namespace Graph_Task
{
    void get_adjacency(std::istream&, std::vector<std::vector<int>>&);
    bool is_valid_input(const std::vector<std::vector<int>>&);
    bool is_space(char);

} ///namespace Graph_Task

#endif /// INPUT_HPP
