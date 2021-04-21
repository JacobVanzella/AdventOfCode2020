#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::string;

#define NUMINSTRUCTIONS 624

int main()
{
    int idx = 0, acc = 0;
    int arguments[NUMINSTRUCTIONS];
    bool visited[NUMINSTRUCTIONS] = {0};
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

    // Execute the instruction set
    idx = 0;
    while (true)
    {
        if (visited[idx])
            break;
        else
            visited[idx] = true;

        if (!instructions[idx].compare("acc"))
        {
            acc += arguments[idx];
            idx++;
        }
        else if (!instructions[idx].compare("jmp"))
        {
            idx += arguments[idx];
        }
        else
        {
            idx++;
        }
    }

    cout << "The last accumulator value was: " << acc << "\n";
}