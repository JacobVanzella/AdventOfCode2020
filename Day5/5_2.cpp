#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#define FB 7
#define LR 3
#define NUM_SEATS 965

int main()
{
    int seatID = 0, maxID = 0, count = 0, prevSeat, nextSeat, minRange, maxRange, row, col;
    int seatIDs[NUM_SEATS];
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
        seatIDs[count] = seatID;
        if (maxID < seatID)
            maxID = seatID;
        count++;
    }

    // Thank the Stroustrup for STL, hollowed by thy name.
    std::sort(seatIDs, seatIDs + NUM_SEATS);
    prevSeat = seatIDs[0];
    for (int i = 1; i < NUM_SEATS; i++){
        nextSeat = seatIDs[i];
        
        if ((prevSeat + 1) != nextSeat)
            break;

        prevSeat = nextSeat;
    }
    
    std::cout << "The highest seat ID is: " << maxID << '\n';
    std::cout << "My seat ID is: " << prevSeat + 1;
}