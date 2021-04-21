#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::string;

#define NUMINSTRUCTIONS 624

int main()
{
    int idx = 0, jmpidx = -1, acc = 0;
    int arguments[NUMINSTRUCTIONS];
    bool loopDetected = false;
    string buffer;
    string instructions[NUMINSTRUCTIONS];
    std::fstream inputFile("input.txt");
    std::stringstream inputStream;

    // Read in the instruction set
    while (getline(inputFile, buffer))
    {
        inputStream.str(buffer);
        inputStream >> instructions[idx] >> arguments[idx];
        idx++;
        inputStream.clear();
    }

    // Execute the instruction set. O(n^2), I feel like there should be something better
    for (int i = 0; i < NUMINSTRUCTIONS; i++)
    {
        acc = 0;
        bool visited[NUMINSTRUCTIONS] = {0};
        for (int idx = 0; idx < NUMINSTRUCTIONS; idx)
        {
            if (visited[idx])
            {
                loopDetected = true;
                break;
            }
            else
            {
                loopDetected = false;
                visited[idx] = true;
            }

            if (!instructions[idx].compare("acc"))
            {
                acc += arguments[idx];
                idx++;
            }
            else if (!instructions[idx].compare("jmp"))
            {
                if (i == idx) // Act as nop
                    idx++;
                else // Act as normal
                    idx += arguments[idx];
            }
            else
            {
                if (i == idx) // Act as jmp
                    idx += arguments[idx];
                else // Act as normal
                    idx++;
            }
        }
        if (!loopDetected)
            break;
    }

    cout << "The last accumulator value was: " << acc << "\n";
}