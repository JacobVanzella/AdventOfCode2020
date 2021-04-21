#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

#define MYBAG "shinygold"

// Use depth first search to count potential outer bags
int DFS(std::map<std::string, std::vector<std::string>> &graph, std::map<std::string, bool> &visited, std::string vertex)
{
    int count = (visited.at(vertex)) ? 0 : 1;
    visited.at(vertex) = true;

    for (size_t i = 0; i < graph.at(vertex).size(); i++)
    {
        if (graph.count(graph.at(vertex)[i]) && !visited.at(graph.at(vertex)[i]))
        {
            count += DFS(graph, visited, graph.at(vertex)[i]);
        }
        else if (!visited.at(graph.at(vertex)[i]))
        {
            visited.at(graph.at(vertex)[i]) = true;
            count++;
        }
        else
        {
            visited.at(graph.at(vertex)[i]) = true;
        }
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
    std::map<std::string, bool> visitedList;
    std::map<std::string, std::vector<std::string>> heldBy;

    while (getline(inputFile, buffer))
    {
        // Clean input text into easily readable format
        buffer.erase(std::remove_if(buffer.begin(), buffer.end(), isspace), buffer.end());
        buffer = std::regex_replace(buffer, regBag, " ");

        // Create a directed graph where edges point from inner bag to outer bag
        inputStream.str(buffer);
        inputStream >> outerBag;
        inputStream >> numBags >> innerBag;
        visitedList.insert(std::pair<std::string, bool>(outerBag, false)); // Initialize visited to false
        while (!inputStream.eof())
        {
            if (!heldBy.count(innerBag))
            {
                adjacencyList.push_back(outerBag);
                visitedList.insert(std::pair<std::string, bool>(innerBag, false)); // Initialize visited to false
                heldBy.insert(std::pair<std::string, std::vector<std::string>>(innerBag, adjacencyList));
            }
            else
            {
                heldBy.at(innerBag).push_back(outerBag);
            }
            adjacencyList.clear();
            inputStream >> numBags >> innerBag;
        }
        inputStream.clear();
    }

    visitedList.at(MYBAG) = true; // Because bag must be in at least on other, set starting node to visited
    outerMostCount = DFS(heldBy, visitedList, MYBAG);
    std::cout << "The number of outermost bags is: " << outerMostCount << '\n';
}