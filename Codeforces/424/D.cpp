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
    lli n, k, p, x ;
    cin>> n >> k >> p ;
    vlli people(n+1), keys(k+1) ;
    for(int i=1 ; i<=n ; i++)
      cin>> people[i] ;
    for(int i=1 ; i<=k ; i++)
      cin>> keys[i] ;
    sort(people.begin()+1, people.end()) ;
    sort(keys.begin()+1, keys.end()) ;
    lli dp[n+1][k+1] ;
    memset(dp, 2*INF, sizeof dp) ;
    for(int i=0 ; i<=k ; i++)
      dp[0][i]=0 ;
    for(int i=1 ; i<=n ; i++)
      for(int j=i ; j<=k ; j++)
        {
          x=abs(people[i]-keys[j])+abs(keys[j]-p) ;
          x=max(x, dp[i-1][j-1]) ;
          dp[i][j]=min(dp[i][j-1], x) ;
        }
    cout<< dp[n][k] ;
  }
