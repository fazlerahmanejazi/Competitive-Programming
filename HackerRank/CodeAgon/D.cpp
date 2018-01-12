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

int T, n, m, u, v, c, x, s ;
pair<lli, int> temp ;
lli ans ;
vector<vpii> adj ;
vb visit ;

void init()
  {
    adj.clear() ; adj.resize(n+1) ;
    visit.assign(n+1, false) ;
  }

pair<lli, int> dfs(int u)
  {
    int v, C, check, decide=1 ;
    lli curr=1, next ;
    visit[u]=true ;
    for(auto x:adj[u])
      {
        tie(v, C)=x ;
        if(!visit[v])
          {
            tie(next, check)=dfs(v) ;
            check*=C ;
            if(check) curr*=(next+1) ;
            decide*=check ;
          }
      }
    if(decide) return mp(curr, 1) ;
    else return mp(curr, 0) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=0 ; i<n-1 ; i++)
          {
            cin>> u >> v >> x ;
            if(x) s=u ;
            adj[u].pb(mp(v, 1-x)) ;
            adj[v].pb(mp(u, 1-x)) ;
          }
        temp=dfs(s) ;
        cout<< temp.fi << endl ;
      }
  }
