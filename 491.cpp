#include <bits/stdc++.h>
using namespace std;

int main()
{

    int ab, bc, ca;

    cin >> ab >> bc >> ca;

    int a = sqrt(ab * ca / bc);
    int b = sqrt(ab * bc / ca);
    int c = sqrt(bc * ca / ab);

    cout << 4 * (a + b + c) << endl;

    return 0;
}