#include <iostream>
#include <fstream>

int part1(std::vector<int> list1, std::vector<int> list2)
{
    int diff = 0;
    // sort each list
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    for (size_t i = 0; i < list1.size(); i++)
    {
        diff += abs(list1[i] - list2[i]);
    }
    return diff;
}

int part2(std::vector<int> list1, std::vector<int> list2)
{
    // create hashmap to store frequencies of list2
    std::unordered_map<int, int> count;
    for (int num : list2)
    {
        count[num]++;
    }

    // iterate through list1 to compute similarity score
    int similarity = 0;
    for (int num : list1)
    {
        similarity += num * count[num];
    }

    return similarity;
}

int main()
{
    std::string myText;
    std::ifstream myFile("day1.txt");

    std::vector<int> list1;
    std::vector<int> list2;
    while (getline(myFile, myText))
    {
        // delim is 3 spaces
        auto space = myText.find(' ');
        list1.push_back(stoi(myText.substr(0, space)));
        list2.push_back(stoi(myText.substr(space + 3)));
    }

    printf("part 1: %d\n", part1(list1, list2));
    printf("part 2: %d\n", part2(list1, list2));
}