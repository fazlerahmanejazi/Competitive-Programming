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

V<lli> input()
  {
    lli x, y, z ;
    cin>> x >> y >> z ;
    return V<lli>(x, y, z) ;
  }

lli vectorTripleProduct(V<lli> AB, V<lli> AC, V<lli> AD)
  {
    return dot(AD, cross(AB, AC)) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    V<lli> p[4] ;
    for(int i=0 ; i<4 ; i++) p[i]=input() ;
    if(!vectorTripleProduct(p[1]-p[0], p[2]-p[0], p[3]-p[0]) && !dot(p[1]-p[0], p[3]-p[2]) && dot(p[1]-p[0], p[2]-p[1])>=0 && dot(p[3]-p[2], p[2]-p[1])>=0) cout<< "Valid" ;
    else cout<< "Invalid" ;
  }
