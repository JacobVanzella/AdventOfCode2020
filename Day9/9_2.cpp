#include <iostream>
#include <fstream>
#include <limits.h>

#define INPUTSIZE 1000

// This solution is super ineffecient, but I don't know if there is a better way, if you do drop me a DM on GITHUB
int main()
{
    int idx = 0, sum = 0, min = INT_MAX, max = INT_MIN;
    int values[INPUTSIZE];
    bool found = false;
    std::fstream inputFile("input.txt");

    while (inputFile >> values[idx])
        idx++;

    // Find number that doesn't fit first rule
    for (size_t i = 25; i < INPUTSIZE; i++)
    {
        for (size_t j = 0; j < 25; j++)
        {
            for (size_t k = 0; k < 25; k++)
            {
                if (values[i - j - 1] + values[i - k - 1] == values[i])
                    found = true;
            }
        }

        if (!found)
        {
            idx = i;
            break;
        }

        found = false;
    }

    size_t i = 0, j = 0;
    while (sum != values[idx])
    {
        min = (values[i] < min) ? values[i] : min;
        max = (values[i] > max) ? values[i] : max;
        sum += values[i];
        i++;

        if (sum > values[idx])
        {
            min = INT_MAX;
            max = INT_MIN;
            sum = 0;
            j++;
            i = j;
        }
    }

    std::cout << "The encryption weakness is: " << min << " + " << max << " = " << min + max << "\n";
}