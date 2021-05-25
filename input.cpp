#include <iostream>
#include <fstream>
#include <list>
#include <vector>

namespace Graph_Task
{
    bool is_space(char ch)
    {
        switch (ch)
        {
        case ' ':
        case '\n':
        case '\t':
            return true;
        default:
            break;
        }
        return false;
    }

    bool is_valid_input(const std::vector<std::vector<int>>& adjacency)
    {
        for (int i = 0; i < adjacency.size(); ++i)
        {
            if (adjacency[i][i] != 0)
            {
                return false;
            }
            for (int j = 0; j < adjacency.size(); ++j)
            {
                if (adjacency[i].size() != adjacency[j].size())
                {
                    return false;
                }
                if (adjacency[i][j] != 1 )
                {
                    if(adjacency[i][j] != 0)
                        return false;
                }
                if(adjacency[i][j] != adjacency[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }


    void get_adjacency(std::istream& in, std::vector<std::vector<int>>& adjacency)
    {
        while (in)
        {
            char ch;
            std::vector<int> elem;
            do
            {
                in.get(ch);
                if (is_space(ch))
                {
                    continue;
                }
                int item = ch - '0';
                elem.push_back(item);
                if (in.eof())
                {
                    adjacency.push_back(elem);
                    return;
                }
            } while (ch != '\n');
            adjacency.push_back(elem);
        }
    }
} ///namespace Graph_Task
