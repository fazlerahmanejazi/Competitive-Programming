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

int n, u, v, x ;
vvi adjA, adjB ;

void init()
  {
    adjA.clear() ; adjB.clear() ;
    adjA.resize(n+1) ; adjB.resize(n+1) ;
  }

bool check(int u, int v)
  {
    if(adjA[u].empty() && adjB[v].empty()) return true ;
    if(adjA[u].empty() || adjB[v].empty() || adjA[u].size()!=adjB[v].size()) return false ;
    if(adjA[u].size()==2) return (check(adjA[u][0], adjB[v][0]) && check(adjA[u][1], adjB[v][1]) || check(adjA[u][0], adjB[v][1]) && check(adjA[u][1], adjB[v][0])) ;
    else return check(adjA[u][0], adjB[v][0]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> x ;
            adjA[x].pb(i) ;
          }
        for(int i=1 ; i<=n ; i++)
          {
            cin>> x ;
            adjB[x].pb(i) ;
          }
        if(check(0, 0)) cout<< 1 << endl ;
        else cout<< 0 << endl ;
      }
  }
