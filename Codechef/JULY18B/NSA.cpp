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

int get(char c) { return c-'a'+1 ; }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
		cin>> T ;
		while(T--)
			{
				lli n, x, ans=0, tot, L[100010][30], R[100010][30] ;
				string s ;
				cin>> s ;
				n=s.length() ;
				s='#'+s ;
				memset(L, 0, sizeof L) ;
				memset(R, 0, sizeof R) ;
				for(int i=1 ; i<=n ; i++)
					{
						for(int j=1 ; j<=26 ; j++)	L[i][j]+=L[i-1][j] ;
						L[i][get(s[i])]++ ;
					}
				for(int i=n ; i>=1 ; i--)
					{
						for(int j=1 ; j<=26 ; j++)	R[i][j]+=R[i+1][j] ;
						R[i][get(s[i])]++ ;
					}
				for(int i=1 ; i<=n ; i++)
					{
						for(int j=1 ; j<=26 ; j++)	L[i][j]+=L[i][j-1] ;
						ans+=L[i-1][get(s[i])-1] ;
					}
				for(int i=1 ; i<=n ; i++)
					for(int j=26 ; j>=1 ; j--)
						R[i][j]+=R[i][j+1] ;
				tot=ans ;
				for(int i=1 ; i<=n ; i++)
					for(int j=1 ; j<=26 ; j++)
						ans=min(ans, tot-L[i-1][get(s[i])-1]-R[i+1][get(s[i])+1]+abs(j-get(s[i]))+L[i-1][j-1]+R[i+1][j+1]) ;
				cout<< ans << endl ;
			}
  }
