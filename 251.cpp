#include <bits/stdc++.h>
using namespace std;

//Correct Solution

double  findMedian(const vector<int> &A,const vector<int> &B)
{
    int total = (A.size() + B.size());
    int half = (total+1)/2;
   
    int left = 0;
    int right = A.size();
   
    while(true)
    {
        int mid = (left + right)/2;
        int left1 = ((mid -1 >=0 and mid-1 <A.size())? A[mid-1]:INT_MIN);
        int left2 = (((half-mid-1)>=0 and half - mid -1 < B.size())?B[half -mid -1]:INT_MIN);
        int right1 = ((mid < A.size())?A[mid]:INT_MAX);
        int right2 = ((half -mid <B.size())?B[half - mid]:INT_MAX);
       
        if(left1 <= right2 and left2<=right1)
        {
            if(total%2 == 1)
            {
                double ans  = max(left1,left2);
                return ans;
            }
            else
            {
                double ans = ((double)max(left1,left2) + (double)min(right1,right2))/2;
                return ans;
            }
        }
        else if(left1 > right2)
        {
            right = mid - 1;
        }
        else if(left2 > right1)
        {
            left = mid + 1;
        }
       
    }
}



double FindMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
       
   if(A.size() <= B.size())
   {
       return findMedian(A,B);
   }  
   else
   {
       return findMedian(B,A);
   }
 
}

//My Solution

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{

    int n = A.size();

    int m = B.size();

    int count = 0;

    int sum = 0;

    int medIndex;

    if ((m + n) % 2 == 0)
    {
        int i = 0, j = 0;

        while (i < n && j < m)
        {

            if (A[i] <= B[j])
            {

                if (count == (m + n) / 2 - 1 || count == (m + n) / 2)
                {
                    sum += A[i];
                }

                count++;
                i++;
            }

            if (A[i] > B[j])
            {

                if (count == (m + n) / 2 - 1 || count == (m + n) / 2)
                {
                    sum += B[j];
                }

                count++;
                j++;
            }
        }

        while (i < n)
        {


            if (count == (m + n) / 2 - 1 || count == (m + n) / 2)
            {
                sum += A[i];
            }

            count++;
            i++;
        }

        while (j < m)
        {


            if (count == (m + n) / 2 - 1 || count == (m + n) / 2)
            {
                sum += B[j];
            }

            count++;
            j++;
        }

        double d = sum / 2.0;

        return d;
    }

    int i = 0, j = 0;

    while (i < n && j < m)
    {

        if (A[i] <= B[j])
        {

            if (count == (m + n) / 2)
            {
                sum += A[i];
            }

            count++;
            i++;
        }

        if (A[i] > B[j])
        {

            if (count == (m + n) / 2)
            {
                sum += B[j];
            }

            count++;
            j++;
        }
    }

    while (i < n)
    {


        if (count == (m + n) / 2)
        {
            sum += A[i];
        }

        count++;
        i++;
    }

    while (j < m)
    {


        if (count == (m + n) / 2)
        {
            sum += B[j];
        }

        count++;
        j++;
    }

    double d = sum /1.0;

    return d;
}

int main()
{

    vector<int> a = {-10,-7,-4,1};
    vector<int> b = {-11,-3,0,2,3};

    cout<<findMedianSortedArrays(a,b);


    return 0;
}