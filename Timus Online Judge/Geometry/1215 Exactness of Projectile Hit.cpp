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

#define pi acos(-1.0)
#define eps 1e-8

int n ;
double x, y, cx, cy, p, d, curr, ans=inf ;
vector<pair<double, double>> point ;

double dist(double x1, double y1, double x2, double y2)
  {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) ;
  }

double solve(int i, int j)
  {
    double r, s, t, a, b, c, d, ans, x, y ;
    tie(a, b)=point[i] ; tie(c, d)=point[j] ;
    x=cx ; y=cy ;
    r=dist(a, b, x, y) ; s=dist(c, d, x, y) ; t=dist(a, b, c, d) ;
    ans=abs(x*(d-b)-y*(c-a)-a*d+b*c)/sqrt((d-b)*(d-b)+(c-a)*(c-a)) ;
    r=sqrt(r*r-ans*ans) ; s=sqrt(s*s-ans*ans) ;
    if(r+s-t>eps) ans=min(dist(a, b, x, y), dist(c, d, x, y)) ;
    return 2*ans ;
  }

bool insidePolygon()
  {
    bool check=false ;
    for(int i=0, j=n-1 ; i<n ; j=i++)
      if((point[i].se>cy)!=(point[j].se>cy) && (cx<(point[j].fi-point[i].fi)*(cy-point[i].se)/(point[j].se-point[i].se)+point[i].fi))
        check=!check ;
    return check ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> cx >> cy >> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        point.pb(mp(x, y)) ;
      }
    d=inf ;
    if(insidePolygon()) ans=0 ;
    else
      {
        ans=min(ans, solve(n-1, 0)) ;
        for(int i=1 ; i<n ; i++)
          ans=min(ans, solve(i, i-1)) ;
      }
    cout<< fixed << setprecision(3) << ans ;
  }
