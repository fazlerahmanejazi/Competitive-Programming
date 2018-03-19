#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

#define pi acos(-1.0)
#define eps 1e-8

lli n, x, y, a, b, c, d, l, r ;
vector<pair<lli, lli>> point ;

lli val(lli x, lli y)
  {
    return x*(d-b)-y*(c-a)-a*d+b*c ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        point.pb(mp(x, y)) ;
      }
    a=point[0].fi ; b=point[0].se ;
    for(int i=1 ; i<n ; i++)
      {
        c=point[i].fi ; d=point[i].se ;
        l=r=0 ;
        for(int j=1 ; j<n ; j++)
          if(j!=i)
            if(val(point[j].fi, point[j].se)>0) l++ ;
            else r++ ;
        if(l==r)
          {
            cout<< 1 << " " << i+1 ;
            return 0 ;
          }
      }
  }
