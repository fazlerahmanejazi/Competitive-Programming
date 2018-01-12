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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    int dp[10010][8] ;
    for(int i=0 ; i<=10000 ; i++)
      for(int j=0 ; j<=6 ; j++)
        dp[i][j]=inf ;
    for(int i=2 ; i<=5 ; i++)
      dp[i][i]=1 ;
    for(int i=6 ; i<=10000 ; i++)
      for(int j=1 ; j<=6 ; j++)
        {
          int curr=inf ;
          for(int k=1 ; k<=6 ; k++)
            if(j+k!=7 && k!=j)
              curr=min(dp[i-j][k], curr) ;
          if(curr!=inf) dp[i][j]=curr+1 ;
        }
    while(T--)
      {
        int n, ans=inf ;
        cin>> n ;
        for(int i=1 ; i<=6 ; i++)
          ans=min(dp[n][i], ans) ;
        if(ans==inf) cout<< -1 << endl ;
        else cout<< ans << endl ;
      }
  }
