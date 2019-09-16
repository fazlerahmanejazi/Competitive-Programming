#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple/
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

const int N=200010 ;

lli n, m, u, v, r_time, t_time, r_len, t_len, r_total, t_total, r_curr, t_curr, curr_sleep, curr_pos ;
vlli first(N), second(N), path_rabbit(N), path_turtle(N),
dist_temp(N), dist(N), time_rabbit(N), time_turtle(N), sleep(N), ans  ;
vvi adj(N), adj_rev(N) ;
vb allowed(N) ;

void dijkstra(int start, vlli &dist)
  {
    for(int i=1 ; i<=n ; i++) dist[i]=INF ;
    dist[start]=0 ;
    priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> pq ;
    pq.push(mp(0LL, start)) ;
    lli d, u ;
    while(!pq.empty())
      {
        tie(d, u)=pq.top() ; pq.pop() ;
        if(d>dist[u]) continue ;
        for(auto e:adj_rev[u])
          {
            auto v=first[e] ;
            auto w=time_rabbit[e] ;
            if(dist[u]+w<dist[v])
              {
                dist[v]=dist[u]+w ;
                pq.push(mp(dist[v], v)) ;
              }
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> first[i] >> second[i] >> time_turtle[i] >> time_rabbit[i] ;
        adj[first[i]].pb(i) ;
        adj_rev[second[i]].pb(i) ;
      }
    cin>> t_len ;
    lli tot=0 ;
    for(int i=1 ; i<=t_len ; i++)
      {
        cin>> path_turtle[i] >> sleep[i] ;
        if(i!=t_len) tot+=sleep[i] ;
        t_total+=time_turtle[path_turtle[i]] ;
      }
    cin>> r_len ;
    for(int i=1 ; i<=r_len ; i++)
      {
        cin>> path_rabbit[i] ;
        allowed[path_rabbit[i]]=true ;
        r_total+=time_rabbit[path_rabbit[i]] ;
      }
    dijkstra(n, dist_temp) ;
    for(int i=1 ; i<=n ; i++)
      {
        dist[i]=INF ;
        for(auto idx:adj[i])
          if(!allowed[idx])
            dist[i]=min(dist[i], dist_temp[second[idx]]+time_rabbit[idx]) ;
        if(dist[i]!=dist_temp[i]) dist[i]=INF ;
      }
    curr_pos=1 ;
    for(int i=1, j=1 ; i<=r_len ; i++)
      {
        while(j<=t_len && t_curr+curr_sleep<=r_curr)
          {
            t_curr+=time_turtle[path_turtle[j]] ;
            curr_sleep+=sleep[j-1] ;
            j++ ;
          }
        if(r_curr+dist[first[path_rabbit[i]]]<r_total && r_curr+dist[first[path_rabbit[i]]]<=t_total-(tot-curr_sleep))
          ans.pb(first[path_rabbit[i]]) ;
      }
    cout<< ans.size() << endl ;
    for(auto i:ans) cout<< i << " " ;
  }
