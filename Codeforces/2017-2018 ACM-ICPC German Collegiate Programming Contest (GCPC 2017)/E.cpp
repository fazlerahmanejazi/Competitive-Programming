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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, m, u, v ;
    long double c ;
    cin>> n >> m ;
    vector<vector<long double>> adj(n+1, vector<long double>(n+1, 0)) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v >> c ;
        adj[u][v]=max(c, adj[u][v]) ;
      }
    for(int k=1 ; k<=n ; k++)
      for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
          {
            adj[i][j]=max(adj[i][j], adj[i][k]*adj[k][j]) ;
            if(i==j && adj[i][j]>1)
              {
                cout<< "inadmissible" ;
                return 0 ;
              }
          }
    cout<< "admissible" ;
  }
