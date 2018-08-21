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

lli n, m, u, a, b, w, ans, tot ;
pair<lli, lli> temp ;
vector<bool> visit;
vector<vector<pair<lli, lli>>> adj ;
priority_queue<pair<lli, lli>> pq ;

lli prim()
  {
    lli ans=0 ;
    visit[1]=true ;
    for(auto v:adj[1]) if(!visit[v.fi]) pq.push(mp(-v.se, -v.fi)) ;
    while(!pq.empty())
      {
        auto x=pq.top() ;
        pq.pop() ;
        w=-x.fi ; u=-x.se ;
        if(!visit[u])
          {
            ans+=w ;
            visit[u]=true ;
            for(auto v:adj[u]) if(!visit[v.fi]) pq.push(mp(-v.se, -v.fi)) ;
          }
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    for(int T=2 ; T<=200 ; T++)
      {
        n=T ;
        visit.clear() ;
        adj.clear() ;
        visit.assign(n+1, false) ;
        adj.resize(n+1) ;
        for(lli i=0 ; i<n ; i++)
          for(lli j=0 ; j<n ; j++)
            if(i!=j)
              {
                adj[i].pb(mp(j, i^j)) ;
                adj[j].pb(mp(i, i^j)) ;
              }
        ans=0 ;
        lli x=prim() ;
        //cout<<  T << " "  ;
        cout<< x << endl ;
      }

  }
