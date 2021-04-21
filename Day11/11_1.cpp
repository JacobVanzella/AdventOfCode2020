#include <fstream>
#include <iostream>

#define WIDTH 98
#define HEIGHT 99

int main()
{
    char currentChar;
    bool dirty = true;
    int numAdj = 0, occupied = 0;
    int seating1[WIDTH][HEIGHT];
    int seating2[WIDTH][HEIGHT];
    std::fstream inputFile("input.txt");

    // Initialize seating array
    int row = 0, col = 0;
    while (inputFile.get(currentChar))
    {
        if (currentChar == '.')
        {
            seating1[col][row] = -1;
            seating2[col][row] = -1;
            col++;
        }
        else if (currentChar == 'L')
        {
            seating1[col][row] = 0;
            seating2[col][row] = 0;
            col++;
        }
        else
        {
            row++;
        }
        col = col % WIDTH;
    }

    while (dirty)
    {
        dirty = false;
        occupied = 0;

        // Read seating from seating1 and stores updated seating to seating2
        for (size_t row = 0; row < HEIGHT; row++)
        {
            for (size_t col = 0; col < WIDTH; col++)
            {
                if (seating1[col][row] == -1)
                    continue;

                numAdj = 0;
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        if ((row + i) < 0 || (col + j) < 0 || (row + i) >= HEIGHT || (col + j) >= WIDTH || (i == 0 && j == 0))
                            continue;

                        numAdj += (seating1[col + j][row + i] == -1) ? 0 : seating1[col + j][row + i];
                    }
                }

                if (seating1[col][row] == 0 && numAdj == 0)
                    seating2[col][row] = 1;
                else if (seating1[col][row] == 1 && numAdj >= 4)
                    seating2[col][row] = 0;
            }
        }

        // Copy seating2 to seating1 for next iteration
        // A more efficient implementation would alternate the observed array instead of copying stuff over, but I'm lazy
        for (size_t row = 0; row < HEIGHT; row++)
            for (size_t col = 0; col < WIDTH; col++)
            {
                if (seating1[col][row] != seating2[col][row])
                    dirty = true;
                if (seating2[col][row] == 1)
                    occupied++;
                seating1[col][row] = seating2[col][row];
            }
    }

    std::cout << "There are " << occupied << " occupied seats.\n";
}