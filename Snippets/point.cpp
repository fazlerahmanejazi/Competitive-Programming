template<typename T> struct Point
  {
      T x, y ;
      Point() {}
      Point(T x, T y) : x(x), y(y) {}
      void read() { cin >> x >> y ; }
  } ;

Point operator + (Point p1, Point p2) { return Point(p1.x + p2.x, p1.y + p2.y); }
Point operator - (Point p1, Point p2) { return Point(p1.x - p2.x, p1.y - p2.y); }
Point operator * (Point p, int a) { return Point(p.x * a, p.y * a); }
Point operator / (Point p, int a) { return Point(p.x / a, p.y / a); }
