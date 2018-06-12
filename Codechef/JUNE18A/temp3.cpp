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
vb isprime ;
vlli prime ;

void seive()
  {
    isprime.assign(1e5+100, true) ;
    for(int i=2 ; i*i<=1e5 ; i++)
      if(isprime[i])
        for(int j=i*i ; j<=1e5 ; j+=i)
          isprime[j]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=1e5 ; i+=2) if(isprime[i]) prime.pb(i) ;
  }

vlli factorize(lli x)
  {
    vlli res ;
    for(auto p:prime)
      {
        while(!(x%p)) res.pb(p), x/=p ;
        if(p*p>x) break ;
      }
    if(x!=1) res.pb(x) ;
    return res ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    lli x ;
    cin>> x ;
    vlli ans=factorize(x) ;
    for(auto i:ans) cout<< i << " " ;
  }
