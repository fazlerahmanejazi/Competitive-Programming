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

lli n, x, y, u, v, ans, p, q ;
vb a, b ;
vvi adj ;

void dfsX(int u, int prev, int t)
  {
    if(u==y) t=1 ;
    if(!t) a[u]=true ;
    for(auto v:adj[u]) if(v!=prev) dfsX(v, u, t) ;
  }

void dfsY(int u, int prev, int t)
  {
    if(u==x) t=1 ;
    if(!t) b[u]=true ;
    for(auto v:adj[u]) if(v!=prev) dfsY(v, u, t) ;
  }

void dfsXX(int u, int prev, int t)
  {
    if(u==y) t=1 ;
    if(t==1) a[u]=false ;
    for(auto v:adj[u]) if(v!=prev) dfsXX(v, u, t) ;
  }

void dfsYY(int u, int prev, int t)
  {
    if(u==x) t=1 ;
    if(t==1) b[u]=false ;
    for(auto v:adj[u]) if(v!=prev) dfsYY(v, u, t) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> x >> y ;
    adj.resize(n+1) ;
    a.assign(n+1, false) ;
    b.assign(n+1, false) ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfsX(x, -1, 0) ;
    dfsY(y, -1, 0) ;
    dfsXX(x, -1, 0) ;
    dfsYY(y, -1, 0) ;
    ans=n*(n-1) ;
    for(int i=1 ; i<=n ; i++)
      {
        if(a[i] && !b[i]) p++ ;
        if(b[i] && !a[i]) q++ ;
      }
    ans-=p*q ;
    cout<< ans ;
  }
