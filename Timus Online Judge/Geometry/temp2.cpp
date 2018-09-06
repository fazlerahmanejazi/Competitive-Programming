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
using pii = pair<lli, lli> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<lli, lli>> ;

#define double long double

class Point
  {
    public:
    double x, y ;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}

    Point operator-(const Point &p) const { return Point(x-p.x, y-p.y) ; }
    bool operator==(const Point &p) const { return p.x==x && p.y==y ; }
    Point operator+(const Point &p) const { return Point(x+p.x, y+p.y) ; }
    Point operator/(long long t) const { return Point(x/t, y/t) ; }
    Point operator*(const double&t) const { return Point(x*t, y*t) ; }
    double operator*(const Point&p) const { return x*p.x+y*p.y ; }

    double length() const { return x*x+y*y ; }

    double distToLineSegment(Point v, Point w) // Distance-squared to the line between v and w
      {
        Point p={x, y} ;
        Point wv=w-v ;
        Point pv=p-v ;
        float res=(wv*((pv*wv)/(wv.length()))-pv).length() ;
        return res ;
      }
  } ;

int n, x, y, X, Y ;
double px, py, qx, qy ;
vector<tuple<int, int, int, int>> square ;
vector<pair<double, int>> data ;
Point P, A, B ;

bool insideSquare()
  {
    return (min(px, qx)<=P.x && P.x<=max(px, qx) && min(py, qy)<=P.y && P.y<=max(py, qy)) ;
  }

double pointToSquare(tuple<int, int, int, int> s)
  {
    tie(px, py, qx, qy)=s ;
    if(insideSquare()) return 0 ;
    ld res ;
    A={px, py} ; B={px, qy} ;
    res=P.distToLineSegment(A, B) ;
    A={px, py} ; B={qx, py} ;
    res=min(res, P.distToLineSegment(A, B)) ;
    A={qx, py} ; B={qx, qy} ;
    res=min(res, P.distToLineSegment(A, B)) ;
    A={px, qy} ; B={qx, qy} ;
    res=min(res, P.distToLineSegment(A, B)) ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y >> X >> Y ;
        if(x>X) swap(x, X), swap(y, Y) ;
        square.pb(mt(x, y, X, Y)) ;
      }
    cin>> x >> y ;
    P={x, y} ;
    for(int i=0 ; i<n ; i++) data.pb(mp(pointToSquare(square[i]), i+1)) ;
    sort(all(data)) ;
    for(int i=0 ; i<n ; i++) cout<< data[i].se << " " ;
  }
