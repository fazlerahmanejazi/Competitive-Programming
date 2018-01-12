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

bool collinear(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3)
  {
    return (y1-y2)*(x1-x3)==(y1-y3)*(x1-x2) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, x, y, x1, y1, x2, y2, x3, y3 ;
    bool pos=true ;
    cin>> n ;
    vector<tuple<lli, lli, int>> point ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        point.pb(mt(x, y, i+1)) ;
      }
    sort(all(point)) ;
    for(int i=2 ; i<n ; i++)
      {
        tie(x1, y1, ignore)=point[i] ;
        tie(x2, y2, ignore)=point[i-1] ;
        tie(x3, y3, ignore)=point[i-2] ;
        if(!collinear(x1, y1, x2, y2, x3, y3))
          pos=false ;
      }
    if(pos) cout<< 1 << endl << get<2>(point[0]) << " " << get<2>(point[n-1]) ;
    else cout<< 0 ;
  }
