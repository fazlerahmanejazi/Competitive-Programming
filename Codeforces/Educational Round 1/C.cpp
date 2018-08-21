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
    int n, x, y ;
    long double m=10, curr ;
    vector<pair<long double, int>> angle ;
    pii ans ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        angle.pb(mp(atan2(1.0*y, 1.0*x), i+1)) ;
      }
    sort(all(angle)) ;
    for(int i=1 ; i<n ; i++)
      {
        curr=angle[i].fi-angle[i-1].fi ;
        if(curr<m) m=curr, ans={angle[i].se, angle[i-1].se} ;
      }
      curr=2*pi-(-angle[0].fi+angle[n-1].fi) ;
      if(curr<m) m=curr, ans={angle[n-1].se, angle[0].se} ;
      cout<< ans.fi << " " << ans.se ;
  }
