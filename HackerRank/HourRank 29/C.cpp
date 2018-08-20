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

lli n, m, x, u, v, ans ;
vi a ;
set<int> temp ;
vvi adj ;

void init()
  {
    ans=0 ;
    a.clear() ; adj.clear() ;
    adj.resize(n+1) ;
  }

void dfs(int u)
  {
    temp.insert(u) ;
    for(auto v:adj[u]) dfs(v) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m ;
        init() ;
        for(int i=1 ; i<n ; i++) cin>> u >> v, adj[v].pb(u) ;
        for(int i=1 ; i<=n ; i++) a.pb(i) ;
        do {
          bool pos=true ;
          for(int i=0 ; i<n ; i++)
            {
              temp.clear() ;
              dfs(a[i]) ;
              for(int j=0 ; j<i ; j++) if(temp.find(a[j])!=temp.end()) pos=false ;
            }
          if(pos) ans++ ;
        } while(next_permutation(all(a))) ;
        cout<< ans << endl ;
      }
  }
