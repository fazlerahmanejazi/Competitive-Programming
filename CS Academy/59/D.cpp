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

int n ;
string dp[3005] ;
char c ;
string ans ;
vvi a ;

void solve(int x, int y, int t)
  {
    if(dp[x]<curr) return ;
    dp[x]=curr ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n+1, vi(n+1)) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=i ; j++)
        {
          cin>> c ;
          a[i][j]=c-'a' ;
        }
    for(int i=1 ; i<=n ; i++)

  }
