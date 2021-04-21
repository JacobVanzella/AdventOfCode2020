#include <fstream>
#include <iostream>
#include <cmath>

#define INPUTSIZE 759

int main()
{
    int unit, facing = 0, posNS = 0, posEW = 0, manDist;
    char heading;
    std::fstream inputFile("input.txt");

    while(inputFile >> heading >> unit)
    {
        switch (heading)
        {
        case 'N':
            posNS += unit;
            break;

        case 'S':
            posNS -= unit;
            break;
        
        case 'E':
            posEW += unit;
            break;

        case 'W':
            posEW -= unit;
            break;

        case 'L':
            facing = abs((facing + unit) % 360);
            break;

        case 'R':
            facing = abs((facing + 360 - unit) % 360);
            break;

        case 'F':
            if (facing == 0)
                posEW += unit;
            else if (facing == 90)
                posNS += unit;
            else if (facing == 180)
                posEW -= unit;
            else
                posNS -= unit;
            break;
        
        default:
            break;
        }
    }
    
    manDist = abs(posNS) + abs(posEW);
    std::cout << "The ships Manhattan distance is: " << manDist << "\n";
}