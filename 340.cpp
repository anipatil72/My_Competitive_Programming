#include <bits/stdc++.h>
using namespace std;

int verify(vector<int>& A)
{
    // A.erase(A.begin()+i);

    

    int n = A.size();

    // if (m==1)
    // {
    //         return 1;
    // }
    // if (m==2&&A[0]!=A[1])
    // {
    //         return 1;
    // }

    // if (m==2&&v[0]==v[1])
    // {
    //         return 0;
    // }
    
    
    
    if (A[0]>A[1])
    {
        for (int i = 1; i < n && i!=n-1; i+=2)
        {
              if (A[i]<A[i-1]||A[i]<A[i+1])
              {
                    return 0;
              }

              if (A[i]==A[i-1])
              {
                    return 0;
              }
              
                
        }

        if (n%2==0&&A[n-1]>A[n-2])
        {
            return 0;
        }
        else if (n%2==1&&A[n-1]<A[n-2])
        {
            return 0;    
        }
        else if (A[n-1]==A[n-2])
        {
                return 0;
        }
        
        
        
        
            
    }

    if (A[0]<A[1])
    {

        for (int i = 2; i < n && i!=n-1; i+=2)
        {
              if (A[i]>A[i-1]||A[i]>A[i+1])
              {
                    return 0;
              }

              if (A[i]==A[i-1])
              {
                    return 0;
              }
                
        }

        if (n%2==0&&A[n-1]<A[n-2])
        {
              return 0;  
        }
        else if (n%2==1&&A[n-1]>A[n-2])
        {
                return 0;
        }
        else if (A[n-1]==A[n-2])
        {
                return 0;
        }
        
        
        
        
            
    
    }

    if (A[0]==A[1])
    {
            return 0;
    }


    return 1;
}

int check(int l,vector<int> A)
{

    
    A.erase(A.begin()+l);

    

    int n = A.size();

    // if (m==1)
    // {
    //         return 1;
    // }
    // if (m==2&&A[0]!=A[1])
    // {
    //         return 1;
    // }

    // if (m==2&&v[0]==v[1])
    // {
    //         return 0;
    // }
    
    
    
    if (A[0]>A[1])
    {
        for (int i = 1; i < n && i!=n-1; i+=2)
        {
              if (A[i]<A[i-1]||A[i]<A[i+1])
              {
                    return 0;
              }

              if (A[i]==A[i-1])
              {
                    return 0;
              }
              
                
        }

        if (n%2==0&&A[n-1]>A[n-2])
        {
            return 0;
        }
        else if (n%2==1&&A[n-1]<A[n-2])
        {
            return 0;    
        }
        else if (A[n-1]==A[n-2])
        {
                return 0;
        }
        
        
        
        
            
    }

    if (A[0]<A[1])
    {

        for (int i = 2; i < n && i!=n-1; i+=2)
        {
              if (A[i]>A[i-1]||A[i]>A[i+1])
              {
                    return 0;
              }

              if (A[i]==A[i-1])
              {
                    return 0;
              }
                
        }

        if (n%2==0&&A[n-1]<A[n-2])
        {
              return 0;  
        }
        else if (n%2==1&&A[n-1]>A[n-2])
        {
                return 0;
        }
        else if (A[n-1]==A[n-2])
        {
                return 0;
        }
        
        
        
        
            
    
    }

    if (A[0]==A[1])
    {
            return 0;
    }


    return 1;
    

}



int solution(vector<int> &A) {
    int n = A.size();

    if (n==1)
    {
            return 1;
    }

    vector<int> pos;
    

    int count = 0 ;


    for (int i = 0; i < n; i++)
    {
            count+=check(i,A);
    }
    

    // if (A[0]>A[1])
    // {
    //     for (int i = 1; i < n && i!=n-1; i+=2)
    //     {
    //           if (A[i]<A[i-1]||A[i]<A[i+1])
    //           {
    //                 pos.push_back(i);
    //           }
                
    //     }

    //     if (n%2==0&&A[n-1]>A[n-2])
    //     {
    //         pos.push_back(n-1);
    //     }
    //     else if (n%2==1&&A[n-1]<A[n-2])
    //     {
    //             pos.push_back(n-1);
    //     }
        
        
        
            
    // }

    // if (A[0]<A[1])
    // {

    //     for (int i = 2; i < n && i!=n-1; i+=2)
    //     {
    //           if (A[i]>A[i-1]||A[i]>A[i+1])
    //           {
    //                 pos.push_back(i);
    //           }
                
    //     }
            
    // }

    // if (count==n)
    // {
    //         return 0;
    // }
    
    
    if (verify(A)==1)
    {
            return 0;
    }

    if (count==0)
    {
            return -1;
    }
    
    

    
    return count;
    
}

// void call(vector<int> ans)
// {
//     ans[0]=0;
// }


// void test(vector<int>& a)
// {
//     call(a);
// }

int main() 
{

    vector<int> v = {1,4,2,6};

    cout<<solution(v);

    

    // test(v);

    // for (int i = 0; i < v.size(); i++)
    // {
    //         cout<<v[i]<<" ";
    // }
    

return 0;
}