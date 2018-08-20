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
    int n, m, x, y, z ;
    vpii edges ;
    cin>> n >> m ;
    if(m<n-1) return cout<< "Impossible", 0 ;
    z=m ;
    for(int i=2 ; i<=n ; i++) edges.pb(mp(1, i)), z-- ;
    for(int i=2 ; i<=n && z ; i++)
      for(int j=i+1 ; j<=n && z ; j++)
        if(__gcd(i, j)==1)
          edges.pb(mp(i, j)), z-- ;
    if(z>0) return cout<< "Impossible", 0 ;
    cout<< "Possible" << endl ;
    for(auto i:edges) cout<< i.fi << " " << i.se << endl ;
  }
