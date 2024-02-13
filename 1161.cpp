// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// bool hasDislikedDigit(int digit, const vector<int> &dislikedDigits)
// {
//     return find(dislikedDigits.begin(), dislikedDigits.end(), digit) != dislikedDigits.end();
// }

// int replaceDislikedDigits(int N, const vector<int> &dislikedDigits)
// {
//     vector<int> digits;

//     // Extract and store the digits in reverse order
//     while (N > 0)
//     {
//         digits.push_back(N % 10);
//         N /= 10;
//     }

//     reverse(digits.begin(), digits.end());

//     // Replace disliked digits with the minimum disliked digit using brute force
//     for (int &digit : digits)
//     {
//         int originalDigit = digit;

//         // Try all possible replacements for the current digit
//         for (int replacement = 0; replacement <= 9; ++replacement)
//         {
//             if (!hasDislikedDigit(replacement, dislikedDigits))
//             {
//                 digit = replacement;
//                 break;
//             }
//         }

//         // If the original digit was disliked, revert to the original value
//         if (hasDislikedDigit(originalDigit, dislikedDigits))
//         {
//             digit = originalDigit;
//         }
//     }

//     // Convert digits back to a number
//     int result = 0;
//     for (int digit : digits)
//     {
//         result = result * 10 + digit;
//     }

//     return result;
// }

// int solve(int N, const vector<int> &dislikedDigits)
// {
//     int result = replaceDislikedDigits(N, dislikedDigits);

//     // Continue replacing disliked digits until no more replacements are needed
//     while (result != N)
//     {
//         N = result;
//         result = replaceDislikedDigits(N, dislikedDigits);
//     }

//     return result;
// }

int solve(int n, int k, vector<int> &dislike)
{
    int d = dislike.size();

    sort(dislike.begin(), dislike.end());

    for (int fed = n; fed < 150000; fed++)
    {

        string s = to_string(fed);

        int fes = s.length();

        bool flag = true;

        for (int i = 0; i < fes; i++)
        {
            char test = s[i];

            int des = test - '0';

            if (binary_search(dislike.begin(), dislike.end(), des))
            {

                flag = false;

                break;
            }
        }

        if (flag)
        {
            return fed;
        }
    }

    return 0;
}

int main()
{
    int N, k;
    cout << "Enter the amount Bob needs to pay: ";
    cin >> N;

    cout << "Enter the number of disliked digits: ";
    cin >> k;

    vector<int> dislikedDigits(k);
    cout << "Enter the disliked digits: ";
    for (int i = 0; i < k; i++)
    {
        cin >> dislikedDigits[i];
    }

    int result = solve(N, k, dislikedDigits);

    cout << "Minimum amount Bob needs to pay: " << result << endl;

    return 0;
}

// Sample Input :
// 100
// 2
// 0 1

// Sample Output :
// 222

// ॥ जय श्री राम जय श्री कृष्ण ॥