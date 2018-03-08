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

int n, x, u, v, res=inf, city, curr ;
vector<vpii> adj ;

int calc(int s)
  {
    queue<int> q ;
    vi dist(n+1, inf) ;
    q.push(s) ;
    dist[s]=0 ;
    int ans=0 ;
    while(!q.empty())
      {
        u=q.front() ; q.pop() ;
        for(auto v:adj[u])
          if(dist[v.fi]>dist[u]+v.se)
            {
              q.push(v.fi) ;
              dist[v.fi]=dist[u]+v.se ;
            }
      }
    for(int i=1 ; i<=n ; i++) ans=max(ans, dist[i]) ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    adj.resize(n+1) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        u=i ;
        if(i==n) v=1 ;
        else v=i+1 ;
        adj[u].pb(mp(v, x)) ;
        adj[v].pb(mp(u, x)) ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        curr=calc(i) ;
        if(curr<res) res=curr, city=i ;
      }
    cout<< city ;
  }
