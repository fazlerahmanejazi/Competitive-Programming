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

double h, H, L, theta, l, r, m, val, ans ;

double func(double x)
  {
    return H*sin(x)*sin(x)*sin(x)-2*h ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> h >> H >> L ;
    if(2*h>=H) ans=0 ;
    else
      {
        theta=asin(2*h/H) ;
        l=theta-eps ; r=pi/2 ;
        while(abs(l-r)>eps)
          {
            m=(l+r)/2 ;
            val=func(m) ;
            if(val>0) r=m ;
            else l=m ;
          }
        theta=(l+r)/2 ;
        ans=((H*cos(theta))/2)-(h/tan(theta)) ;
      }
    cout<< fixed << setprecision(9) << ans ;
  }
