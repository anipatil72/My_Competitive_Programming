#include <bits/stdc++.h>
using namespace std;

// void decToBinary(int n)
// {
//     // array to store binary number
//     bool binaryNum[32];
 
//     // counter for binary array
//     int i = 0;
//     while (n > 0) {
 
//         // storing remainder in binary array
//         binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }
 
//     // printing binary array in reverse order
//     for (int j = i - 1; j >= 0; j--)
//         cout << binaryNum[j];
// }

int main() 
{

    bitset<32> b1(1000000);

    cout<<b1<<endl;
    cout<<b1.any();

    

return 0;
}