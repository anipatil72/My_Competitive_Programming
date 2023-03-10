#include <iostream>
#include <vector>
using namespace std;

int mod(int cards)
{
    if (cards>=0)
    {
        return cards;
    }
    
    return (-1)*cards;
}



int minf(vector<int> &cards)
{

    int k = 1, d;

    vector<int>::iterator i, j, h;

    for (i = cards.begin(); i != cards.end(); i++)
    {

        for (j = cards.begin(); j != cards.end(); j++)
        {
            if (*i == *j && i != j)
            {

                    if (k)
                    {
                        d = mod(distance(i, j));
                        // cout<<" I am here!\n";
                        // cout<<distance(i, j)<<endl;
                        k = 0;
                    }

                    int d1 = mod(distance(i, j));

                    if (d1 < d)
                    {
                        // cout<<" I am hereby !\n";
                        // // cout<<distance(i, j)<<endl;
                        d = d1;
                    }
                 return d +1 ;   
            }
        }
    }
        return -1;
}

int main()
{

    vector <int> v = {1, 80,1, 18, 7 ,25 ,12,90,10};

    int ans = minf(v);

    cout<<ans<<endl;

    return 0;
}