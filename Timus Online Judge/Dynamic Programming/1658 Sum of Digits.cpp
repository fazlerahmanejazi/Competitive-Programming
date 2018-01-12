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

int T, s1, s2 ;
vi ans ;
int dp[901][8101] ;

void reconstruct(int a, int b)
  {
    if(!a) return ;
    int x=inf, y ;
    for(int i=1 ; i<=9 ; i++)
      if(a>=i && b>=i*i && dp[a-i][b-i*i]<x)
        x=dp[a-i][b-i*i], y=i ;
    ans.pb(y) ;
    reconstruct(a-y, b-y*y) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    memset(dp, inf, sizeof dp) ;
    dp[0][0]=0 ;
    for(int i=1 ; i<=900 ; i++)
      for(int j=1 ; j<=8100 ; j++)
        for(int k=1 ; k<=9 ; k++)
          if(i>=k && j>=k*k)
            dp[i][j]=min(dp[i-k][j-k*k]+1, dp[i][j]) ;
    cin>> T ;
    while(T--)
      {
        cin>> s1 >> s2 ;
        ans.clear() ;
        if(s1>900 || s2>8100 || dp[s1][s2]>100) cout<< "No solution" ;
        else
          {
            reconstruct(s1, s2) ;
            sort(all(ans)) ;
            for(auto i:ans) cout<< i ;
          }
        cout<< endl ;
      }
  }
