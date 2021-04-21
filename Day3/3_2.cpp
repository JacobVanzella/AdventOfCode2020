#include <iostream>
#include <fstream>
#include <sstream>

#define ROW_LENGTH 31
// Number of moves down
#define ROW_SHIFTA 1
#define ROW_SHIFTB 1
#define ROW_SHIFTC 1
#define ROW_SHIFTD 1
#define ROW_SHIFTE 2
// Number of moves right
#define COL_SHIFTA 1
#define COL_SHIFTB 3
#define COL_SHIFTC 5
#define COL_SHIFTD 7
#define COL_SHIFTE 1

int treeCount(std::string line, int *pos, int colShift, int rowShift, int currentRow);

int main()
{
    long long treeCountA = 0, treeCountB = 0, treeCountC = 0, treeCountD = 0, treeCountE = 0;
    int posA = 0, posB = 0, posC = 0, posD = 0, posE = 0;
    int row = 0;
    std::string line;
    std::ifstream inputFile("input.txt");

    while (getline(inputFile, line))
    {
        treeCountA += treeCount(line, &posA, COL_SHIFTA, ROW_SHIFTA, row);
        treeCountB += treeCount(line, &posB, COL_SHIFTB, ROW_SHIFTB, row);
        treeCountC += treeCount(line, &posC, COL_SHIFTC, ROW_SHIFTC, row);
        treeCountD += treeCount(line, &posD, COL_SHIFTD, ROW_SHIFTD, row);
        treeCountE += treeCount(line, &posE, COL_SHIFTE, ROW_SHIFTE, row);
        row++;
    }

    long long longBoi = treeCountA * treeCountB * treeCountC * treeCountD * treeCountE;
    std::cout << "Number of trees hit on path A: " << treeCountA << "\n";
    std::cout << "Number of trees hit on path B: " << treeCountB << "\n";
    std::cout << "Number of trees hit on path C: " << treeCountC << "\n";
    std::cout << "Number of trees hit on path D: " << treeCountD << "\n";
    std::cout << "Number of trees hit on path E: " << treeCountE << "\n";
    std::cout << "Tree hit product: "
         << longBoi << "\n";

    return longBoi;
}

// colShift gives the moves to the right and rowShift the moves down
int treeCount(std::string line, int *pos, int colShift, int rowShift, int currentRow)
{
    if (!(currentRow % rowShift))
    {
        if (line[*pos] == '#')
        {
            *pos = (*pos + colShift) % ROW_LENGTH;
            return 1; // Return 1 to increment tree count if tree fonud
        }

        *pos = (*pos + colShift) % ROW_LENGTH;
    }

    return 0; // Return 0 if tree not found
}