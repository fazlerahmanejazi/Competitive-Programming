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

#define countBit(n) __builtin_popcountll(n)
#define checkBit(n, i) ((n>>i)&1)
#define toggleBit(n, i) (n^=(1<<i))
#define clearBit(n, i) (n&=~(1<<i))
#define setBit(n, i) (n|=(1<<i))

lli A, B, C, x, ans, dp[40][40][40][4] ;

lli solve(lli idx, lli a, lli b, lli c)
  {
    if(idx>30)
      {
        if(a || b || c) return 0 ;
        else return 1 ;
      }
    if(a<0 || b<0) return 0 ;
    if(dp[idx][a][b][c]!=-1) return dp[idx][a][b][c] ;
    lli ans=0 ;
    if(checkBit(C, idx))
      {
        if(!c) ans+=solve(idx+1, a-1, b, 0)+solve(idx+1, a, b-1, 0) ;
        else ans+=solve(idx+1, a, b, 0)+solve(idx+1, a-1, b-1, 1) ;
      }
    else
      {
        if(c) ans+=solve(idx+1, a-1, b, 1)+solve(idx+1, a, b-1, 1) ;
        else ans+=solve(idx+1, a, b, 0)+solve(idx+1, a-1, b-1, 1) ;
      }
    return dp[idx][a][b][c]=ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        memset(dp, -1, sizeof dp) ;
        ans=0 ;
        cin>> A >> B >> C ;
        ans=solve(0, countBit(A), countBit(B), 0) ;
        cout<< ans << endl ;
      }
  }
