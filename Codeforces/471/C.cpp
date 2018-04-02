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

lli q, L, R, ans ;
vlli a, b ;

lli root(lli x)
  {
    lli l=0, r=1e9+1, m ;
    while(l<r-1)
      {
        m=(l+r)/2 ;
        if(m*m>x) r=m ;
        else l=m ;
      }
      return l ;
  }

void pre()
  {
    lli x, y ;
    for(lli i=2 ; i<=1000000 ; i++)
      {
        x=i*i*i ;
        while(1)
          {
            y=root(x) ;
            if(y*y!=x) a.pb(x) ;
            if(x>INF/i) break ;
            x*=i ;
          }
      }
    sort(all(a)) ;
    b.pb(a[0]) ;
    for(int i=1 ; i<a.size() ; i++) if(a[i]!=a[i-1]) b.pb(a[i]) ;
  }

lli query()
  {
    cin>> L >> R ;
    ans=root(R)-root(L-1) ;
    ans+=upper_bound(all(b), R)-lower_bound(all(b), L) ;
    cout<< ans << endl ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    pre() ;
    cin>> q ;
    while(q--) query() ;
  }
