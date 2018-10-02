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

lli n, x, ans ;
vlli cnt(2100000) ;
vb isprime(2100000, true) ;
vlli prime ;

void init()
    {
        ans=0 ;
        prime.clear() ;
        for(int i=0 ; i<=2000000 ; i++) cnt[i]=0 ;
    }

void seive()
  {
    for(int i=2 ; i*i<=2000000 ; i++)
      if(isprime[i])
        for(int j=i*i ; j<=2000000 ; j+=i)
          isprime[j]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=2000000 ; i+=2) if(isprime[i]) prime.pb(i) ;
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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> x, cnt[(upper_bound(all(prime), x)-prime.begin())-1]++ ;
    for(int i=0 ; i<=2000000 ; i++) ans=(ans+fast_exp(2, cnt[i])-1+mod)%mod ;
    cout<< ans ;
  }
