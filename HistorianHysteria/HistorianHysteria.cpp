#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

std::vector<int> leftList;
std::vector<int> rightList;

void storeInputAsNumbers(std::vector<int>* leftList, std::vector<int>* rightList, std::string inputName)
{
    std::string line;
    std::ifstream file(inputName);
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            int left, right;

            std::istringstream iss(line);
            if (iss >> left >> right)
            {
                leftList->push_back(left);
                rightList->push_back(right);
            }
        }

        file.close();
    }
    else
    {
        std::cerr << "Unable to open file!" << std::endl;
    }
}

void solvePartOne()
{
    int totalDistance{ 0 };

    storeInputAsNumbers(&leftList, &rightList, "input.txt");

    std::sort(leftList.begin(), leftList.end());
    std::sort(rightList.begin(), rightList.end());

    for (int i = 0; i < leftList.size(); i++)
    {
        totalDistance += (std::abs(leftList[i] - rightList[i]));
    }

    std::printf("Total distance: %d\n", totalDistance);
}

void solvePartTwo()
{
    int similarityScore{ 0 };
    std::map<int, int> similarity;

    for (int k : leftList)
    {
        similarity[k] = 0;
    }

    for (int k : rightList)
    {
        if (similarity.find(k) != similarity.end())
        {
            similarity[k]++;
        }
        else continue;
    }

    for (std::pair<int, int> kv : similarity)
    {
        similarityScore += (kv.first * kv.second);
    }

    std::printf("Similarity score: %d\n", similarityScore);
}

int main()
{
    solvePartOne();
    solvePartTwo();
    return 0;
}
