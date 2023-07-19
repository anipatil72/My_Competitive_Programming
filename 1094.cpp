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

// void recur(int index, int req, int cur, vector<int> &peeps, int num, int &ans)
// {
//     int n = peeps.size();

//     if (num > ans)
//     {
//         return;
//     }

//     if ((cur & req) == req)
//     {
//         // return 0;

//         ans = num;

//         return;
//     }

//     if (index == n)
//     {
//         return;
//     }

//     int ans = 100;

//     int tem = 1;

//     cur |= peeps[index];
// }

// https://leetcode.com/problems/maximum-rows-covered-by-columns/

vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
{
    int n = people.size();

    int m = req_skills.size();

    unordered_map<string, int> skillId;

    for (int i = 0; i < m; i++)
    {
        skillId[req_skills[i]] = i;
    }

    vector<int> skillsMaskOfPerson(n);

    for (int i = 0; i < n; i++)
    {
        for (string skill : people[i])
        {
            skillsMaskOfPerson[i] |= 1 << skillId[skill];
        }
    }

    vector<long long> dp(1 << m, (1LL << n) - 1);

    dp[0] = 0;

    for (int skillsMask = 1; skillsMask < (1 << m); skillsMask++)
    {
        for (int i = 0; i < n; i++)
        {
            int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
            if (smallerSkillsMask != skillsMask)
            {
                long long peopleMask = dp[smallerSkillsMask] | (1LL << i);
                if (__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask]))
                {
                    dp[skillsMask] = peopleMask;
                }
            }
        }
    }
    long long answerMask = dp[(1 << m) - 1];
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if ((answerMask >> i) & 1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
{
    int n = req_skills.size();

    unordered_map<string, int> des;

    int desc = 0;

    for (auto &x : req_skills)
    {
        des[x] = desc++;
    }

    int m = people.size();

    vector<int> peeps(m, 0);

    for (int i = 0; i < m; i++)
    {
        for (auto &s : people[i])
        {
            int fix = des[s];

            peeps[i] |= (1 << fix);
        }
    }

    int ans = 100;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥