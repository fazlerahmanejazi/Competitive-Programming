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

int n, m, u, v, loops ;
bool check ;
lli ans ;
vvi adj ;
vi degree ;
vb visit, loop ;

lli ways(lli x)
  {
    return (x*(x-1))/2 ;
  }

void dfs(int u)
  {
    visit[u]=true ;
    for(auto v:adj[u])
      if(!visit[v])
        dfs(v) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    degree.assign(n+1, 0) ;
    loop.assign(n+1, false) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        if(u!=v)
          {
            adj[u].pb(v) ;
            adj[v].pb(u) ;
            degree[u]++ ;
            degree[v]++ ;
          }
        else loop[u]=true, loops++ ;
      }
    ans+=(lli)loops*(m-1) ;
    ans-=ways(loops) ;
    for(int i=1 ; i<=n ; i++)
      ans+=ways(degree[i]) ;
    check=false ;
    for(int i=1 ; i<=n ; i++)
      if(degree[i])
        {
          check=true ;
          dfs(i) ;
          break ;
        }
    for(int i=1 ; i<=n ; i++)
      if((!visit[i] && degree[i]) || (loop[i] && !degree[i]))
        check=false ;
    if(!check) ans=0 ;
    cout<< ans ;
  }
