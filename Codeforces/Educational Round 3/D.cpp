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

lli n, m, k, s, t, x, l, r, mid, day, d1, d2 ;
vector<pair<lli, lli>> gadget ;
vlli a, b, dollar, pound ;

bool check(lli x)
  {
    lli cost=0 ;
    vlli temp ;
    for(auto i:gadget)
      if(i.fi==1) temp.pb(i.se*a[x]) ;
      else temp.pb(i.se*b[x]) ;
    sort(all(temp)) ;
    for(int i=0 ; i<k ; i++) cost+=temp[i] ;
    if(cost<=s) return true ;
    return false ;
  }

void print()
  {
    cout<< day+1 << endl ;
    vector<tuple<lli, lli, lli>> ans ;
    for(int i=0 ; i<=day ; i++)
      {
        if(dollar[i]==a[day]) d1=i ;
        if(pound[i]==b[day]) d2=i ;
      }
    for(int i=0 ; i<m ; i++)
      if(gadget[i].fi==1) ans.pb(mt(gadget[i].se*a[d1], i+1, d1+1)) ;
      else ans.pb(mt(gadget[i].se*b[d2], i+1, d2+1)) ;
    sort(all(ans)) ;
    for(int i=0 ; i<k ; i++) cout<< get<1>(ans[i]) << " " << get<2>(ans[i]) << endl ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k >> s ;
    a.resize(n+1) ; b.resize(n+1) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=0 ; i<n ; i++) cin>> b[i] ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> t >> x ;
        gadget.pb(mp(t, x)) ;
      }
    dollar=a ; pound=b ;
    for(int i=1 ; i<n ; i++) a[i]=min(a[i-1], a[i]), b[i]=min(b[i-1], b[i]) ;
    l=0 ; r=n-1 ; day=inf ;
    while(l<=r)
      {
        mid=(l+r)/2 ;
        if(check(mid)) r=mid-1, day=min(day, mid) ;
        else l=mid+1 ;
      }
    if(day!=inf) print() ;
    else cout<< -1 ;
  }
