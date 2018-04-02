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
    lli n, m, ans=0, curr ;
    cin>> n >> m ;
    vlli t(n), b(m) ;
    vvi a(n+1) ;
    for(int i=0 ; i<n ; i++) cin>> t[i] ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> b[i] ;
        a[upper_bound(all(t), b[i])-t.begin()].pb(b[i]) ;
      }
    if(!a[0].empty()) ans+=2*(t[0]-a[0][0]) ;
    if(!a[n].empty()) ans+=2*(a[n][a[n].size()-1]-t[n-1]) ;
    for(int i=1 ; i<n ; i++)
      if(!a[i].empty())
        {
          curr=min({t[i]-t[i-1], 2*(a[i][a[i].size()-1]-t[i-1]), 2*(t[i]-a[i][0])}) ;
          for(int j=0 ; j<a[i].size()-1 ; j++) curr=min(curr, 2*(a[i][j]-t[i-1]+t[i]-a[i][j+1])) ;
          ans+=curr ;
        }
    cout<< ans ;
  }
