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

#define ld double

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli a, w, h, n ;
    ld x, y, z, theta, lX=INF, lY=INF, hX=-INF, hY=-INF, scaleX, scaleY ;
    vector<pair<ld, ld>> p ;
    //cin>> a >> w >> h >> n ;
    scanf("%lld %lld %lld %lld", &a, &w, &h, &n) ;
    theta=(a*pi)/180.0 ;
    for(int i=0 ; i<n ; i++)
      {
        //cin>> x >> y ;
        scanf("%lf %lf", &x, &y) ;
        z=y*cos(theta)+x*sin(theta) ;
        x=-y*sin(theta)+x*cos(theta) ;
        y=z ;
        p.pb(mp(x, y)) ;
        lX=min(lX, x) ;
        hX=max(hX, x) ;
        lY=min(lY, y) ;
        hY=max(hY, y) ;
      }
    tie(scaleX, scaleY)=mp(w/(hX-lX), h/(hY-lY)) ;
    //cout<< fixed << setprecision(9) ;
    for(int i=0 ; i<n ; i++)
      {
        tie(x, y)=p[i] ;
        x=(x-lX)*scaleX ;
        y=(y-lY)*scaleY ;
        printf("%.9f %.9f\n", x, y) ;
      }
  }
