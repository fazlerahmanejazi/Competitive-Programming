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

typedef complex<double> point ;
point v, p, m1, m2, w1, w2, t ;

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

point reflect(const point &p, const point &about1, const point &about2)
  {
    point z=p-about1 ;
    point w=about2-about1 ;
    return conj(z/w)*w+about1 ;
  }

point intersection(const point &a, const point &b, const point &p, const point &q)
  {
    double d1=cross(p-a, b-a) ;
    double d2=cross(q-a, b-a) ;
    return (d1*q-d2*p)/(d1-d2) ;
  }

bool onSegment(const point &x, const point &a, const point &b)
  {
    return (!cross(a-x, b-x))&&(dot(a-x, b-x)<=0) ;
  }

bool intersect(const point &a, const point &b, const point &p, const point &q)
  {
    double d1=cross(p-a, b-a)*cross(b-a, q-a) ;
    double d2=cross(a-p, q-p)*cross(q-p, b-p) ;
    if(d1<0 || d2<0) return false ;
    else if(!d1 && !d2) return onSegment(p, a, b)||onSegment(q, a, b) ;
    else return true ;
  }

bool check()
  {
    t=reflect(v, m1, m2) ;
    if(intersect(t, p, m1, m2))
      {
        t=intersection(t, p, m1, m2) ;
        if((intersect(t, p, w1, w2) || intersect(t, v, w1, w2)) && intersect(v, p, w1, w2)) return false ;
        else return true ;
      }
    else
      {
        if(intersect(v, p, w1, w2) || intersect(v, p, m1, m2)) return false ;
        else return true ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    v=input() ; p=input() ;
    w1=input() ; w2=input() ;
    m1=input() ; m2=input() ;
    if(check()) cout<< "YES" ;
    else cout<< "NO" ;
  }
