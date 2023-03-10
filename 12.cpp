#include <iostream>
using namespace std;

int countZeros(int i)
{

    if (i / 10 == 0 && i % 10 == 0)
    {

        return 1;
    }

    else if (i / 10 == 0 && i % 10 != 0)
    {

        return 0;
    }

    else if (i % 10 == 0)
    {
        return 1 + countZeros(i / 10);
    }

        return  countZeros(i / 10);
    
    
}

int main()
{

    int n;
    cin >> n;

    cout << countZeros(n) << endl;

    return 0;
}