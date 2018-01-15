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

bool pos=true ;
int n, m, u, v, x, cnt ;
vvi adj ;
vi temp, cycle, nxt, visit ;

void findCycle(int u, int edge)
  {
    temp.pb(edge) ;
    visit[u]++ ;
    for(auto i:adj[u])
      if(!visit[nxt[i]]) findCycle(nxt[i], i) ;
      else if(visit[nxt[i]]==1)
        {
          cycle=temp ;
          cycle.pb(i) ;
          pos=false ;
        }
    visit[u]++ ;
    temp.pop_back() ;
  }

void check(int u)
  {
    visit[u]++ ;
    for(auto i:adj[u])
      if(i!=x)
        {
          if(!visit[nxt[i]]) check(nxt[i]) ;
          else if(visit[nxt[i]]==1) cnt++ ;
        }
    visit[u]++ ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, 0) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(i) ;
        nxt.pb(v) ;
      }
    for(int i=1 ; i<=n ; i++) if(!visit[i]) findCycle(i, -1) ;
    for(auto i:cycle)
      {
        x=i ;
        cnt=0 ;
        visit.assign(n+1, false) ;
        for(int i=1 ; i<=n ; i++) if(!visit[i]) check(i) ;
        if(!cnt) pos=true ;
      }
    if(pos) cout<< "YES" ;
    else cout<< "NO" ;
  }
