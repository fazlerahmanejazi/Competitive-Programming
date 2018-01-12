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

int in()
  {
    int x ;
    cin>> x ;
    return x ;
  }

ld dist(ld x1, ld y1, ld x2, ld y2)
  {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) ;
  }

ld area(ld r)
  {
    return pi*r*r ;
  }

ld calc(ld x, ld y, ld r, ld o)
  {
    ld tot=o*r*r ;
    tot-=r*r*sin(o)*cos(o) ;
    return tot ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    ld x1, x2, y1, y2, r1, r2, d, a, b ;
    x1=in() ; y1=in() ; r1=in() ;
    x2=in() ; y2=in() ; r2=in() ;
    d=dist(x1, y1, x2, y2) ;
    if(r1+r2<=d) cout<< 0 ;
    else if(abs(r2-r1)>=d) cout<< fixed << setprecision(12) << min(area(r1), area(r2)) ;
    else
      {
        a=acos((r1*r1+d*d-r2*r2)/(2*r1*d)) ;
        b=acos((r2*r2+d*d-r1*r1)/(2*r2*d)) ;
        cout<< fixed << setprecision(12) << calc(x1, y1, r1, a)+calc(x2, y2, r2, b) ;
      }
  }
