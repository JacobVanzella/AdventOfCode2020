#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string.h>

int main()
{
    int groupCount = 0, totalCount = 0, length;
    char prevValue, nextValue;
    std::string buffer, groupAnswers;
    std::fstream inputText("input.txt");

    while (getline(inputText, buffer))
    {
        if (buffer[0] != '\0')
            groupAnswers.append(buffer);

        if (buffer[0] == '\0' || inputText.eof())
        {
            groupCount = 1;
            length = groupAnswers.length();
            char *ga = new char[length+1];
            strcpy(ga, groupAnswers.c_str());
            std::sort(ga, ga + length);

            prevValue = ga[0];
            for (int i = 1; i < length; i++)
            {
                nextValue = ga[i];
                if (nextValue != prevValue)
                    groupCount++;
                prevValue = nextValue;
            }
            totalCount += groupCount;
            // std::cout << "Group count - ans : " << groupCount << " - " << ga << '\n';
            groupAnswers.erase();
        }
    }

    std::cout << "\nThe group sum of yes answers is: " << totalCount << '\n';
}