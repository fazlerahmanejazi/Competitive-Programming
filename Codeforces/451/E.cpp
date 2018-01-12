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

lli n, x, res ;
vlli sq ;
vector<pair<lli, lli> > a ;

lli get(lli x)
  {
    lli idx=upper_bound(all(sq), x)-sq.begin() ;
    lli ans=sq[idx]-x ;
    if(idx) ans=min(ans, abs(sq[idx-1]-x)) ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(lli i=0 ; i<=sqrt(1000000000)+5 ; i++) sq.pb(i*i) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.pb(mp(get(x), x)) ;
      }
    sort(all(a)) ;
    for(int i=0 ; i<n/2 ; i++) res+=a[i].fi ;
    for(int i=n/2 ; i<n ; i++)
      if(!a[i].fi && !a[i].se) res+=2 ;
      else if(!a[i].fi) res++ ;
    cout<< res ;
  }
