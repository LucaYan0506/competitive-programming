#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> res;

static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second; 
}

void removeZero(vector<pair<int,int>>& arr){
    int i = 0;
    while(arr[i].second == 0 && i < arr.size())
        i++;
    if (i != 0)
        arr.erase(arr.begin(),arr.begin() + i);
}

void getMaxScore(){
    int n; cin >> n;
    vector<pair<int,int>> freq(1001,{0,0});
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        freq[temp] = {temp,freq[temp].second + 1};
    }

    vector<pair<int,int>> currState = freq;
    sort(currState.begin(),currState.end(),cmp);
    removeZero(currState);

    bool aliceTurn = true;
    vector<bool> aliceColor(1001);
    while(currState.size() != 0){
        if (aliceTurn){
            bool flag = false;
            for(int i = 0; i < currState.size(); i++){
                auto x = currState[i];
                if (!aliceColor[x.first]){
                    aliceColor[x.first] = true;
                    currState[i] = {currState[i].first,currState[i].second - 1};
                    flag = true;
                    break;
                }
            }

            if (!flag)
                break;
            
            sort(currState.begin(), currState.end(), cmp);
            removeZero(currState);
        }else{
            bool flag = false;
            for(int i = 0; i < currState.size(); i++){
                auto x = currState[i];
                if (aliceColor[x.first]){
                    currState[i] = {currState[i].first,0};
                    flag = true;
                    break;
                }
            }

            if (!flag)
                for(int i = 0; i < currState.size(); i++)
                if (currState[i].first != 0){
                    currState[i] = {currState[i].first,currState[i].second - 1};
                    break;
                }
            
            sort(currState.begin(), currState.end(), cmp);
            removeZero(currState);
        }


        aliceTurn = !aliceTurn;
    }

    int aliceScore = 0;
    for (int i = 0; i < 1001; i++)
        if (aliceColor[i])
            aliceScore += 1 + (freq[i].second == 1);

    res.push_back(aliceScore);    
}

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        getMaxScore();

    for (int x : res)
        cout << x << endl;


    return 0;
}