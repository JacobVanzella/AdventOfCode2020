#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    int validCount = 0, index, first, second;
    char policy;
    bool valid;
    std::string line, passwd;
    std::stringstream lineSS;
    std::ifstream inputFile("input.txt");

    while (getline(inputFile, line))
    {
        index = line.find(":");

        lineSS.str(line);
        lineSS >> first >> second >> policy;
        second = -second; // Dash makes stream read the second integer as a negative
        lineSS.str("");   // Reset the stringstream
        lineSS.clear();

        passwd = line.substr(index + 1);

        valid = ((policy == passwd[first]) || (policy == passwd[second])) &&
                !((policy == passwd[first]) && (policy == passwd[second]));

        if (valid)
            validCount++;

        // std::cout << first << " " << second << " " << policy << " " << passwd << " " << valid << "\n";
    }

    std::cout << "\nTotal valid password count: " << validCount;

    return validCount;
}