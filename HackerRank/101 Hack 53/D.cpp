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

lli n, k ;
vlli a, s, S ;
ld dp[50005][105] ;

ld cost(int l, int r)
  {
    if(r<l) return 0 ;
    return (S[r]-S[l-1])-(s[r]-s[l-1])*(s[r]-s[l-1])/(r-l+1.0) ;
  }

void compute(int j, int L, int R, int optL, int optR)
  {
    if(R<L) return ;
    int m=(L+R)/2, best=optL ;
    ld curr ;
    dp[m][j]=INF ;
    for(int k=optL ; k<=min(m, optR) ; k++)
      {
        curr=dp[k][j-1]+cost(k+1, m) ;
        if(curr<dp[m][j]) dp[m][j]=curr, best=k ;
      }
    compute(j, L, m-1, optL, best) ;
    compute(j, m+1, R, best, optR) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    a.resize(n) ;
    s.assign(n+1, 0) ;
    S.assign(n+1, 0) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    sort(all(a)) ;
    for(int i=1 ; i<=n ; i++)
      {
        s[i]=s[i-1]+a[i-1] ;
        S[i]=S[i-1]+a[i-1]*a[i-1] ;
      }
    for(int i=0 ; i<=n ; i++)
      for(int j=0 ; j<=k ; j++)
        dp[i][j]=INF ;
    dp[0][0]=0 ;
    for(int j=1 ; j<=k ; j++) compute(j, 1, n, 0, n) ;
    cout<< fixed << setprecision(9) << dp[n][k] ;
  }
