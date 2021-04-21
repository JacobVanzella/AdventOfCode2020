#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

#define MYBAG "shinygold"

// Use depth first search to count number of inner bags
int DFS(std::map<std::string, std::vector<std::string>> &graph, std::string vertex)
{
    int bagCount = 0, count = 0;
    std::string innerBag;
    std::stringstream bagStream;
    
    for (size_t i = 0; i < graph.at(vertex).size(); i++)
    {
        bagStream.str(graph.at(vertex)[i]);
        bagStream >> bagCount >> innerBag;

        if (graph.count(innerBag))
        {
            count += bagCount + bagCount * DFS(graph, innerBag);
        }
        else
        {
            count += bagCount;
        }
        bagStream.clear();
    }


    return count;
}

int main()
{
    int numBags, outerMostCount;
    std::string buffer, outerBag, innerBag;
    std::fstream inputFile("input.txt");
    std::stringstream inputStream;
    std::regex regBag("(bag)[\\D]*");

    std::vector<std::string> adjacencyList;
    std::map<std::string, std::vector<std::string>> holds;

    while (getline(inputFile, buffer))
    {
        // Clean input text into easily readable format
        buffer.erase(std::remove_if(buffer.begin(), buffer.end(), isspace), buffer.end());
        buffer = std::regex_replace(buffer, regBag, " ");
        
        // Create a directed graph where edges point from inner bag to outer bag
        inputStream.str(buffer);
        inputStream >> outerBag;
        inputStream >> innerBag;
        while (!inputStream.eof())
        {
            if (!holds.count(outerBag))
            {
                adjacencyList.push_back(innerBag);
                holds.insert(std::pair<std::string, std::vector<std::string>>(outerBag, adjacencyList));
            }
            else
            {
                holds.at(outerBag).push_back(innerBag);
            }
            adjacencyList.clear();
            inputStream >> innerBag;
        }
        inputStream.clear();
    }

    outerMostCount = DFS(holds, MYBAG);
    std::cout << "The number of bags inside the " << MYBAG << " bag is: " << outerMostCount << '\n';
}