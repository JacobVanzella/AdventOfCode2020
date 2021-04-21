#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string.h>

int main()
{
    int groupCount = 0, totalCount = 0, ansPP, groupSize = 0, length;
    char startValue, currentValue;
    std::string buffer, groupAnswers;
    std::fstream inputText("input.txt");

    while (getline(inputText, buffer))
    {
        if (buffer[0] != '\0')
        {
            groupAnswers.append(buffer);
            groupSize++;
        }

        if (buffer[0] == '\0' || inputText.eof())
        {
            length = groupAnswers.length();
            char *ga = new char[length + 1];
            strcpy(ga, groupAnswers.c_str());
            std::sort(ga, ga + length);

            ansPP = 1;
            startValue = ga[0];
            groupCount = (groupSize == 1) ? 1 : 0;
            for (int i = 1; i < length; i++)
            {
                currentValue = ga[i];
                if (startValue != currentValue || i == (length - 1))
                {
                    if (startValue == currentValue) // Accounts for end of line
                        ansPP++;
                    if (ansPP == groupSize)
                        groupCount++;

                    ansPP = 1;
                    startValue = currentValue;
                }
                else
                {
                    ansPP++;
                }
            }
            totalCount += groupCount;
            //std::cout << "Group size - count - ans : " << groupSize << " - " << groupCount << " - " << ga << '\n';
            groupSize = 0;
            groupAnswers.erase();
        }
    }

    std::cout << "\nThe group sum of yes answers is: " << totalCount << '\n';
}