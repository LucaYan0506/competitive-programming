#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

void printRec(int b, int h, char k){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < b; j++)
            cout << k;
        cout << endl;
    }
}

void print2Rec(int b, int h, char k,int b1, int h1, char k1, bool sameHeight){
    int n,m;
    if (sameHeight)
        n = h, m = b + b1;
    else
        n = h + h1, m = b;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (sameHeight){
                if (j < b)
                    cout << k;
                else
                    cout << k1;
            }else{
                if (i < h)
                    cout << k;
                else
                    cout << k1;
            }
        }
        cout << endl;
    }
}


int main(){
    vector<vector<int>> x(3,vector<int>(3,0));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cin >> x[i][j];
        
    for (int i = 0; i < 3; i++)
        x[i][2] = 'A' + i;

    int maxi = 0;
    int maxj = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            if (x[i][j] > x[maxi][maxj]){
                maxi = i;
                maxj = j;
            }
        
    int base = x[maxi][maxj];
    vector<int> other = {-1,-1,-1};
    for (int i = 0; i < 3; i++){
        if (i == maxi)
            continue;
        if (other[0] == -1)
            other = x[i];
        else{
            if (x[i][0] + other[0] == base && x[i][1] == other[1] && other[1] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][0],x[i][1],x[i][2],other[0],other[1],other[2],true);
            }else if (x[i][0] + other[1] == base && x[i][1] == other[0] && other[0] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][0],x[i][1],x[i][2],other[1],other[0],other[2],true);
            }else if (x[i][1] + other[0] == base && x[i][0] == other[1] && x[i][0] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][1],x[i][0],x[i][2],other[0],other[1],other[2],true);
            }else if (x[i][1] + other[1] == base && x[i][0] == other[0] && x[i][0] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][1],x[i][0],x[i][2],other[1],other[0],other[2],true);
           
           
            }else if (x[i][0] == other[0] && other[0] == base && x[i][1] + other[1] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][0],x[i][1],x[i][2],other[0],other[1],other[2],false);
            }else if (x[i][1] == other[0] && other[0] == base && x[i][0] + other[1] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][1],x[i][0],x[i][2],other[0],other[1],other[2],false);
            }else if (x[i][0] == other[1] && other[1] == base && x[i][1] + other[0] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][0],x[i][1],x[i][2],other[1],other[0],other[2],false);
            }else if (x[i][1] == other[1] && other[1] == base && x[i][0] + other[0] + x[maxi][(maxj + 1) % 2] == base){
                cout << base << endl;
                printRec(x[maxi][maxj],x[maxi][(maxj + 1) % 2],x[maxi][2]);
                print2Rec(x[i][1],x[i][0],x[i][2],other[1],other[0],other[2],false);
            }
            else
                cout << "-1";
        }
    }



    return 0;
}



/*
1 3 1 3 3 1
4 4   2 6   4 2
other  max   x
*/