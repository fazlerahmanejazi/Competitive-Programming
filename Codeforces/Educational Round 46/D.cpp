#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
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

#define mod 998244353

lli n, ans, dp[1010][1010][3], a[1010] ;

lli solve(lli idx, lli pos, lli c)
  {
    if(idx==n)
      {
        if(!pos && c==1) return 1 ;
        else return 0 ;
      }
    if(dp[idx][pos][c]!=-1) return dp[idx][pos][c] ;
    lli curr=0 ;
    curr+=solve(idx+1, pos, c) ;
    curr%=mod ;
    if(!pos)
      {
        if(a[idx]<=n+1 && a[idx]>0)
          {
            curr+=solve(idx+1, a[idx], 1) ;
            curr%=mod ;
          }
      }
    else
      {
        curr+=solve(idx+1, pos-1, 1) ;
        curr%=mod ;
      }
    return dp[idx][pos][c]=curr ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    memset(dp, -1, sizeof dp) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    ans=solve(0, 0, 0) ;
    cout<< ans ;
  }
