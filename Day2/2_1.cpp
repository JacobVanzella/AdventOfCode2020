#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    int validCount = 0, charCount = 0, index, min, max;
    char policy;
    bool valid;
    std::string line, passwd;
    std::stringstream lineSS;
    std::ifstream inputFile("input.txt");

    while (getline(inputFile, line))
    {
        index = line.find(":");

        lineSS.str(line);
        lineSS >> min >> max >> policy;
        max = -max;     // Dash makes stream read the second integer as a negative
        lineSS.str(""); // Reset the stringstream
        lineSS.clear();

        passwd = line.substr(index + 1);
        for (int i = 0; i < passwd.size() / sizeof(passwd[0]); i++)
        {
            if (policy == passwd[i])
                charCount++;
        }

        valid = (min <= charCount) && (charCount <= max);
        charCount = 0;

        if (valid)
            validCount++;

        // std::cout << min << " " << max << " " << policy << " " << passwd << " " << valid << "\n";
    }

    std::cout << "\nTotal valid password count: " << validCount;

    return validCount;
}