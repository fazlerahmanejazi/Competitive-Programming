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

string s ;
lli n, k, ans, L, curr, dp[1005][1005] ;
vlli steps(1005, -1), p(1005) ;

lli fact[400005] ;

void init()
  {
    steps[0]=0 ; steps[1]=1 ; p[0]=1 ;
    fact[0]=1 ;
    memset(dp, -1, sizeof dp) ;
    for(int i=1 ; i<=400000 ; i++) fact[i]=fact[i-1]*i%mod ;
    for(lli i=2 ; i<=1000 ; i++) steps[i]=1+steps[__builtin_popcountll(i)] ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1;
    while(exp>0)
      {
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
      }
    return res%mod;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ; b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

lli nCr(lli n, lli r)
  {
    if(r>n || r<0) return 0 ;
    return divide(divide(fact[n],fact[r]), fact[n-r])%mod ;
  }

lli solve(lli idx, lli cnt)
  {
    if(idx>=n || cnt<0) return 0 ;
    if(dp[idx][cnt]!=-1) return dp[idx][cnt] ;
    lli len=n-idx-1, ans=0, chk=0 ;
    for(int i=1 ; i<=len ; i++)
      if(steps[i]==cnt)
        ans+=nCr(len, i) ;
    for(int i=idx+1 ; i<n ; i++)
      if(s[i]=='1')
        {
          chk=1 ;
          ans+=solve(idx+1, cnt-1) ;
        }
    if(!chk && cnt)  ans++ ;
    dp[idx][cnt]=ans ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    cin>> s >> k ;
    n=s.length() ;
    ans=solve(0, k) ;
    cout<< ans ;
  }
