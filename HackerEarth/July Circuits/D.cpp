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

int n, m, u, v, k, x, K ;
lli w, ans ;
vlli c ;
vector<vector<pair<int, vi>>> adj ;
vb taken, inc ;
priority_queue<tuple<lli, int, vi>> pq ;

void init()
  {
    adj.resize(n+1) ;
    c.resize(k+1) ;
    taken.assign(n+1, false) ;
    inc.assign(k+1, false) ;
  }

void process(int u)
  {
    lli curr=0 ;
    int v ;
    vi temp ;
    taken[u]=true ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        tie(v, temp)=adj[u][i] ;
        if(!taken[v])
          {
            for(int j=0 ; j<temp.size() ; j++)
              if(!inc[temp[j]])
                curr+=c[temp[j]] ;
            pq.push(mt(-curr, v, temp)) ;
          }

      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k ;
    init() ;
    for(int i=1 ; i<=k ; i++)
      cin>> c[i] ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> u >> v >> K ;
        vi temp ;
        for(int j=0 ; j<K ; j++)
          {
            cin>> x ;
            temp.pb(x) ;
          }
        adj[u].pb(mp(v, temp)) ;
      }
      process(1) ;
      while(!pq.empty())
        {
          vi temp ;
          tie(w, u, temp)=pq.top() ; pq.pop() ;
          if(!taken[u])
            {
              ans+=abs(w) ;
              for(int i=0 ; i<temp.size() ; i++)
                inc[temp[i]]=true ;
              process(u) ;
            }
        }
      cout<< ans ;
    }
