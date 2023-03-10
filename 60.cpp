// C++ program to print largest contiguous array sum
#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySum(int a[],int size)
{
    int max_so_far = INT_MIN,max_ending_here = 0,
        start = 0,end = 0,s = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    if (a[start]==0)
    {
            while (a[start]==0)
            {
                start++ ;
            }
            
    }

    if (a[end]==0)
    {
            while (a[end]==0)
            {
                end-- ;
            }
            
    }
    
    cout << "Maximum contiguous sum is "
         << max_so_far << endl;
    cout << "Starting index " << start +1
         << endl
         << "Ending index " << end +1 << endl;

        // pair <int,int> p = {start,end};

    return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {0,1,0};
            // 100101101010101010001110101010100010100101010000010100001
            // 100101101010101010001110101010100010100101010000010100001
    int n = sizeof(a) / sizeof(a[0]);

    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = (a[i] == 0 ? 1 : 0);
    }



    

    int max_sum = maxSubArraySum(b,n);

    // int * len1 = new int[2];

    // len1[0]= max_sum.first + 1;
    // len1[1]= max_sum.second +1 ;

    return 0;
}
