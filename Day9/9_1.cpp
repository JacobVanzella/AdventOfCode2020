#include <iostream>
#include <fstream>

#define INPUTSIZE 1000

int main()
{
    int idx = 0;
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

    std::cout << "The value not satisfying the rule is: " << values[idx] << "\n";
}