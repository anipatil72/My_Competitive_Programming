#include <bits/stdc++.h>
using namespace std;





int main() 
{

    string text = "papel papel, you are very good with your !";

    string pattern = "papel";

    int pos = text.find(pattern);

    while (pos!=-1)
    {
        cout<<pos<<" ";

        pos = text.find(pattern,pos + 1);
    }
    




return 0;
}