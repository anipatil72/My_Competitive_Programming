#include <bits/stdc++.h>
using namespace std;

string serialize(vector<string> &A) {


    int n = A.size();


    string s = "";


    for (int i = 0; i < n; i++)
    {
            s = s + A[i] + to_string(A[i].length()) + '~';
    }
    

    return s;

}

int main() 
{

    vector<string> A = {"Aniruddha","Patil"};

    cout<<serialize(A);





    

return 0;
}