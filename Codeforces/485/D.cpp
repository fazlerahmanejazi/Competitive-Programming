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

int n, m, s, k, u, v, x, ans, dist[205][200005] ;
vvi adj(200005), idx(205), costs(200005) ;
vi a(200005) ;
vb visit ;

void bfs(int start)
  {
    queue<int> q ;
    visit.assign(200005, false) ;
    visit[start]=true ;
    dist[start-n][start]=0 ;
    q.push(start) ;
    while(!q.empty())
      {
        u=q.front() ; q.pop() ;
        for(auto v:adj[u])
          if(!visit[v])
            {
              q.push(v) ;
              dist[start-n][v]=dist[start-n][u]+1 ;
              visit[v]=true ;
            }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k >> s ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a[i] ;
        idx[a[i]].pb(i) ;
      }
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    for(int i=n+1 ; i<=n+k ; i++)
      {
        for(auto j:idx[i-n]) adj[i].pb(j) ;
        bfs(i) ;
        for(int j=1 ; j<=n ; j++) costs[j].pb(dist[i-n][j]-1) ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        sort(all(costs[i])) ;
        ans=0 ;
        for(int j=0 ; j<s ; j++) ans+=costs[i][j] ;
        cout<< ans << " " ;
      }
  }
