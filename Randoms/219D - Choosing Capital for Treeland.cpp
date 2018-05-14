#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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

int n, s, t, ans=inf ;
vb visit ;
vector<vpii> adj ;
vi dp ;

void dfs(int u)
  {
    visit[u]=true ;
    int v, c ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        tie(v, c)=adj[u][i] ;
        if(!visit[v])
          {
            dp[1]+=c ;
            dfs(v) ;
          }
      }
  }

void solve()
  {
    visit.assign(n+1, false) ;
    queue<pii> q ;
    int x, c ;
    visit[1]=true ;
    for(int i=0 ; i<adj[1].size() ; i++)
      {
        tie(x, c)=adj[1][i] ;
        if(c) q.push(mp(x, -1+dp[1])) ;
        else q.push(mp(x, 1+dp[1])) ;

      }
    while(!q.empty())
      {
        tie(x, c)=q.front() ; q.pop() ;
        if(!visit[x])
          {
            visit[x]=true ;
            dp[x]=c ;
            for(int i=0 ; i<adj[x].size() ; i++)
              {
                int v, d ;
                tie(v, d)=adj[x][i] ;
                if(!visit[v])
                  if(d) q.push(mp(v, -1+dp[x])) ;
                  else q.push(mp(v, 1+dp[x])) ;
              }
          }
      }
    for(int i=1 ; i<=n ; i++)
      ans=min(ans, dp[i]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    dp.assign(n+1, 0) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> s >> t ;
        adj[s].pb(mp(t, 0)) ;
        adj[t].pb(mp(s, 1)) ;
      }
    dfs(1) ;
    solve() ;
    cout<< ans << endl ;
    for(int i=1 ; i<=n ; i++)
      if(dp[i]==ans)
        cout<< i << " " ;
  }
