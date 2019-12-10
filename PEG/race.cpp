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

const int N=200010 ;

lli n, k, u, v, w, res=INF ;
vector<vpii> adj(N) ;
vlli sz(N, 0) ;
vb del(N, false) ;
vector<pair<lli, lli>> temp ;
map<lli, lli> dp ;

void dfs(int u, int prev, lli dist, lli len)
  {
    if(dist>k) return ;
    if(dp.count(k-dist)) res=min(res, dp[k-dist]+len) ;
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev)
        dfs(v.fi, u, dist+v.se, len+1) ;
    temp.pb({dist, len}) ;
  }

void dfs_sz(int u, int prev)
  {
    sz[u]=1 ;
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev)
        {
          dfs_sz(v.fi, u) ;
          sz[u]+=sz[v.fi] ;
        }
  }

int find_centroid(int u, int prev, int r)
  {
    for(auto v:adj[u])
      if(!del[v.fi] && v.fi!=prev && sz[v.fi]>r)
        return find_centroid(v.fi, u, r) ;
    return u ;
  }

void decompose(int u)
  {
    dfs_sz(u, u) ;
    int c=find_centroid(u, u, sz[u]/2) ;
    del[c]=true ;
    dp.clear() ;
    dp[0]=0 ;
    for(auto v:adj[c])
      if(!del[v.fi])
        {
          temp.clear() ;
          dfs(v.fi, v.fi, v.se, 1) ;
          for(auto i:temp)
            if(!dp.count(i.fi)) dp[i.fi]=i.se ;
            else dp[i.fi]=min(dp[i.fi], i.se) ;
        }
    for(auto v:adj[c]) if(!del[v.fi]) decompose(v.fi) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb({v, w}) ;
        adj[v].pb({u, w}) ;
      }
    decompose(0) ;
    if(res==INF) res=-1 ;
    cout<< res ;
  }
