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

map<int, double> dp[100010] ;

double solve(int n, int len)
  {
    if(dp[n][len]) return dp[n][len] ;
  	if(len==1) return 1.0 ;
    double a, b ;
  	if(len%2==0)
      {
    		if(n>=len/2) dp[n][len]=(double)len+solve(n-len/2, len/2) ;
    		else dp[n][len]=(double)len+solve(n, len/2) ;
    	}
  	else
      {
    		if(n<=len/2) a=solve(n, len/2), b=solve(n, len/2+1) ;
    		else if(n>len/2+1) a=solve(n-len/2-1,n/2), b=solve(n-len/2,len/2+1) ;
    		else a=solve(n/2+1,len/2+1), b=solve(1,len/2+1) ;
        dp[n][len]=(double)len+(a/2.0)+b/2.0 ;
    	}
    return dp[n][len] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      cout<< fixed << setprecision(9) << solve(i, n) << " " ;
  }
