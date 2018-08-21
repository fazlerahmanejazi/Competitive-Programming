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
    lli n, p, q, r, curr, ans=-4000000000000000010 ;
    cin>> n >> p >> q >> r ;
    vlli a(n), b(n), c(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    b[0]=p*a[0] ; c[n-1]=r*a[n-1] ;
    for(int i=1 ; i<n ; i++) b[i]=max(b[i-1], a[i]*p) ;
    for(int i=n-2 ; i>=0 ; i--) c[i]=max(c[i+1], a[i]*r) ;
    for(int i=0 ; i<n ; i++) ans=max(ans, b[i]+q*a[i]+c[i]) ;
    cout<< ans ;
  }
