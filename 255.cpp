#include <bits/stdc++.h>
using namespace std;


int BinarySearch(int low, int high , const vector<int>&v,int b)
{
    int l = low ;
    int h = high ;

    int mid = (l + h)/2;
        

        if (v[mid]==b)
        {
             return mid;   
        }

        if (v[l]==b)
        {
             return l;   
        }

        if (v[h]==b)
        {
             return h;   
        }


        if (l>h)
        {
                return -1;
        }
        
        
        // cout<<"I am here ! "<<endl;

   
        if (v[mid]<b)
        {
            return BinarySearch(mid + 1, h - 1,v,b);    
        }

        if (v[mid]>b)
        {
            return BinarySearch(l +1, mid -1,v,b);    
        }
        
    return -1;
    
}

int search(const vector<int> &A, int B) {

    int n = A.size();

    

    int btidx ;


    auto it = max_element(A.begin(),A.end());

    btidx = distance(A.begin(),it);
    

   
    if (binary_search(A.begin(),A.begin() + btidx + 1,B))
    {
          return BinarySearch(0,btidx,A,B) ;
    }


    if (binary_search(A.begin() + btidx + 1 ,A.end(),B))
    {
        return BinarySearch(btidx,n-1,A,B) ;   
    }
    


    return 0;


}



int main() 
{


    vector<int> v = {1,2,3,4,5,6,7,8};

    // rotate(v.begin(),v.begin() + 3,v.end());


    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }

    // cout<<endl;

    // cout<<search(v,9);

    cout<<BinarySearch(0,v.size() - 1, v, 11);
    

return 0;
}

