#include<bits/stdc++.h>
using namespace std;

random_device dev;
mt19937 rng(dev());
// uniform_int_distribution<std::mt19937::result_type> val(1,6); // distribution in range [1, 6]
// cout << dist6(rng) << std::endl;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        if (n < 0)
            return 0;
        int i = 1, j = 2, k = 3;
        while(1)
        {
            cout<<"? "<< i <<" "<< j <<" "<< k <<endl;
            int l; cin >> l;
            if(l < 0)
                return 0;
            if(l == 0)
                break;

            uniform_int_distribution<std::mt19937::result_type> uni(1,3);
            
            int temp = uni(rng);
            if(temp == 1)
                i = l;
            else if(temp == 2)
                j = l;
            else 
                k = l;
        }
        cout<<"! "<< i <<" "<< j <<" "<< k << endl;
    }
}