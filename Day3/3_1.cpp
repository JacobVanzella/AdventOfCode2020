#include <iostream>
#include <fstream>
#include <sstream>

#define ROW_LENGTH 31

int main()
{
    int pos = 0, treeCount = 0;
    std::string line;
    std::ifstream inputFile("input.txt");

    while (getline(inputFile, line))
    {
        if (line[pos] == '#')
            treeCount++;
        
        pos = (pos + 3) % ROW_LENGTH;
    }

    std::cout << "Number of trees hit: " << treeCount;

    return treeCount;
}