#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#define FB 7
#define LR 3

int main()
{
    int seatID = 0, maxID = 0, minRange, maxRange, row, col;
    std::string buffer;
    std::ifstream inputFile("input.txt");

    while (getline(inputFile, buffer))
    {
        minRange = 0;
        maxRange = 127;
        for (int i = 0; i < FB; i++)
        {
            if (buffer[i] == 'F')
                maxRange -= pow(2,(FB - i - 1));
            else
                minRange += pow(2,(FB - i - 1));
        }
        row = minRange;

        minRange = 0;
        maxRange = 7;
        for (int i = 0; i < LR; i++)
        {
            if (buffer[i + FB] == 'L')
                maxRange -= pow(2,(LR - i - 1));
            else
                minRange += pow(2,(LR - i - 1));
        }
        col = minRange;

        seatID = row * 8 + col;
        if (maxID < seatID)
            maxID = seatID;
    }
    
    std::cout << "The highest seat ID is: " << maxID << '\n';
}