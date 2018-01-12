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

lli T, n, k, dp[100000][20], ans ;

lli solve(int mask, int idx)
  {
    if(mask==(1<<(n+1))-2) return 1 ;
    else if(dp[mask][idx]!=-1) return dp[mask][idx] ;
    lli res=0 ;
    for(int i=1 ; i<=15 ; i++)
      if((!(mask&(1<<i)) && abs(i-idx)<=k) || !idx)
        res+=solve(mask|(1<<i), i) ;
    return dp[mask][idx]=res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T-- && cin>> n >> k)
      {
        memset(dp, -1, sizeof dp) ;
        cout<< solve(0, 0) << endl ;
      }
  }
