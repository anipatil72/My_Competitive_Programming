// ॥ श्री गणेशाय नमः ॥
 
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;


template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {  
     if (start < 0)                                                      
     {
         start = 0;
     }
     if (end < 0)
     {
        end = int(v.size());
     }
     
     for (int i = start; i < end; i++)
     {
          cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
     }
}

int main() 
{

    vector<int> a = {2,1,5,3,7,8,3,11};

    sort(a.begin(), a.end());

    output_vector(a);

    

return 0;
}
 
// ॥ जय श्री राम जय श्री कृष्ण ॥