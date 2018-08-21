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

const int N=2000000 ;

vlli prime ;
vb isprime(N+5, true) ;

void sieve()
  {
    isprime[1]=1 ;
    for(int i=2 ; i<=N ; i++)
      if(isprime[i])
        {
          for(int j=2*i ; j<=N ; j+=i)
            isprime[j]=false ;
          prime.pb(i)  ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    sieve() ;
    lli n, x, y, curr, ans=INF, z, g, l, r, m ;
    cin>> n >> x >> y ;
    vlli cnt(N+5, 0), sum(N+5, 0)  ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> z ;
        cnt[z]++ ;
        sum[z]+=z ;
      }
    for(int i=1 ; i<=N ; i++) cnt[i]+=cnt[i-1], sum[i]+=sum[i-1] ;
    for(auto g:prime)
      {
        curr=0 ;
        for(int j=g ; j<=N ; j+=g)
          {
            l=j-g ; r=j ;
            m=max(l+1, j-(x/y))-1 ;
            curr+=(cnt[m]-cnt[l])*x ;
            curr+=((cnt[r]-cnt[m])*r-(sum[r]-sum[m]))*y ;
          }
        ans=min(ans, curr) ;
      }
    cout<< ans ;
  }
