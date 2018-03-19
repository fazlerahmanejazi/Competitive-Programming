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

lli n, q, l, r, s, c, XX[2005][2005], YY[2005][2005], dp[2005][2005] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
  	cin>> n >> q ;
  	for(int i=1 ; i<=q ; i++)
    	{
    		cin>> r >> c >> l >> s ;
    		XX[r+l-1][c]+=s ;
    		XX[r+l-1][c+l]-=s ;
    		YY[r+l-1][c]+=s ;
    		YY[r-1][c]-=s ;
    	}
  	for(int i=1 ; i<=2000 ; i++)
  	 for(int j=1 ; j<=2000 ; j++)
  		 XX[i][j]+=XX[i][j-1] ;
  	for(int j=1;j<=2000;j++)
    	for(int i=2000 ; i>=1 ; i--)
    		{
    			YY[i][j]+=YY[i+1][j] ;
    			dp[i][j]+=dp[i-1][j-1]-XX[i-1][j-1] ;
    			dp[i][j]+=YY[i][j] ;
    		}
  	for(int i=1 ;i<=n ; i++, cout<< endl)
      for(int j=1;j<=n;j++)
  		  cout<< dp[i][j] << " " ;
  }
