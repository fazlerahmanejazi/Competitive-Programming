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

int n, m, k, q, t, x, y, l, r, ans, mid, monitor[501][501] ;
vector<tuple<int, int, int>> data ;

bool check(int z)
  {
    memset(monitor, 0, sizeof monitor) ;
    for(int i=0 ; i<data.size() ; i++)
      if(get<0>(data[i])>z) break ;
      else monitor[get<1>(data[i])][get<2>(data[i])]=1 ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        monitor[i][j]+=monitor[i-1][j]+monitor[i][j-1]-monitor[i-1][j-1] ;
    for(int i=k ; i<=n ; i++)
      for(int j=k ; j<=m ; j++)
        if(monitor[i][j]+monitor[i-k][j-k]-monitor[i-k][j]-monitor[i][j-k]==k*k)
          return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k >> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> x >> y >> t ;
        data.pb(mt(t, x, y)) ;
      }
    sort(all(data)) ;
    l=0 ; r=1e9 ; ans=inf ;
    while(l<=r)
      {
        mid=(l+r)/2 ;
        if(check(mid)) ans=min(ans, mid), r=mid-1 ;
        else l=mid+1 ;
      }
    if(ans==inf) cout<< -1 ;
    else cout<< ans ;
  }
