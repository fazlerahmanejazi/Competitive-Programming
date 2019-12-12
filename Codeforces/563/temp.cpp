0#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
//#define endl '\n'
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

int n, u, v, x=1, y, tt=30 ;
vi sz(200005), dist(200005), par(200005), heavyChild(200005) ;
vvi adj(200005) ;

void dfs(int u, int prev)
  {
    int mx=-1, c=-1 ;
    par[u]=prev ;
    sz[u]++ ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          sz[u]+=sz[v] ;
          if(sz[v]>mx) mx=sz[v], c=v ;
        }
    heavyChild[u]=c ;
  }

int query(int u, char c)
  {
    int x ;
    cout<< c << " " << u << endl ;
    cin>> x ;
    return x ;
  }

int ternary_search(int s)
  {
    int d1, d2, m1, m2, mn, ans, lo, hi ;
    vi path ;
    while(s!=-1) path.pb(s), s=heavyChild[s] ;
    lo=0 ; hi=path.size()-1 ;
    while(lo<hi-2)
      {
      	m1=(lo*2+hi)/3 ;
      	m2=(lo+hi*2)/3 ;
        d1=query(path[m1], 'd') ;
        d2=query(path[m2], 'd') ;
      	if(d1>d2) hi=m2 ;
      	else lo=m1 ;
      }
    mn=query(path[lo], 'd') ;
    ans=path[lo] ;
    for(int i=lo+1 ; i<=hi ; i++)
      {
        d1=query(path[i], 'd') ;
        if(d1<mn) mn=d1, ans=path[i] ;
      }
    return ans ;
  }

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1) ;
    while(tt--)
      {
        y=ternary_search(x) ;
        if(y==x)
          {
            if(!query(x, 'd'))
              {
                cout<< "! " << x << endl ;
                return 0 ;
              }
            x=query(x, 's') ;
          }
        else x=y ;
        if(!query(x, 'd'))
          {
            cout<< "! " << x << endl ;
            return 0 ;
          }
      }
    cout<< x ;
  }
