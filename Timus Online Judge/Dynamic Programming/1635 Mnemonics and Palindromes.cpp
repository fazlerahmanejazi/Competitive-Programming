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
    string s ;
    cin>> s ;
    int l, r, n=s.length(), curr, prev ;
    s='#'+s ;
    pii dp[n+1] ;
    bool isPal[n+1][n+1] ;
    memset(isPal, false, sizeof isPal) ;
    memset(dp, inf, sizeof dp) ;
    for(int i=1 ; i<=n ; i++) isPal[i][i]=true, dp[i]=mp(1, 0) ;
    for(int len=2 ; len<=n ; len++)
      for(int i=1 ; i+len-1<=n ; i++)
        {
          l=i ; r=i+len-1 ;
          if(len==2) isPal[l][r]=(s[l]==s[r]) ;
          else isPal[l][r]=((s[l]==s[r])&&isPal[l+1][r-1]) ;
        }
    for(int i=2 ; i<=n ; i++)
      {
        dp[i]=mp(dp[i-1].fi+1, i-1) ;
        for(int j=1 ; j<i ; j++)
          if(isPal[j][i])
            {
              if(j>1) curr=dp[j-1].fi ;
              else curr=0 ;
              if(curr+1<dp[i].fi) dp[i]=mp(1+curr, j-1) ;
            }
      }
    cout<< dp[n].fi << endl ;
    vi ans ;
    prev=n ;
    while(prev)
      {
        ans.pb(dp[prev].se) ;
        prev=dp[prev].se ;
      }
    sort(all(ans)) ;
    ans.pb(n) ;
    for(int i=0 ; i<ans.size()-1 ; i++)
      {
        for(int j=ans[i]+1 ; j<=ans[i+1] ; j++) cout<< s[j] ;
        if(i!=ans.size()-2) cout<< " " ;
      }
  }
