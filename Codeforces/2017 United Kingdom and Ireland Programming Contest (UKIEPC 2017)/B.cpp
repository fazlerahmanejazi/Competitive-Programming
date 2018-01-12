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
#define x first
#define y second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, X, Y ;
double ans, curr ;
vpii points ;
vpii hull ;

int orientation(pii p, pii q, pii r)
  {
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y) ;
    if(val==0) return 0 ;
    return (val>0)?1:2 ;
  }

void convexHull()
  {
    if(n<3) return ;
    int l=0 ;
    for(int i=1 ; i<n ; i++) if(points[i].x<points[l].x) l=i ;
    int p=l, q ;
    do
      {
        hull.push_back(points[p]) ;
        q=(p+1)%n ;
        for(int i=0 ; i<n ; i++) if(orientation(points[p], points[i], points[q])==2) q=i ;
        p=q ;
      } while(p!=l) ;
  }

double dist(int i, int j, double cx, double cy)
  {
    double a, b, c, d ;
    tie(a, b)=hull[i] ; tie(c, d)=hull[j] ;
    return abs(cx*(d-b)-cy*(c-a)-a*d+b*c)/sqrt((d-b)*(d-b)+(c-a)*(c-a)) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> X >> Y  ;
        points.pb(mp(X, Y)) ;
      }
    convexHull() ;
    ans=inf ;
    for(int i=0 ; i<hull.size()-1 ; i++)
      {
        curr=-1 ;
        for(int j=0 ; j<n ; j++)
          curr=max(curr, dist(i, i+1, points[j].x, points[j].y)) ;
        ans=min(curr, ans) ;
      }
    curr=-1 ;
    for(int j=0 ; j<n ; j++)
      curr=max(curr, dist(0, hull.size()-1, points[j].x, points[j].y)) ;
    ans=min(curr, ans) ;
    cout<< fixed << setprecision(9) << ans ;
  }
