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

int n, N=60, res, val, x, a[110], dp[110][1<<17], fact[65], last[101][1<<17], ans[110], isprime[65] ;

void pre()
  {
    vi p ;
    for(int i=2 ; i<=N ; i++) isprime[i]=true ;
    for(int i=2 ; i<=N ; i++)
      if(isprime[i])
        for(int j=2*i ; j<=N ; j+=i)
          isprime[j]=false ;
    for(int i=2 ; i<=N ; i++) if(isprime[i]) p.pb(i) ;
    for(int i=2 ; i<=N ; i++)
      for(int j=0 ; j<p.size() ; j++)
        if(!(i%p[j]))
          fact[i]|=(1<<j) ;
  }

void fillDP()
  {
    memset(dp, inf, sizeof dp) ;
    res=inf ;
    for(int i=0 ; i<(1<<16) ; i++) dp[0][i]=0 ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=N ; j++)
        {
          x=(~fact[j])&((1<<16)-1) ;
          for(int s=x ; ; s=((s-1)&x))
            {
              if(dp[i-1][s]==inf) continue ;
              else if(dp[i-1][s]+abs(a[i]-j)<dp[i][s|fact[j]])
                {
                  dp[i][s|fact[j]]=dp[i-1][s]+abs(a[i]-j) ;
                  last[i][s|fact[j]]=j ;
                }
              if(!s) break ;
            }
        }
    for(int i=0 ; i<(1<<16) ; i++) if(dp[n][i]<res) res=dp[n][i], val=i ;
  }

void reconstruct()
  {
    for(int i=n ; i>=1 ; i--)
      {
        ans[i]=last[i][val] ;
        val^=fact[last[i][val]] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    pre() ;
    fillDP() ;
    reconstruct() ;
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
