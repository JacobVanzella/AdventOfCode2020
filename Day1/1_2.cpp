#include <iostream>
#include <fstream>
#include <istream>

int main()
{
    int entries[200];
    int i, j, k, index = 0;
    std::ifstream inputFile("input.txt");

    while (inputFile >> entries[index])
    {
        std::cout << entries[index] << "\n";
        index++;
    }

    for (i = 0; i < 200; i++)
    {
        for (j = 0; j < 200; j++)
        {
            for (k = 0; k < 199; k++)
            {
                if ((entries[i] + entries[j] + entries[k]) == 2020)
                {
                    std::cout << "\n"
                         << entries[i] << "\n";
                    std::cout << entries[j] << "\n";
                    std::cout << entries[k] << "\n";
                    std::cout << entries[i] * entries[j] * entries[k] << "\n";

                    return entries[i] * entries[j] * entries[k];
                }
            }
        }
    }

    // Invalid input
    return -1;
}