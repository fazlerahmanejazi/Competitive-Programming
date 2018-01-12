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

lli n, mx, x, diff, ans, cnt, y ;
vlli nine ;

lli get(lli x)
  {
    int idx=upper_bound(all(nine), x)-nine.begin() ;
    return nine[idx] ;
  }

lli digit(lli x)
  {
    int cnt=0 ;
    while(x) cnt++, x/=10 ;
    return cnt ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    nine.pb(0) ;
    for(lli i=1 ; i<12 ; i++) nine.pb(nine[i-1]*10+9) ;
    cin>> n ;
    mx=get(n) ;
    if(2*n-1<mx) mx/=10 ;
    x=digit(mx) ;
    y=1 ;
    while(x--) y*=10 ;
    while(2*n-1>=mx)
      {
        x=mx-min(mx-1, n) ;
        diff=min(mx-1, n)-x+1 ;
        ans+=diff/2 ;
        mx+=y ;
      }
    cout<< ans ;
  }
