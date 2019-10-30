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

bool cmpx(tuple<lli, lli, lli, lli> a, tuple<lli, lli, lli, lli> b)
  {
    return (get<0>(a))<(get<0>(b)) ;
  }

bool cmpy(tuple<lli, lli, lli, lli> a, tuple<lli, lli, lli, lli> b)
  {
    return (get<1>(a))<(get<1>(b)) ;
  }

bool cmpz(tuple<lli, lli, lli, lli> a, tuple<lli, lli, lli, lli> b)
  {
    return (get<2>(a))<(get<2>(b)) ;
  }

lli getDist(tuple<lli, lli, lli, lli> a, tuple<lli, lli, lli, lli> b)
  {
    lli x, y, z, X, Y, Z ;
    tie(x, y, z, ignore)=a ;
    tie(X, Y, Z, ignore)=b ;
    return (x-X)*(x-X)+(y-Y)*(y-Y)+(z-Z)*(z-Z) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, t, idx1, idx2 ;
    cin>> n ;
    vlli x(n), y(n), z(n) ;
    vb check(n, 0) ;
    vlli extra ;
    vector<tuple<lli, lli, lli>> temp ;
    vector<tuple<lli, lli, lli, lli>> points ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x[i] >> y[i] >> z[i] ;
        points.pb(mt(x[i], y[i], z[i], i)) ;
      }
    sort(all(points), cmpx) ;
    for(int i=1 ; i<n ; i++) temp.pb(mt(getDist(points[i], points[i-1]), (get<3>(points[i])), (get<3>(points[i-1])))) ;
    sort(all(points), cmpy) ;
    for(int i=1 ; i<n ; i++) temp.pb(mt(getDist(points[i], points[i-1]), (get<3>(points[i])), (get<3>(points[i-1])))) ;
    sort(all(points), cmpz) ;
    for(int i=1 ; i<n ; i++) temp.pb(mt(getDist(points[i], points[i-1]), (get<3>(points[i])), (get<3>(points[i-1])))) ;
    sort(all(temp)) ;
    for(auto i:temp)
      {
        tie(ignore, idx1, idx2)=i ;
        if(!check[idx1] && !check[idx2])
          {
            cout<< idx1+1 << " " << idx2+1 << endl ;
            check[idx1]=true ;
            check[idx2]=true ;
          }
      }
    for(int i=0 ; i<n ; i++) if(!check[i]) extra.pb(i) ;
    for(int i=1 ; i<extra.size() ; i+=2) cout<< extra[i]+1 << " " << extra[i-1]+1 << endl ;
  }
