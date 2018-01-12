#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, m, l, r, x, ans=0 ;
set<int> a ;
vi res ;
vector<vpii> adj(100005) ;
vi cnt(100005, 0) ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> l >> r ;
        adj[l].pb(mp(1, i)) ;
        adj[r+1].pb(mp(-1, i)) ;
        cnt[l]++ ;
        cnt[r+1]-- ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        cnt[i]+=cnt[i-1] ;
        if(!cnt[i]) ans++ ;
      }
    res.assign(m+1, ans) ;
    for(int i=1 ; i<=n ; i++)
      {
        for(auto p:adj[i])
          if(p.fi==1) a.insert(p.se) ;
          else a.erase(p.se) ;
        if(cnt[i]==1) res[*a.begin()]++ ;
      }
    for(int i=1 ; i<=m ; i++) cout<< res[i] << endl ;
  }
