#include <iostream>
#include <fstream>
#include <algorithm>

#define INPUTSIZE 98

int main()
{
    long long outputPaths[INPUTSIZE];
    int outputJolts[INPUTSIZE];
    int idx = 0, count = 0, maxVal = 0, joltDiff = 0;
    std::fstream inputFile("input.txt");

    while (inputFile >> outputJolts[idx])
    {
        if (outputJolts[idx] > maxVal)
            maxVal = outputJolts[idx];
        outputPaths[idx] = 0;
        idx++;
    }
    outputJolts[INPUTSIZE - 2] = 0;
    outputPaths[INPUTSIZE - 2] = 0;
    outputJolts[INPUTSIZE - 1] = maxVal + 3;
    outputPaths[INPUTSIZE - 1] = 1;

    std::sort(outputJolts, outputJolts + INPUTSIZE);
    

    for (int i = INPUTSIZE - 1; i >= 0; i--)
    {
        count = 0;
        for (size_t j = 1; j < 4; j++)
        {
            if ((i + j) >= INPUTSIZE)
                break;

            joltDiff = outputJolts[i + j] - outputJolts[i];
            if (joltDiff <= 3)
                count++;
        }

        for (size_t j = 1; j <= count; j++)
        {
            if ((i + j) >= INPUTSIZE)
                break;

            outputPaths[i] += outputPaths[i + j];
        }
    }

    std::cout << "Total number of distinct arrangements is: " << outputPaths[0] << "\n";
}