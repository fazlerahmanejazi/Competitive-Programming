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

lli n, L, x, l, r, ans, m, idx, cap, res=INF, q ;
vlli c(50) ;
vector<pair<long double, lli>> data ;

bool check(lli x)
  {
    lli V=0 ;
    for(auto d:data)
      {
        idx=d.se ;
        if(c[idx]>x) continue ;
        q=x/c[idx]  ;
        cap=1LL<<(idx-1) ;
        if(q>INF/cap) return true ;
        V+=q*cap ;
        x%=c[idx] ;
        if(V>=L) return true ;
      }
    return (V>=L) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> L ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=2 ; i<=n ; i++) c[i]=min(c[i], 2*c[i-1]) ;
    for(int i=1 ; i<=n ; i++) data.pb(mp(c[i]*1.0/(1LL<<(i-1))*1.0, i)) ;
    sort(all(data)) ;
    l=0 ; r=INF ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m)) r=m-1, res=min(res, m) ;
        else l=m+1 ;
      }
    cout<< res ;
  }
