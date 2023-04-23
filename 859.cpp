// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

class TrieNode
{
public:
    TrieNode *children[26];
};
TrieNode *getNode()
{
    TrieNode *pNode = new TrieNode();
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    return pNode;
}
void insert(TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
}

bool search(TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return true;
}

class Solution
{
public:
    int prefixSuffixString(vector<string> &s1, vector<string> s2)
    {
        TrieNode *root = getNode();
        for (auto str : s1)
        {
            insert(root, str);
            reverse(str.begin(), str.end());
            insert(root, str);
        }
        int ans = 0;
        for (auto str : s2)
        {
            string rev = str;
            reverse(rev.begin(), rev.end());
            if (search(root, str) or search(root, rev))
            {
                ans++;
            }
        }
        return ans;
    }
};

// int prefixSuffixString(vector<string> &s1, vector<string> s2)
// {
//     int n = s1.size();

//     int m = s2.size();

//     int ans = 0;

//     unordered_map<int, int> lens;

//     for (int i = 0; i < m; i++)
//     {

//         lens[s2[i].length()]++;
//     }

//     unordered_map<string, int> mp;

//     for (int i = 0; i < n; i++)
//     {

//         // int found = s1[j].find(s2[i]);
//         // if (found != -1)
//         // {

//         //     int pos = s1[j].length() - tem;

//         //     if (found == pos || found == 0)
//         //     {
//         //         ans++;

//         //         break;
//         //     }
//         // }

//         // int tem = s2[i].length();

//         // if (tem <= s1[j].length())
//         // {
//         //     string can1 = s1[j].substr(0, tem);

//         //     string can2 = s1[j].substr(s1[j].length() - tem);

//         //     if (can1 == s2[i] || can2 == s2[i])
//         //     {
//         //         ans++;

//         //         break;
//         //     }
//         // }
//     }

//     return ans;
// }

int main()
{

    string s = "hovcv";

    string temp = "v";

    int tem = temp.length();

    string can1 = s.substr(0, tem);

    string can2 = s.substr(s.length() - tem);

    cout << "This is it : " << endl;

    cout << can1 << endl;
    cout << can2 << endl;

    // int found = s.find(tem);

    // cout << (found) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥