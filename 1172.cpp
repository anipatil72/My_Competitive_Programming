#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int P, X, R1, N, Y, R2;
        cin >> P >> X >> R1;
        cin >> N >> Y >> R2;

        // Calculate time taken by Paul and Nina
        int timePaul = (P / X) + R1;
        int timeNina = (N / Y) + R2;

        // Determine who reaches first
        if (timePaul < timeNina)
        {
            cout << "PAUL" << endl;
            cout << timePaul << endl;
        }
        else if (timePaul > timeNina)
        {
            cout << "NINA" << endl;
            cout << timeNina << endl;
        }
        else
        {
            cout << "BOTH" << endl;
            cout << timePaul << endl; // or timeNina since they are equal
        }
    }

    return 0;
}
