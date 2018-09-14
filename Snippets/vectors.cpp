template<typename T> class V
  {
    public:
    // 3 most basic ways of initializing a vector
    V() : x(T(0)), y(T(0)), z(T(0)) {}
    V(const T &xx) : x(xx), y(xx), z(xx) {}
    V(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    T x, y, z ;
    V<T> operator + (const V<T> &v) const { return V<T>(x+v.x, y+v.y, z+v.z) ; }
    V<T> operator - (const V<T> &v) const { return V<T>(x-v.x, y-v.y, z-v.z) ; }
    V<T> operator * (const T &r) const { return V<T>(x * r, y * r, z * r) ; }
  } ;

template<typename T> T length(const V<T> &v) { return sqrt(v.x*v.x+v.y*v.y+v.z*v.z) ; }
template<typename T> T dot(const V<T> &a, const V<T> &b) { return a.x*b.x+a.y*b.y+a.z*b.z ; } //dot squared
template<typename T> V<T> cross(const V<T> &a, const V<T> &b) { return V<T>( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x) ; }

template<typename T> void normalize(V<T> &v)
  {
    T len2=v.x*v.x+v.y*v.y+v.z*v.z ;
    // avoid division by 0
    if(len2>0)
      {
        T invLen=1/sqrt(len2) ;
        v.x*=invLen, v.y*=invLen, v.z*=invLen ;
      }
  }

template<typename T> T pointToLine(const V<T> &a, const V<T> &b, const V<T> &p)
  {
    V<T> v=a-b ;
    V<T> w=p-b ;
    T c1=dot(w, v) ;
    T c2=dot(v, v) ;
    T c3=c1/c2 ;
    V<T> z=b+v*c3 ;
    return length(p-z) ;
  }

//NOT TESTED
template<typename T> T pointToLineSegment(const V<T> &a, const V<T> &b, const V<T> &p)
  {
    V<T> ap=a-p ;
    V<T> ab=a-b ;
    V<T> c ;
    T x=dot(ap, ab)/length(ab) ;
    if(x<0) return length(p-a) ;
    else if(x>1) return length(p-b) ;
    else return pointToLine(a, b, p) ;
  }
