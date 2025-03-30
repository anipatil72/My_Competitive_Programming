#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to check if a range is already sorted
bool isSorted(const string &s, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        if (s[i] > s[i + 1])
            return false;
    }
    return true;
}

// Function to create a signature for a range operation
string createSignature(const string &s, int l, int r)
{
    // Count zeros in the range
    int zeros = 0;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '0')
            zeros++;
    }

    // Create a compact signature
    // This will represent: prefix + sorted_substring + suffix
    string signature = "";

    // Add prefix
    if (l > 0)
    {
        signature += s.substr(0, l);
    }

    // Add sorted substring signature (just # of zeros and ones)
    signature += string(zeros, '0') + string(r - l + 1 - zeros, '1');

    // Add suffix
    if (r < s.length() - 1)
    {
        signature += s.substr(r + 1);
    }

    return signature;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        // Use unordered_map to track signatures we've seen
        unordered_map<string, bool> unique_results;

        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;

            // Convert to 0-indexed
            l--;
            r--;

            if (isSorted(s, l, r))
            {
                // If already sorted, the result is the original string
                unique_results[s] = true;
            }
            else
            {
                // Otherwise, create a signature
                unique_results[createSignature(s, l, r)] = true;
            }
        }

        // Output the number of unique results
        cout << unique_results.size() << endl;
    }

    return 0;
}