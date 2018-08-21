#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
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

int n, u, v, x, leaf, cnt, s ;
bool pos=true ;
vi deg, temp ;
vvi adj, ans ;

void dfs(int u, int prev)
  {
    temp.pb(u) ;
    if(deg[u]==1 && u!=s) ans.pb(temp) ;
    for(auto v:adj[u]) if(v!=prev) dfs(v, u) ;
    temp.pop_back() ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    deg.assign(n+1, 0) ;
    adj.resize(n+1) ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
        deg[u]++ ; deg[v]++ ;
      }
    for(int i=1 ; i<=n ; i++) if(deg[i]==1) leaf++ ;
    for(int i=1 ; i<=n ; i++)
      if(deg[i]>2)
        {
          if(deg[i]!=leaf) pos=false ;
          else s=i, cnt++ ;
        }
    if(cnt>1) pos=false ;
    if(pos)
      {
        vi temp ;
        s=max(s, 1) ;
        dfs(s, -1) ;
        cout<< "Yes" << endl << ans.size() << endl ;
        for(auto i:ans) cout<< i[0] << " " << i[i.size()-1] << endl ;
      }
    else cout<< "No" ;
  }
