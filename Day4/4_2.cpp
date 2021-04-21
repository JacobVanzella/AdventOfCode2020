#include <iostream>
#include <fstream>
#include <sstream>

bool validateFields(size_t *dataPos, std::string data);

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
            size_t dataPos[7] = {data.find("byr:"), data.find("iyr:"), data.find("eyr:"),
                                 data.find("hgt:"), data.find("hcl:"), data.find("ecl:"),
                                 data.find("pid:")};
            validDocument = (dataPos[0] + 1) && (dataPos[1] + 1) && (dataPos[2] + 1) &&
                            (dataPos[3] + 1) && (dataPos[4] + 1) && (dataPos[5] + 1) &&
                            (dataPos[6] + 1);
            if (validDocument)
                validDocument = validateFields(dataPos, data);

            data.erase();
            if (validDocument)
                validCount++;
        }
    }

    std::cout << "\nThe valid document count is: " << validCount;
}

// There's probably a better way than this . . . perhaps using a map . . .
bool validateFields(size_t *dataPos, std::string data)
{
    char hcl;
    int byr, iyr, eyr, hgt;
    std::stringstream documentStream;
    std::string hgtUnits, hclValue, ecl, pid;

    documentStream.str(data);
    documentStream.seekg(dataPos[0] + 4);
    documentStream >> byr;
    documentStream.seekg(dataPos[1] + 4);
    documentStream >> iyr;
    documentStream.seekg(dataPos[2] + 4);
    documentStream >> eyr;
    documentStream.seekg(dataPos[3] + 4);
    documentStream >> hgt >> hgtUnits;
    documentStream.seekg(dataPos[4] + 4);
    documentStream >> hcl >> hclValue;
    documentStream.seekg(dataPos[5] + 4);
    documentStream >> ecl;
    documentStream.seekg(dataPos[6] + 4);
    documentStream >> pid;

    // Check birth year
    if (!(1920 <= byr && byr <= 2002))
        return false;
    // Check issue year
    if (!(2010 <= iyr && iyr <= 2020))
        return false;
    // Check expiration year
    if (!(2020 <= eyr && eyr <= 2030))
        return false;
    // Check height
    if (!(150 <= hgt && hgt <= 193 && !hgtUnits.compare("cm")) && !(59 <= hgt && hgt <= 76 && !hgtUnits.compare("in")))
        return false;
    // Check hair color
    if (hcl != '#' || !(0x000000 <= std::stoi(hclValue, 0, 16) <= 0x1000000))
        return false;
    // Check eye color
    if (ecl.compare("amb") && ecl.compare("blu") && ecl.compare("brn") && ecl.compare("gry") && ecl.compare("grn") && ecl.compare("hzl") && ecl.compare("oth"))
        return false;
    // Check issue number
    if (pid.length() != 9 || !stoi(pid))
        return false;

    return true;
}