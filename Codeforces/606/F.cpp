#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];

int dfs(int x, int p){
    int mx = 0;
    for(auto i : adj[x]){
        if(i == p)  continue;
        mx = max(mx, dfs(i, x));
    }
    if(adj[x].size() == 1 && x != 1)    return 0;
    int snd = (int)adj[x].size() - 2;
    if(x == 1)  ++snd;
    return 1 + max(mx, snd);
}

signed main(){
    ios::sync_with_stdio(0);
    int tc = 1;
    while(tc--){
        int n; cin >> n;
        for(int i = 2; i <= n; i++){
            int x; cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        cout << dfs(1, 0) << endl;
        for(int i = 1; i <= n; i++) adj[i].clear();
    }
}
