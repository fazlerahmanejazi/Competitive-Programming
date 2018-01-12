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

int n, u, v ;
vi a, cnt, ans ;
vvi adj ;

void init()
  {
    a.resize(n+1) ;
    adj.resize(n+1) ;
    cnt.assign(200000+5, 0) ;
    ans.resize(n+1) ;
  }

void modify(int x, int p)
  {
    for(int i=1 ; i<=sqrt(x) ; i++)
      if(x%i==0)
        {
          if(x/i==i) cnt[i]+=p ;
          else cnt[i]+=p, cnt[x/i]+=p ;
        }
  }

int check(int x, int d)
  {
    int res=1 ;
    for(int i=1 ; i<=sqrt(x) ; i++)
      if(x%i==0)
        {
          if(cnt[i]>=d) res=max(res, i) ;
          if(cnt[x/i]>=d) res=max(res, x/i) ;
        }
    return res ;
  }

void dfs(int u, int prev, int d)
  {
    modify(a[u], 1) ;
    ans[u]=max(check(a[u], d), check(a[1], d)) ;
    for(auto v:adj[u]) if(v!=prev) dfs(v, u, d+1) ;
    modify(a[u], -1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1, 0) ;
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
