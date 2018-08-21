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

lli n, x, dp[100005][21], a[100005], ans ;
lli p[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67} ;

lli solve(lli idx, lli mask)
  {
    if(idx<0)
      {
        if(!mask) return 1 ;
        return 0 ;
      }
    if(dp[idx][mask]!=-1) return dp[idx][mask] ;
    lli curr=a[idx], m=0, c ;
    for(int i=0 ; i<19 ; i++)
      if(!(curr%p[i]))
        {
          c=0 ;
          while(!(curr%p[i])) c++, curr/=p[i] ;
          if(c%2) m|=1LL<<i ;
        }
    dp[idx][mask]=solve(idx-1, mask)+solve(idx-1, mask^m) ;
    return dp[idx][mask] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    memset(dp, -1, sizeof dp) ;
    cout<< solve(n-1, 0)-1 ;
  }
