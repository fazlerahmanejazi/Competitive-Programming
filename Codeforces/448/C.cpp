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

lli n, x, dp[100005][21], a[100005], f[71],  ans, p[71] ;
lli prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67} ;

lli solve(lli idx, lli mask)
  {
    if(dp[idx][mask]!=-1) return dp[idx][mask] ;
    if(idx==0) return 0 ;
    lli curr=a[idx], m=0, c ;
    for(int i=0 ; i<19 ; i++)
      if(!(curr%prime[i]))
        {
          c=0 ;
          while(!(curr%prime[i])) c++, curr/=prime[i] ;
          if(c%2) m|=1LL<<i ;
        }
    dp[idx][mask]=(p[f[a[idx]]-1]*((solve(idx-f[a[idx]], mask)+solve(idx-f[a[idx]], mask^m))%mod))%mod ;
    return dp[idx][mask] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    memset(dp, -1, sizeof dp) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a[i] ;
        f[a[i]]++ ;
      }
    sort(a+1, a+n+1) ;
    p[0]=1 ;
    dp[0][0]=1 ;
    for(int i=1 ; i<=70 ; i++) p[i]=(2*p[i-1])%mod ;
    ans=(solve(n, 0)-1+mod)%mod ;
    cout<< ans ;
  }
