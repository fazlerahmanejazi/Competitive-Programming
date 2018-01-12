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

#define ld long double

lli T, n, m, x, y, Aa, Bb, Cc, v, res, ans ;
ld aa, bb, cc ;
vector<pair<lli, lli>> r, b ;
vector<tuple<ld, lli, lli>> R, B ;

void input(vector<pair<lli, lli>> &p, int q)
  {
    p.clear() ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> x >> y ;
        p.pb(mp(x, y)) ;
      }
  }

lli distLine(lli x1, lli y1, lli x2, lli y2)
  {
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) ;
  }

ld distCentroid(lli x1, lli y1)
  {
    ld n, d ;
    n=abs((aa*x1+bb*y1+cc)) ;
    d=sqrt(aa*aa+bb*bb) ;
    return n/d ;
  }

void sortByLine()
  {
    lli rx=0, ry=0, bx=0, by=0 ;
    for(int i=0 ; i<n ; i++) rx+=r[i].fi, ry+=r[i].se ;
    for(int i=0 ; i<n ; i++) bx+=b[i].fi, by+=b[i].se ;
    rx/=n ; ry/=n ; bx/=m ; by/=m ;
    R.clear() ; B.clear() ;
    for(int i=0 ; i<n ; i++) R.pb(mt(distLine(rx, ry, r[i].fi, r[i].se), r[i].fi, r[i].se)) ;
    for(int i=0 ; i<m ; i++) B.pb(mt(distLine(bx, by, b[i].fi, b[i].se), b[i].fi, b[i].se)) ;
    sort(all(R)) ; sort(all(B)) ;
  }

void sortByCentroid()
  {
    ld rx=0, ry=0, bx=0, by=0, h, k ;
    for(int i=0 ; i<n ; i++) rx+=r[i].fi, ry+=r[i].se ;
    for(int i=0 ; i<m ; i++) bx+=b[i].fi, by+=b[i].se ;
    rx/=n ; ry/=n ; bx/=m ; by/=m ;
    h=(rx+bx)/2 ; k=(bx+by)/2 ;
    aa=bx-rx ;
    bb=by-ry ;
    cc=-k*(by-ry)-h*(bx-rx) ;
    R.clear() ; B.clear() ;
    for(int i=0 ; i<n ; i++) R.pb(mt(distCentroid(r[i].fi, r[i].se), r[i].fi, r[i].se)) ;
    for(int i=0 ; i<m ; i++) B.pb(mt(distCentroid(b[i].fi, b[i].se), b[i].fi, b[i].se)) ;
    sort(all(R)) ; sort(all(B)) ;
  }

void line(lli rx, lli ry, lli bx, lli by)
  {
    Aa=ry-by ;
    Bb=bx-rx ;
    Cc=rx*by-bx*ry ;
  }

lli val(lli x, lli y)
  {
    return Aa*x+Bb*y+Cc ;
  }

lli get()
  {
    lli rN=0, rP=0, bN=0, bP=0 ;
    for(int i=0 ; i<max(n, m) ; i++)
      {
        if(i<n)
          {
            v=val(r[i].fi, r[i].se) ;
            if(v<0) rN++ ;
            else if(v>0) rP++ ;
          }
        if(i<m)
          {
            v=val(b[i].fi, b[i].se) ;
            if(v<0) bN++ ;
            else if(v>0) bP++ ;
          }
        if(min(bP+rN, bN+rP)>=res) break ;
      }
    return min(bP+rN, bN+rP) ;
  }

lli solve(lli s1, lli e1)
  {
    res=inf ;
    for(int i=s1 ; i<min(e1, n) ; i++)
      for(int j=0 ; j<min(300LL, m) ; j++)
        {
          line(get<1>(R[i]), get<2>(R[i]), get<1>(B[j]), get<2>(B[j])) ;
          res=min(res, get()) ;
        }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m ;
        input(r, n) ; input(b, m) ;
        sortByLine() ;
        ans=solve(500, 700) ;
        sortByCentroid() ;
        ans=min(ans, solve(0, 500)) ;
        cout<< ans << endl ;
      }
  }
