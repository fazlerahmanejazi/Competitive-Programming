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

const int N=2000010 ;

lli T, n ;
vlli sum(N, 0), dp(N, 0) ;

lli val(lli x)
  {
    lli o=0, e=0, d ;
    while(x>0)
      {
        d=x%10 ; x/=10 ;
        if(d%2) e+=d ;
        else o+=d ;
      }
    return abs(e-o) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    for(int i=1 ; i<N ; i++) sum[i]=sum[i-1]+val(i) ;
    dp[1]=2 ;
    for(int i=2 ; i<N/2 ; i++) dp[i]=dp[i-1]+2*(sum[2*i]-sum[i])-val(2*i) ;
    while(T-- && cin>> n) cout<< dp[n] << endl ;
  }
