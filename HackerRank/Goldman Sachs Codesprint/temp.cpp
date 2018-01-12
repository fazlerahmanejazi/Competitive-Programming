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

lli n, x, s, f, m, graph[30][30], val, len ;
vvi adj(30) ;
set<int> nodes ;

void solve()
  {

  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    cin>> x >> s >> f >> m ;
    s++ ; f++ ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        {
          cin>> val ;
          graph[i][j]=val ;
          if(i!=j)adj[i].pb(j) ;
        }

  }
