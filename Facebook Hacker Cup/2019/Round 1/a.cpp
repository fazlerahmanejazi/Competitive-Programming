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

lli n, m, u, v, w, d[100][100] ;
bool pos ;
vector<tuple<lli, lli, lli>> edges ;
vvi adj ;

void init()
  {
    adj.clear() ;
    edges.clear() ;
    adj.resize(n+1) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        d[i][j]=INF ;
    pos=true ;
  }

void floydWarshall()
  {
    for(int k=1 ; k<=n ; k++)
      for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
          if(d[i][k]<INF && d[k][j]<INF)
            d[i][j]=min(d[i][j], d[i][k]+d[k][j]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> m ;
        init() ;
        for(int i=1 ; i<=m ; i++)
          {
            cin>> u >> v >> w ;
            edges.pb(mt(w, u, v)) ;
            d[u][v]=d[v][u]=w ;
          }
        floydWarshall() ;
        for(auto e:edges)
          {
            tie(w, u, v)=e ;
            if(d[u][v]!=w) pos=false ;
          }
        cout<< "Case #" << tc << ": " ;
        if(pos)
          {
            edges.clear() ;
            for(int i=1 ; i<=n ; i++)
              for(int j=i+1 ; j<=n ; j++)
                if(d[i][j]!=INF)
                  edges.pb(mt(d[i][j], i, j)) ;
            cout<< edges.size() << endl ;
            for(auto e:edges)
              {
                tie(w, u, v)=e ;
                cout<< u << " " << v << " " << w << endl ;
              }
          }
        else cout<< "Impossible" << endl ;
      }
  }
