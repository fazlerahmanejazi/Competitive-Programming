
typedef complex<double> point ;

point input()
  {
    double x, y ;
    cin>> x >> y ;
    return point(x, y) ;
  }

double dot(const point &a, const point &b)
  {
    return real(conj(a)*b) ;
  }

double cross(const point &a, const point &b)
  {
    return imag(conj(a)*b) ;
  }

bool onSegment(const point &a, const point &b, const point &x)
  {
    return (!cross(a-x, b-x))&&(dot(a-x, b-x)<=0) ;
  }

point rotate_by(const point &p, const point &about, double radians)
  {
    return (p-about)*exp(point(0, radians))+about ;
  }

point reflect(const point &p, const point &about1, const point &about2)
  {
    point z=p-about1 ;
    point w=about2-about1 ;
    return conj(z/w)*w+about1 ;
  }

point sym(const point &x, const point &a, const point &b)
  {
  	return x+2*dot(a, b)/dot(b, b)*b-a ;
  }

// returns intersection of infinite lines ab and pq (undefined if they are parallel)
point intersectLine(const point &a, const point &b, const point &p, const point &q)
  {
    double d1=cross(p-a, b-a) ;
    double d2=cross(q-a, b-a) ;
    return (d1*q-d2*p)/(d1-d2) ;
  }

bool intersectSegment(const point &a, const point &b, const point &p, const point &q)
  {
    double d1=cross(p-a, b-a)*cross(q-a, b-a) ;
    double d2=cross(a-p, q-p)*cross(b-p, q-p) ;
    if(d1<0 || d2<0) return false ;
    else if(!d1 && !d2) return onSegment(p, a, b)||onSegment(q, a, b) ;
    else return true ;
  }
