#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, u, v, x ;
vb visit, init, goal ;
vi ans ;
vvi adj ;

void dfs(int t, int l, int e, int o)
  {
    visit[t]=true ;
    if((l%2==0 && e%2==1) || (l%2==1 && o%2==1))
      init[t]=init[t]-1 ;
    if(init[t]!=goal[t])
      {
        ans.pb(t) ;
        if(l%2) o++ ;
        else e++ ;
      }
    for(int i=0 ; i<adj[t].size() ; i++)
      if(!visit[adj[t][i]])
        dfs(adj[t][i], l+1, e, o) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    goal.resize(n+1) ;
    init.resize(n+1) ;
    visit.assign(n+1, false) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        init[i]=x ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        goal[i]=x ;
      }
    dfs(1, 0, 0, 0) ;
    cout<< ans.size() << endl ;
    for(int i=0 ; i<ans.size() ; i++)
      cout<< ans[i] << endl ;
  }
