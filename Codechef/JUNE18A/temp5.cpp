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
template<typename T> T dot(const V<T> &a, const V<T> &b) { return a.x*b.x+a.y*b.y+a.z*b.z ; }
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

V<long double> in()
  {
    int x, y, z ;
    cin>> x >> y >> z ;
    return V<long double>(x, y, z) ;
  }

template<typename T> T findUpperBound(const V<T> &P, const V<T> &Q, const V<T> &D, const V<T> &C)
  {
    T m1, m2, f1, f2, l=0, r=1e9+10 ;
    while (r-l>eps)
      {
        m1=l+(r-l)/3 ;
        m2=r-(r-l)/3 ;
        f1=pointToLine(P, Q+D*m1, C) ;
        f2=pointToLine(P, Q+D*m2, C) ;
        if(f1<f2) l=m1 ;
        else r=m2 ;
      }
    return l ;
  }

template<typename T> T solve(const V<T> &P, const V<T> &Q, const V<T> &D, const V<T> &C, const T &R)
  {
    T m, dist, l=0, r=findUpperBound(P, Q, D, C) ;
    while(abs(l-r)>eps)
      {
        m=(l+r)/2 ;
        dist=pointToLine(P, Q+D*m, C) ;
        if(dist<R) l=m ;
        else r=m ;
      }
    return l ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        long double l=0, r=1e9+10, m, dist, R ;
        V<long double> P, Q, D, C ;
        P=in() ; Q=in() ; D=in() ; C=in() ;
        cin>> R ;
        cout<< fixed << setprecision(9) << solve(P, Q, D, C, R) << endl ;
      }
  }
