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

#define ld long double

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli s, q, k ;
    cin>> s >> q >> k ;
    vlli a(q) ;
    ld ans=s, x, y ;
    for(int i=0 ; i<q ; i++) cin>> a[i] ;
    sort(all(a)) ;
    for(int i=0 ; i<q ; i++)
      {
        x=k ;
        y=1.0*ans*a[i]/100.0 ;
        ans+=max(x, y) ;
      }
    cout<< fixed << setprecision(9) << ans ;
  }
