#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include <memory>

using namespace std;

struct Node{
    int val;
    int pathSize;
    int ref;
    shared_ptr<Node> parent;

    Node (int _val, int _pathSize, int _ref, shared_ptr<Node> _parent = nullptr)
        : val(_val), pathSize(_pathSize), ref(_ref), parent(_parent) {}    
};

void printPath(shared_ptr<Node> node){
    auto curr = node;
    vector<int> path;
    while(curr != nullptr){
        path.push_back(curr->val);
        curr = curr->parent;
    }

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

int main(){
    int n,m,s; cin >> n >> m >> s;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
    }

    vector<shared_ptr<Node>> visited(n + 1);
    //init
    for (int i = 1; i <= n; i++){
        visited[i] = make_shared<Node>(i, 0,-1);
    }

    queue<shared_ptr<Node>> q;
    shared_ptr<Node> node_s = visited[s];
    node_s->pathSize = 1;
    for (auto edge : edges[s]){
        q.push(make_shared<Node>(edge,2,edge, node_s));
        // visited[edge] = {edge,2,edge,&node_s};
    }
    
    if (q.size() <= 1){
        cout << "Impossible";
        return 0;
    }
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto curr = q.front();
            q.pop();
            if (visited[curr->val]->pathSize > 1 && visited[curr->val]->ref != curr->ref){
                cout << "Possible" << endl;
                cout << visited[curr->val]->pathSize << endl;
                printPath(visited[curr->val]);
                cout << curr->pathSize << endl;
                printPath(curr);
                return 0;
            }
            if (visited[curr->val]->pathSize > 1 && visited[curr->val]->ref == curr->ref)
                continue;
            
            if (curr->val == s)
                continue;

            visited[curr->val] = curr;
            for (auto edge : edges[curr->val]){
                q.push(make_shared<Node>(edge,curr->pathSize + 1,curr->ref,curr));
                int a = 0;
            }
        }
    }

    cout << "Impossible";



    return 0;
}

