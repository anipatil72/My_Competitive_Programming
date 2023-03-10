#include <bits/stdc++.h>
using namespace std;

string convert(string A, int B)
{

    int n = A.length();

    if (n==1)
    {
            return A ;
    }
    

    vector<string> v;

    int iter = 0;

    int pos = 0;

    int inc = 1;

    for (int i = 0; i < B; i++)
    {
        v.push_back("");
    }

    for (int i = 0; i < n; i++)
    {

        if (inc == 1)
        {
            v[pos] += A[i];
            pos++;
        }

        if (inc == 0)
        {
            v[pos] += A[i];
            pos--;
        }

        if (pos == -1)
        {
            pos = 1;
            inc = 1;
        }

        if (pos == B)
        {
            pos = B - 2;
            inc = 0;
        }
    }

    string ans = "";

    for (int i = 0; i < B; i++)
    {

        //cout << v[i] << endl;
        ans += v[i];
    }

    return ans;
}

int main()
{

    string s = "kHAlbLzY8Dr4zR0eeLwvoRFg9r23Y3hEujEqdio0ctLh4jZ1izwLh70R7SAkFsXlZ8UlghCL95yezo5hBxQJ1Td6qFb3jpFrMj8pdvP6M6k7IaXkq21XhpmGNwl7tBe86eZasMW2BGhnqF6gPb1YjCTexgCurS";

    cout << convert(s, 3);

    return 0;
}