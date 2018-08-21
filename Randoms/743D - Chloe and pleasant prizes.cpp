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

int n, u, v, x ;
vi a ;
vvi adj ;
vb visit ;
vlli pre, val ;
lli ans ;

void init()
  {
    ans=-2*INF ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    a.resize(n+1) ;
    val.resize(n+1) ;
    pre.resize(n+1) ;
  }

void dfs(int u)
  {
    visit[u]=true ;
    int v ;
    pre[u]=a[u] ;
    lli maxm=-2*INF ;
    vlli temp={-2*INF, -2*INF} ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        v=adj[u][i] ;
        if(!visit[v])
          {
            dfs(v) ;
            pre[u]+=pre[v] ;
            maxm=max(val[v], maxm) ;
            temp.pb(val[v]) ;
          }
      }
    val[u]=max(maxm, pre[u]) ;
    sort(all(temp)) ;
    if(temp[temp.size()-1]!=-2*INF && temp[temp.size()-2]!=-2*INF)
      ans=max(ans, temp[temp.size()-1]+temp[temp.size()-2]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<=n ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1) ;
    if(ans==-2*INF) cout<< "Impossible" ;
    else cout<< ans ;
  }
