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

lli n, x, cnt[20], fact[22], digits, ans ;
map<vi, lli> dp ;

void init()
  {
    fact[0]=fact[1]=1 ;
    for(lli i=2 ; i<=20 ; i++) fact[i]=fact[i-1]*i ;
  }

void count(lli n)
  {
    while(n)
      {
        cnt[n%10]++ ;
        n/=10 ;
        digits++ ;
      }
  }

lli solve(vi S)
  {
    if(S[0]==digits) return 1 ;
    if(dp.find(S)!=dp.end()) return dp[S] ;
    vi R ;
    lli res=0, extra=1 ;
    for(int i=1 ; extra && i<=10 ; i++) if(cnt[i-1] && !S[i]) extra=0 ;
    res+=extra ;
    R=S ;
    R[0]++ ;
    for(int i=1 ; i<=10 ; i++)
      {
        if(S[0]==0 && i==1) continue ;
        if(R[i]<cnt[i-1])
          {
            R[i]++ ;
            res+=solve(R) ;
            R[i]-- ;
          }
      }
    dp[S]=res ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    count(n) ;
    vi S ;
    for(int i=0 ; i<=10 ; i++) S.pb(0) ;
    ans=solve(S) ;
    cout<< ans ;
  }
