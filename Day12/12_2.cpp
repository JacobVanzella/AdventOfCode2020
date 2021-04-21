#include <fstream>
#include <iostream>
#include <cmath>

#define INPUTSIZE 759
#define _USE_MATH_DEFINES


int main()
{
    int unit, posNS = 0, posEW = 0, manDist;
    int waypointNS = 1, waypointEW = 10, temp;
    double radians;
    char heading;
    std::fstream inputFile("input.txt");

    while(inputFile >> heading >> unit)
    {
        switch (heading)
        {
        case 'N':
            waypointNS += unit;
            break;

        case 'S':
            waypointNS -= unit;
            break;
        
        case 'E':
            waypointEW += unit;
            break;

        case 'W':
            waypointEW -= unit;
            break;

        case 'L':
            temp = waypointNS;
            radians = -(unit * M_PI / 180);
            waypointNS = temp * (int)cos(radians) - waypointEW * (int)sin(radians);
            waypointEW = temp * (int)sin(radians) + waypointEW * (int)cos(radians);
            break;

        case 'R':
            temp = waypointNS;
            radians = unit * M_PI / 180;
            waypointNS = temp * (int)cos(radians) - waypointEW * (int)sin(radians);
            waypointEW = temp * (int)sin(radians) + waypointEW * (int)cos(radians);
            break;

        case 'F':
            posNS += unit * waypointNS;
            posEW += unit * waypointEW;
            break;
        
        default:
            break;
        }
    }
    
    manDist = abs(posNS) + abs(posEW);
    std::cout << "The ships Manhattan distance is: " << manDist << "\n";
}