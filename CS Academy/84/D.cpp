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

lli n, k, x, y, z, l, r, m, f1, f2, ans=INF ;
vector<pair<lli, lli>> a ;

lli check(lli m)
  {
    lli res=0 ;
    vlli b ;
    for(int i=0 ; i<n ; i++) b.pb(abs(a[i].fi-a[m].fi)+abs(a[i].se)) ;
    sort(all(b)) ;
    for(int i=0 ; i<k ; i++) res+=b[i] ;
    return res ;
  }

lli ternary_search(lli lo, lli hi)
  {
    while(lo<hi-2)
      {
      	lli m1=(lo*2+hi)/3 ;
      	lli m2=(lo+hi*2)/3 ;
      	if(check(m1)<check(m2)) hi=m2 ;
      	else lo=m1 ;
      }
    lli ans=check(lo) ;
    for(int i=lo+1 ; i<=hi ; i++) ans=min(ans, check(i)) ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    for(int i=0 ; i<n ; i++) cin>> x >> y, a.pb(mp(x, y)) ;
    sort(all(a)) ;
    ans=ternary_search(0, n-1) ;
    cout<< ans ;
  }
