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

    double distToLine(Point v, Point w) // Distance-squared to the line between v and w
      {
        Point p={x, y} ;
        if(w==v) return (v-p).length() ;
        Point wv=w-v ;
        Point pv=p-v ;
        double res=(wv*((pv*wv)/(wv.length()))-pv).length() ;
        return res ;
      }

    double distToLineSegment(Point v, Point w) // Distance-squared to the line between v and w
      {
        Point p={x, y} ;
        if(w==v) return (v-p).length() ;
        Point wv=w-v ;
        Point pv=p-v ;
        double t=(p-v)*(w-v)/(w-v).length() ;
        if(t<0 || 1<t) return min((w-p).length(), (v-p).length()) ;
        else return p.distToLine(v, w) ;
      }
  } ;

class Square
  {
    public:
    vector<Point> points ;

    Square(lli x1, lli y1, lli x2, lli y2)
      {
        Point a(x1, y1), b, c(x2, y2), d ;
        // The opposite points are given, so the remaining two vectors are calculated by taking the
        // half-way vector between those two points and adding it to itself, rotated +-90 degrees
        Point cent=(c-a)/2 ;
        b=a+cent+Point{-cent.y, cent.x} ;
        d=a+cent-Point{-cent.y, cent.x} ;
        points={a, b, c, d} ;
      }

    double distanceToPoint(Point p)
      {
        double ans=INF ;
        bool inside=true ;
        for(int i=0 ; i<4 ; i++) // For each side of the square
          {
            Point w=points[(i+1)%4] ;
            Point v=points[i] ;
            if(v==w)
              {
                ans=min(ans, (v-p).length()) ;
                continue ;
              }
            Point u=w-v ;
            Point P=p-v ;
            // We're inside the square if all sides of the square are to the right
            // of the query point, in a cross-product sense
            inside&=double(0)<(P.x*u.y-P.y*u.x) ;
            double t=(p-v)*(w-v)/(w-v).length() ;
            if(t<0 || 1<t) ans=min(ans, min((w-p).length(), (v-p).length())) ;
            else ans=min(p.distToLineSegment(v, w), ans) ;
          }
        if(inside) ans=0 ;
        return ans ;
      }
  } ;

int n, x, y, X, Y ;
double px, py, qx, qy ;
vector<Square> squares ;
vector<pair<double, int>> data ;
Point P, A, B ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y >> X >> Y ;
        squares.pb(Square(x, y, X, Y)) ;
      }
    cin>> x >> y ;
    P=Point{x, y} ;
    for(int i=0 ; i<n ; i++) data.pb(mp(squares[i].distanceToPoint(P), i+1)) ;
    sort(all(data)) ;
    for(int i=0 ; i<n ; i++) cout<< data[i].se << " " ;
  }
