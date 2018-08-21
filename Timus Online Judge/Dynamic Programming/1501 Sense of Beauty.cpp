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

int n, x=0, y ;
bool dp[1000+1][1000+1] ;
string s, r ;
vi ans ;

void reconstruct(int i, int j)
  {
    if(i>0 && dp[i-1][j]) ans.pb(1), reconstruct(i-1, j) ;
    else if(j>0) ans.pb(2), reconstruct(i, j-1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> s >> r ;
    s+='#' ; r+='#' ;
    memset(dp, false, sizeof dp) ;
    dp[0][0]=dp[1][0]=dp[0][1]=true ;
    reverse(all(s)) ; reverse(all(r)) ;
    for(int i=0 ; i<=n ; i++)
      {
        if(s[i]=='1') x++ ;
        y=0 ;
        for(int j=0 ; j<=n ; j++)
          {
            if(r[j]=='1') y++ ;
            if(abs(2*x+2*y-i-j)<=1)
              {
                if(i>0) dp[i][j]|=dp[i-1][j] ;
                if(j>0) dp[i][j]|=dp[i][j-1] ;
              }
          }
      }
    if(dp[n][n])
      {
        reconstruct(n, n) ;
        for(int i=0 ; i<2*n ; i++) cout<< ans[i] ;
      }
    else cout<< "Impossible" ;
  }
