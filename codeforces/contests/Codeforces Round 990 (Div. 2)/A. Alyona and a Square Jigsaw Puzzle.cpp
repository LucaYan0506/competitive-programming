#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    // vector<int> happyPiece = {1, 9, 25, 49, 81, 121, 169, 225, 289, 361, 441, 529, 625, 729, 841, 961, 1089, 1225, 1369, 1521, 1681, 1849, 2025, 2209, 2401, 2601, 2809, 3025, 3249, 3481, 3721, 3969, 4225, 4489, 4761, 5041, 5329, 5625, 5929, 6241, 6561, 6889, 7225, 7569, 7921, 8281, 8649, 9025, 9409, 9801}
    vector<bool> happyPiece(10000);

    int layerSize = -1;
    for (int i = 1; i <= 100*100; i += layerSize * 4 + 4){
        happyPiece[i] = true;
        layerSize += 2;
    }    

    int t; cin >> t;
    vector<int> results;
    while (t--)
    {
        int n; cin >> n;
        int pieces = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            int temp; cin >> temp;
            pieces += temp;
            if (pieces < 10000){
                if (happyPiece[pieces])
                    res++;
            }
        }
        results.push_back(res);
    }
    
    for (int res : results)
        cout << res << endl;

    return 0;
}