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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    double V, a, k, vx, vy, T, ans=0 ;
    cin>> V >> a >> k ;
    vx=V*cos((pi*a)/180.0) ;
    vy=V*sin((pi*a)/180.0) ;
    while(vx>eps || vy>eps)
      {
        T=(2*vy)/10.0 ;
        ans+=vx*T ;
        vx/=sqrt(k) ;
        vy/=sqrt(k) ;
      }
    cout<< fixed << setprecision(2) << ans ;
  }
