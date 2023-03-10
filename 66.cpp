#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char str[10];

    scanf("%[^\n]c",&str);

    cout<<strrev(str)<<endl;

    
    return 0;
}