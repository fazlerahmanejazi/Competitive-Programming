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

double dist(double x1, double y1, double x2, double y2)
  {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    double r, ans ;
    cin>> n >> r ;
    ans=2*pi*r ;
    vector<pair<double, double>> point(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> point[i].fi >> point[i].se ;
    for(int i=1 ; i<n ; i++)
      ans+=dist(point[i].fi, point[i].se, point[i-1].fi, point[i-1].se) ;
    ans+=dist(point[0].fi, point[0].se, point[n-1].fi, point[n-1].se) ;
    cout<< fixed << setprecision(2) << ans ;
  }
