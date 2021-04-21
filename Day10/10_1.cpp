#include <iostream>
#include <fstream>
#include <algorithm>

#define INPUTSIZE 96

int main()
{
    int idx = 0;
    int oneJoltDiff = 0, threeJoltDiff = 0;
    int outputJolts[INPUTSIZE];
    std::fstream inputFile("input.txt");

    while (inputFile >> outputJolts[idx])
        idx++;

    std::sort(outputJolts, outputJolts + INPUTSIZE);

    if (outputJolts[0] == 1)
        oneJoltDiff++;
    else
        threeJoltDiff++;

    for (size_t i = 1; i < INPUTSIZE; i++)
    {
        if (outputJolts[i] - outputJolts[i - 1] == 1)
            oneJoltDiff++;

        if (outputJolts[i] - outputJolts[i - 1] == 3)
            threeJoltDiff++;
    }
    threeJoltDiff++; // To account for the device jolt difference

    std::cout << "Product = " << oneJoltDiff << " * " << threeJoltDiff << " = " << oneJoltDiff * threeJoltDiff;
}