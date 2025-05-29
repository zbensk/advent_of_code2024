#include <iostream>
#include <fstream>

bool isStable(std::vector<int> report)
{
    int total_diff = 0;
    bool valid = true;
    for (size_t i = 0; i < report.size() - 1; i++)
    {
        int diff = report[i] - report[i + 1];
        // check for stability
        if (abs(diff) < 1 || abs(diff) > 3)
        {
            valid = false;
            break;
        }
        // check for staying increase/decrease (sign of total_diff and current_diff should be the same)
        if (total_diff * diff < 0)
        {
            valid = false;
            break;
        }
        total_diff += diff;
    }
    return valid;
}

int part1(std::vector<std::vector<int>> reports)
{
    int total_safe = 0;
    for (auto report : reports)
    {
        if (isStable(report))
        {
            total_safe++;
        }
    }

    return total_safe;
}

int part2(std::vector<std::vector<int>> reports)
{
    int total_safe = 0;
    for (auto report : reports)
    {
        if (isStable(report))
        {
            total_safe++;
        }
        else
        {
            // remove each number from report and try again
            for (size_t i = 0; i < report.size(); i++)
            {
                std::vector<int> temp_report;
                for (size_t j = 0; j < report.size(); j++)
                {
                    if (i != j)
                    {
                        temp_report.push_back(report[j]);
                    }
                }
                if (isStable(temp_report))
                {
                    total_safe++;
                    break;
                }
            }
        }
    }
    return total_safe;
}

int main()
{
    std::string myText;
    std::ifstream myFile("day2.txt");

    std::vector<std::vector<int>> reports;
    while (getline(myFile, myText))
    {
        // delim is 1 space
        std::vector<int> report;
        int l = 0;
        int r = 1;
        while ((size_t)r < myText.size())
        {
            if (myText[r] == ' ')
            {
                report.push_back(stoi(myText.substr(l, r)));
                l = r + 1;
            }
            r++;
        }
        report.push_back(stoi(myText.substr(l, r)));
        reports.push_back(report);
    }

    printf("part 1: %d\n", part1(reports));
    printf("part 2: %d\n", part2(reports));
}