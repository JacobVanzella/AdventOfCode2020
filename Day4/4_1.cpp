#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    bool validDocument = false;
    int validCount = 0;
    std::ifstream inputFile("input.txt");
    std::string data, buffer;

    while (getline(inputFile, buffer))
    {
        if (buffer[0] != '\0')
        {
            data.append(" ");
            data.append(buffer);
        }

        // Accounts for case where the last entry is not followed by an empty line
        if (buffer[0] == '\0' || inputFile.eof())
        {
            // std::cout << data << "\n";
            // So slick, and he's modest too
            validDocument = (data.find("byr:") + 1) && (data.find("iyr:") + 1) &&
                            (data.find("eyr:") + 1) && (data.find("hgt:") + 1) &&
                            (data.find("hcl:") + 1) && (data.find("ecl:") + 1) &&
                            (data.find("pid:") + 1);

            if (validDocument)
                validCount++;
            data.erase();
        }
    }

    std::cout << "\nThe valid document count is: " << validCount;
}