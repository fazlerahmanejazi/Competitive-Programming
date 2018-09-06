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

lli n, x, y, X, Y, p, q, g, r, s ;
double ans ;
vpii points ;
set<pii> xx, yy ;
map<tuple<lli, lli, lli, lli>, set<pii>> slope ;

double get(pii a, pii b)
  {
    double d=(a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se) ;
    d=sqrt(d) ;
    return d ;
  }

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> x >> y, points.pb(mp(x, y)) ;
    for(int i=0 ; i<n ; i++)
      {
        tie(x, y)=points[i] ;
        for(int j=i+1 ; j<n ; j++)
          {
            tie(X, Y)=points[j] ;
            p=X-x ; q=Y-y ;
            if(!p)
              {
                slope[mt(inf, 1, x, 1)].insert(points[i]) ;
                slope[mt(inf, 1, x, 1)].insert(points[j]) ;
                continue ;
              }
            if(!q)
              {
                slope[mt(0, 0, y, 0)].insert(points[i]) ;
                slope[mt(0, 0, y, 0)].insert(points[j]) ;
                continue ;
              }
            if(q<0) p=-p, q=-q ;
            g=__gcd(abs(p), abs(q)) ;
            p/=g ; q/=g ;
            r=Y*q-p*X ; s=q ;
            g=__gcd(abs(r), abs(s)) ;
            r/=g ; s/=g ;
            slope[mt(p, q, r, s)].insert(points[i]) ;
            slope[mt(p, q, r, s)].insert(points[j]) ;
          }
      }
    for(auto i:slope)
      {
        auto it1=(i.se).begin(), it2=(i.se).end() ; it2-- ;
        ans+=get(*it1, *it2) ;
      }
    ans+=eps ;
    cout<< nearbyintl(ans) ;
  }
