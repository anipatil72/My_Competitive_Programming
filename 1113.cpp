#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the next permutation of the array
std::vector<int> next_permutation(std::vector<int> arr)
{
    int n = arr.size();

    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            break;
        }
    }

    if (i == -1)
    {
        // If no such element is found, arr is the last permutation
        return {};
    }

    for (int j = n - 1; j > i; j--)
    {
        if (arr[j] > arr[i])
        {
            std::swap(arr[i], arr[j]);
            std::reverse(arr.begin() + i + 1, arr.end());
            return arr;
        }
    }

    return arr;
}

bool findMaxScore(std::vector<int> arr)
{
    int n = arr.size();
    int mad = 0;

    while (!arr.empty())
    {
        int des = 0;

        for (int i = 1; i <= n; i++)
        {
            des += (arr[i - 1] * i);
        }

        mad = std::max(mad, des);
        arr = next_permutation(arr);

        if (arr.empty())
        {
            break;
        }
    }

    return mad == (n * (n + 1) * (2 * n + 1) / 6);
}

int main()
{
    // Example usage
    for (int i = 1; i <= 250; i++)
    {
        std::vector<int> tem(i);
        for (int j = 0; j < i; j++)
        {
            tem[j] = j + 1;
        }

        bool ans = findMaxScore(tem);

        if (ans)
        {
            std::cout << "Yeah! it works!" << std::endl;
        }
        else
        {
            std::cout << "Doesn't Work!" << std::endl;
        }
    }

    return 0;
}
