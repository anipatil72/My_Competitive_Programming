#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> &a)
{
    vector<int>::iterator i, j, k;

    for (i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
}

vector<int> twoSum(vector<int> &nums, int target)
{

    vector<int> ans;
    // sort(nums.begin(), nums.end());

    int s = 0;
    vector<int>::iterator i, j, k;

    k = nums.begin();

    for (i = nums.begin(); i != nums.end(); i++)
    {
        for (j = i +1; j != nums.end(); j++)
        {

            if ((*i + *j) == target)
            {

                // cout<<" I am here ! "<<endl;

                int x = distance(k, i);
                int y = distance(k, j);
                // cout<<x<<endl;
                // cout<<y<<endl;

                ans.push_back(x);
                ans.push_back(y);
            }
        }
    }

    return ans;
}

// using namespace std;

int main()
{

    vector<int> n = {2, 7, 11, 15};

    display(n);

    cout << "\nDisplaying the Answer" << endl;
    vector<int> answ = twoSum(n, 9);

    display(answ);

    return 0;
}