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

int n, m, u, v, x, s, mx, ans, W, L, D, N, dp[200005], nxt[200005][4] ;
bool isCycle, oddCycle ;
vvi adj, dag ;
vi visit, topo, temp, C, T ;

void check(int u, int t)
  {
    visit[u]++ ;
    temp.pb(u) ;
    T[u]=t ;
    for(auto v:adj[u])
      if(!visit[v]) dag[u].pb(v), check(v, t+1) ;
      else if(visit[v]==1)
        {
          isCycle=true ;
          if((T[u]-T[v]+1)%2) oddCycle=1, temp.pb(v), C=temp ;
        }
      else dag[u].pb(v) ;
    temp.pop_back() ;
    visit[u]++ ;
  }

void dfs(int u)
  {
    visit[u]++ ;
    for(auto v:dag[u]) if(!visit[v]) dfs(v) ;
    topo.pb(u) ;
  }

void print(int s, int x)
  {
    while(nxt[s][x])
      {
        cout<< nxt[s][x] << " " ;
        s=nxt[s][x] ;
        x=1-x ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    adj.resize(n+1) ;
    T.resize(n+1) ;
    dag.resize(n+1) ;
    memset(dp, -1, sizeof dp) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        for(int j=0 ; j<x ; j++)
          {
            cin>> v ;
            adj[i].pb(v) ;
          }
      }
    cin>> s ;
    visit.assign(n+1, 0) ;
    check(s, 0) ;
    visit.assign(n+1, 0) ;
    dfs(s) ;
    for(auto u:topo)
      {
        W=L=D=N=0 ;
        for(auto v:dag[u])
          {
            if(dp[v]==0) L=v ;
            else if(dp[v]==1) W=v ;
            else if(dp[v]==2) D=v ;
            else N=1 ;
          }
        if(D) dp[u]=2, nxt[u][1]=nxt[u][0]=D ;
        else if(L && W) dp[u]=2, nxt[u][1]=L, nxt[u][0]=W ;
        else if(L) dp[u]=1, nxt[u][1]=L ;
        else if(W) dp[u]=0, nxt[u][0]=W ;
        else if(adj[u].empty()) dp[u]=0 ;
        else if(dag[u].empty() || N) dp[u]=-1 ;
      }
    if(dp[s]<=0)
      {
        if(isCycle)
          {
            if(oddCycle && !dp[s])
              {
                cout<< "Win" << endl ;
                for(auto i:C) cout<< i << " " ;
                s=C[C.size()-1] ;
                x=(T[C[C.size()-2]])%2 ;
                print(s, x) ;
              }
            else cout<< "Draw" ;
          }
        else cout<< "Lose" ;
      }
    else
      {
        cout<< "Win" << endl ;
        cout<< s << " " ;
        print(s, 1) ;
      }
  }
