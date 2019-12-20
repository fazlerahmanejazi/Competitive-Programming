#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define For(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define int long long
#define ld long double

const int N=100*100+200 ;

lli n, k, x, start, finish, dist[N] ;
vector<vector<pair<lli, lli>>> tow, adj ;

void dijkstra()
  {
    for(int i=0 ; i<N ; i++) dist[i]=1000000000000000000 ;
    dist[start]=0 ;
    priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> pq ;
    pq.push(mp(0LL, start)) ;
    while(!pq.empty())
      {
        lli d, u ;
        tie(d, u)=pq.top() ; pq.pop() ;
        if(d>dist[u]) continue ;
        for(auto v:adj[u])
          if(dist[u]+v.ss<dist[v.ff])
            {
              dist[v.ff]=dist[u]+v.ss ;
              pq.push(mp(dist[v.ff], v.ff)) ;
            }
      }
  }

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin>>t;
  while(t--)
  {
    cin>> n >> k ;
    start=1 ;
    finish=n*n+n+1 ;
    adj.clear() ;
    adj.resize(finish+10) ;
    tow.clear() ;
    tow.resize(k+1) ;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            {
              cin>> x ;
              tow[x].pb(mp(i, j)) ;
            }
    for(int i=2 ; i<=k ; i++)
        {
          for(auto u:tow[i-1])
            for(auto v:tow[i])
              {
                int uu=u.first*n+u.second ;
                int vv=v.first*n+v.second ;
                adj[uu].pb(mp(vv, abs(v.first-u.first)+abs(v.second-u.second))) ;
              }
        }
    for(auto v:tow[1])
        {
          int vv=v.first*n+v.second ;
          adj[start].pb(mp(vv, 0)) ;
        }
    for(auto u:tow[k])
        {
          int uu=u.first*n+u.second ;
          adj[uu].pb(mp(finish, 0)) ;
        }
    dijkstra() ;
    cout<< dist[finish] << endl ;
  }
  return 0;
}
