#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, x, ans=0 ;
vector<vector<int>> adj ;
vi timee ;
vb visit ;

void dfs_bob(int u, int t)
  {
    int v ;
    timee[u]=t ;
    visit[u]=true ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        v=adj[u][i] ;
        if(!visit[v])
          dfs_bob(v, t+1) ;
      }
  }

void dfs_alice(int u, int t)
  {
    int v ;
    visit[u]=true ;
    if(adj[u].size()==1 && t>timee[u]) ans=max(t, ans) ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        v=adj[u][i] ;
        if(!visit[v])
          dfs_alice(v, t+1) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> x ;
    adj.clear() ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    timee.assign(n+1, 0) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        int u, v ;
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs_bob(x, 0) ;
    visit.assign(n+1, false) ;
    dfs_alice(1, 0) ;
    cout<< ans*2 ;
  }
