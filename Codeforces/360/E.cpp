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

int N, K, X, curr, last ;
bool dp[2][501][501] ;
vi ans ;

bool f(int x, int y, int z)
  {
    if(x<0 || y<0 || z<0) return false ;
    return dp[x][y][z] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> N >> K ;
    memset(dp, false, sizeof dp) ;
    dp[0][0][0]=true ;
    for(int i=1 ; i<=N ; i++)
      {
        cin>> X ;
        curr=i%2 ;
        last=1-curr ;
        for(int j=0 ; j<=500 ; j++)
          for(int k=0 ; k<=500 ; k++)
            dp[curr][j][k]|=f(last, j, k)|f(last, j-X, k)|f(last, j-X, k-X) ;
      }
    for(int i=0 ; i<=500 ; i++) if(dp[N%2][K][i]) ans.pb(i) ;
    cout<< ans.size() << endl ;
    for(auto i:ans) cout<< i << " " ;
  }
