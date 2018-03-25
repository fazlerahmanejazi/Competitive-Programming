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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli hh, mm, h, d, c, n, T=0 ;
    cin>> hh >> mm >> h >> d >> c >> n ;
    long double ans=INF, x, y, C ;
    C=0.8*c ;
    y=ceil(1.0*h/n) ;
    ans=min(ans, y*c) ;
    if(hh<20)
      {
        hh++ ; T+=(60-mm) ;
        T+=(20-hh)*60 ;
        h+=T*d ;
        x=ceil(1.0*h/n) ;
        ans=min(ans, x*C) ;
      }
    else
      {
        x=ceil(1.0*h/n) ;
        ans=min(ans, x*C) ;
      }
    cout<< fixed << setprecision(9) << ans ;
  }
