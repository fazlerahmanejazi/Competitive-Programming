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

int n, q, u, v, x, T, c, ans ;
vi d(100005, 0), start(100005), finish(100005), sz(100005, 0) ;
vvi adj(100005), p(25, vi(100005)) ;

void dfs(int u, int prev)
  {
  	d[u]=d[prev]+1 ;
  	p[0][u]=prev ;
  	start[u]=T++ ;
  	for(auto v:adj[u]) if(v!=prev) dfs(v, u), sz[u]+=sz[v] ;
  	finish[u]=T++ ;
  	sz[u]++ ;
  }

int check(int u, int v)
  {
  	if((start[v]<=start[u] && finish[u]<=finish[v]))
      {
    		for(int j=19 ; j>=0 ; j--)
    			if(d[p[j][u]]>d[v])
    				u=p[j][u];
    		return u ;
    	}
  	else return p[0][v];
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, 1) ;
    for(int i=1 ; i<20 ; i++)
  		for(int j=1 ; j<=n ; j++)
  			p[i][j]=p[i-1][p[i-1][j]] ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> u >> v >> c ;
        u=check(u, c) ;
        v=check(v, c) ;
        if(u==v) cout<< 0 << endl ;
        else
          {
            ans=n ;
            if(v==p[0][c]) ans-=(n-sz[c]) ;
      			else ans-=sz[v];
            if(u==p[0][c]) ans-=(n-sz[c]) ;
      			else ans-=sz[u];
            cout<< ans << endl ;
          }
      }
  }
