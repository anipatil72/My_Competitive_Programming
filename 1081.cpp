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

const int MAX = 10000;

int findK(vector<vector<int>> &a, int n, int m, int k)
{
    int left = 0, right = m - 1, up = 0, down = n - 1;

    int des = 0, ans = -1;

    for (int count = 0; left <= right && up <= down; count++)
    {
        if (count % 4 == 0)
        {

            for (int i = left; i <= right && des < k; i++)
            {
                des++;

                ans = a[up][i];

                cout << ans << endl;
            }

            if (des == k)
            {
                return ans;
            }

            up++;
        }
        else if (count % 4 == 1)
        {
            for (int i = up; i <= down && des < k; i++)
            {
                des++;

                ans = a[i][right];

                cout << ans << endl;
            }

            if (des == k)
            {
                return ans;
            }

            right--;
        }
        else if (count % 4 == 2)
        {

            for (int i = right; i >= left && des < k; i--)
            {
                des++;

                ans = a[down][i];

                cout << ans << endl;
            }

            if (des == k)
            {
                return ans;
            }

            down--;
        }
        else
        {

            for (int i = down; i >= up && des < k; i--)
            {
                des++;

                ans = a[i][left];

                cout << ans << endl;
            }

            if (des == k)
            {
                return ans;
            }

            left++;
        }

        count++;
    }

    return ans;
}

int main()
{

    vector<vector<int>> spiral = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int k = 4;

    cout << "This is ans : " << findK(spiral, 3, 3, k) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥