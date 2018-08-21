#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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

int n, d, m, x, ans=0 ;
vi gem(30000+5, 0) ;

void DP()
  {
    int dp[m+1][d+251] ;
    memset(dp, -1, sizeof dp) ;
    dp[d][d]=gem[d] ;
    for(int i=d ; i<=m ; i++)
      for(int j=1 ; j<=d+250 ; j++)
        if(dp[i][j]!=-1)
          {
            if(i+j<=m && j<=d+250) dp[i+j][j]=max(dp[i][j]+gem[i+j], dp[i+j][j]) ;
            if(i+j+1<=m && j+1<=d+250) dp[i+j+1][j+1]=max(dp[i][j]+gem[i+j+1], dp[i+j+1][j+1]) ;
            if(i+j-1<=m && j-1<=d+250 && j>1) dp[i+j-1][j-1]=max(dp[i][j]+gem[i+j-1], dp[i+j-1][j-1]) ;
          }
    for(int i=d ; i<=m ; i++)
      for(int j=1 ; j<=d+250 ; j++)
        ans=max(ans, dp[i][j]) ;
  }

void brute(int pos, int jump, int curr)
  {
    if(pos>m) return ;
    int x=curr+gem[pos] ;
    ans=max(x, ans) ;
    brute(pos+jump, jump, x) ;
    brute(pos+jump+1, jump+1, x) ;
    brute(pos+jump-1, jump-1, x) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> d ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        gem[x]++ ;
        m=max(x, m) ;
      }
    if(d<=1950) DP() ;
    else brute(d, d, 0) ;
    cout<< ans << endl ;
  }
