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

int n, q, u, v, x, s, e, idx, mx, t ;
double mean, median, mode ;
vvi adj ;
vi freq, a, val ;

void dfs(int u, int prev)
  {
    freq[val[u]]++ ;
    a.pb(val[u]) ;
    if(u==e)
      {
        sort(all(a)) ;
        idx=a.size()/2 ;
        if(a.size()%2==0) median=(a[idx]+a[idx-1])/2.0 ;
        else median=a[idx] ;
        mean=mx=0 ;
        for(auto i:a) mean+=i ;
        mean/=a.size() ;
        for(int i=1 ; i<=100000 ; i++) if(freq[i]>mx) mx=freq[i], mode=i ;
        if(t==1) cout<< round(mean) << endl ;
        else if(t==2) cout<< round(median) << endl ;
        else cout<< round(mode) << endl ;
      }
    for(auto v:adj[u]) if(v!=prev) dfs(v, u) ;
    a.pop_back() ;
    freq[val[u]]-- ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    adj.resize(n+1) ;
    val.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> val[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=1 ; i<=q ; i++)
      {
        cin>> t >> s >> e ;
        a.clear() ;
        freq.assign(100005, 0) ;
        dfs(s, -1) ;
      }
  }
