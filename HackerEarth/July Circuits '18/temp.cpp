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

lli n, m, p, x, T ;

void subtask1()
  {
    lli dp[1010][1010] ;
    memset(dp, 0, sizeof dp) ;
    dp[0][0]=1%p ;
    for(int i=1 ; i<=n ; i++)
      for(int j=0 ; j<=m ; j++)
        {
          dp[i][j]=dp[i-1][j] ;
          if(j>=i) dp[i][j]=(dp[i][j]+dp[i][j-i])%p ;
        }
    cout<< dp[n][m] << endl ;
  }

void subtask2()
  {

  }

void subtask3()
  {

  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T >> p ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> m ;
        if(n<=1000 && m<=1000) subtask1() ;
        else if(T==1 && n<=100000 && m<=100000) subtask2() ;
        else subtask2() ;
      }

  }
