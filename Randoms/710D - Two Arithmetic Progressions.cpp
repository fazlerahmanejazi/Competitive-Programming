#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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

lli a1, a2, b1, b2, L, R, x, y, a, b, d, c, ans, l, r, ansL, ansR ;

void extendedEuclid(lli a, lli b)
  {
    if(b==0)
      {
        x=1 ; y=0 ;
        d=a ;
        return ;
      }
    extendedEuclid(b, a%b) ;
    lli x1=y ;
    lli y1=x-(a/b)*y ;
    x=x1 ;
    y=y1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> a1 >> b1 >> a2 >> b2 >> L >> R ;
    a=a1 ; b=-a2 ; c=b2-b1 ;
    extendedEuclid(a, b) ;
    if(c%d)
      {
        cout<< 0 ;
        return 0 ;
      }
    if(d<0) tie(d, x, y)=mt(-d, -x, -y) ;
    l=max(0LL, (lli)ceil(1.0*(L-b1)/a1)) ;
    r=floor(1.0*(R-b1)/a1) ;
    ansL=(lli)ceil(1.0*(r*d-c*x)/(-a2)) ;
    ansR=(lli)floor(1.0*(l*d-c*x)/(-a2)) ;
    ansR=min(ansR, (lli)floor(1.0*c*y/a1)) ;
    l=max(0LL, (lli)ceil(1.0*(L-b2)/a2)) ;
    r=floor(1.0*(R-b2)/a2) ;
    ansL=max(ansL, (lli)ceil(1.0*(r*d-c*y)/(-a1))) ;
    ansR=min(ansR, (lli)floor(1.0*(l*d-c*y)/(-a1))) ;
    ans=ansR-ansL+1 ;
    ans=max(ans, 0LL) ;
    cout<< ans ;
  }
