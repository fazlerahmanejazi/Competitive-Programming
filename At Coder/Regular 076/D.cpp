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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, X, Y ;
    lli ans=0 ;
    pii temp ;
    cin>> n ;
    vector<pair<int, int>> x, y ;
    vector<vpii> adj(n+1) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> X >> Y ;
        x.pb(mp(X, i)) ;
        y.pb(mp(Y, i)) ;
      }
    sort(all(x)) ;
    sort(all(y)) ;
    for(int i=1 ; i<n ; i++)
      {
        adj[x[i].se].pb(mp(x[i-1].se, abs(x[i-1].fi-x[i].fi))) ;
        adj[x[i-1].se].pb(mp(x[i].se, abs(x[i-1].fi-x[i].fi))) ;
        adj[y[i].se].pb(mp(y[i-1].se, abs(y[i-1].fi-y[i].fi))) ;
        adj[y[i-1].se].pb(mp(y[i].se, abs(y[i-1].fi-y[i].fi))) ;
      }
    priority_queue<pii> pq ;
    vb taken(n+1, false) ;
    taken[1]=true ;
    for(int i=0 ; i<adj[1].size() ; i++)
      {
        temp=adj[1][i] ;
        if(!taken[temp.fi])
          pq.push(mp(-temp.se, temp.fi)) ;
      }
    while(!pq.empty())
      {
        temp=pq.top() ; pq.pop() ;
        int u=temp.se ; lli w=-temp.fi ;
        if(!taken[u])
          {
            ans+=w ;
            taken[u]=true ;
            for(int i=0 ; i<adj[u].size() ; i++)
              {
                temp=adj[u][i] ;
                if(!taken[temp.fi])
                  pq.push(mp(-temp.se, temp.fi)) ;
              }
          }
      }
    cout<< ans ;
  }
