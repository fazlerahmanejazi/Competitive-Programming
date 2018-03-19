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

lli n, L, x, ans, m, res=INF ;
vlli c(50) ;
vb take(50) ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> L ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=2 ; i<=n ; i++) c[i]=min(c[i], 2*c[i-1]) ;
    m=n ;
    while(m>0)
      {
        x=L/((1LL<<(m-1))) ;
        if(!x) res=min(c[m]+ans, res) ;
        L-=x*((1LL<<(m-1))) ;
        ans+=c[m]*x ;
        m-- ;
      }
    ans+=c[1]*L ;
    cout<< min(ans, res) ;
  }
