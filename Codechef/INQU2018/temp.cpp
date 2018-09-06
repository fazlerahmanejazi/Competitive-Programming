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

const int M=110 ;

lli T, n, k, dp[200][200], aux[200][200], fact[400005] ;

void init()
  {
    fact[0]=1 ;
    for(int i=1 ; i<=400000 ; i++) fact[i]=fact[i-1]*i%mod ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    base=base%mod ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ;
    b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

lli nCr(lli n, lli r)
  {
    if(r>n || r<0) return 0 ;
    return divide(divide(fact[n],fact[r]), fact[n-r])%mod ;
  }

void fillDP()
  {
    for(int i=1 ; i<=M ; i++) dp[i][1]=1 ;
    for(int i=2 ; i<=M ; i++)
      for(int j=1 ; j<i ; j++)
        {
          dp[i][j]=(nCr(i-1, j-1)*(nCr(i-1, j-1)))%mod ;
          for(int l=1 ; l<j ; l++)
            for(int k=1 ; k<j ; k++)
              dp[i][j]=(dp[i][j]-dp[l][j-k]*()+mod)%mod ;
          cerr<< i << " " << j << " " << dp[i][j] << endl ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    fillDP() ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> k ;
        cout<< dp[k][n] << endl ;
      }
  }
