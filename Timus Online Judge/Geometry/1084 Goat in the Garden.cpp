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
    double a, r, angle, extra=0, ans=0 ;
    cin>> a >> r ;
    angle=2*acos(a/(2*r)) ;
    if(2*r>=a) extra=((r*r*angle)/2.0)-((sqrt(4*r*r-a*a)*a)/4.0) ;
    if(sqrt(2)*r>a) ans=a*a ;
    else ans=pi*r*r-4*extra ;
    cout<< fixed << setprecision(3) << ans ;
  }
