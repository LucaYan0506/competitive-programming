#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define long long int

using namespace std;

int main(){
    int t; cin >> t;
    vector<string> res;
    while(t--){
        string str; cin >> str;
        for (int i = 0; i < str.size(); i++){
            int maxi = -1;
            for (int j = i + 1; j < str.size() && j <= i + 9; j++){
                char n = str[j] - j + i;
                
                if (maxi == -1 && n > str[i])
                    maxi = j;
                else if (maxi != -1 && n > str[maxi] - maxi + i)
                    maxi = j;
            }
            
            if (maxi != -1){
                char n = str[maxi] - maxi + i;
                str.erase(str.begin() + maxi);
                str.insert(i,1,n);
            }
                
        }

        res.push_back(str);
    }    
    
    for (auto x : res)
        cout << x << endl;

    return 0;
}