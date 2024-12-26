#include<iostream>
#include<vector>


using namespace std;

vector<string> res;

bool patterExists(string &str, int i){
    // if (i < 0 || i + 3 >= str.size())
    //     return false;
    return str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '0' && str[i + 3] == '0';
}

void helper(){
    string str; cin >> str;
    int size = str.size();
    int q; cin >> q;
    vector<pair<int,int>> qs(q); //first = index second = value
    for (int i = 0; i < q; i++){
        int a,b; cin >> a >> b;        
        qs[i] = {a - 1,b};
    }
    
    vector<bool> check(size);
    int trueCount = 0;
    for (int i = 0; i < size - 3; i++)
        if (patterExists(str, i)){
            check[i] = true;
            trueCount++;
        }

    for (pair<int,int> x : qs){
        str[x.first] = (x.second + '0');
        for (int i = x.first - 3; i <= x.first; i++){
            if (i < 0 || i + 3 >= str.size())
                continue;
            if (patterExists(str,i)){
                if (!check[i]){
                    check[i] = true;
                    trueCount++;
                }
            }else if(check[i]){
                check[i] = false;
                trueCount--;
            }
        }
        
        if (trueCount > 0)
            res.push_back("YES");
        else
            res.push_back("NO");
    }   

}

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        helper();

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}

/*
1
1100000
3
6 1
7 1
4 1
*/