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

int n, x, y ;
vb isprime
vi a, prime, ans ;

void sieve()
  {
    isprime.assign(10010, true) ;
    isprime[1]=false ;
    for(int i=2 ; i<=10001 ; i++)
      if(isprime[i])
        for(int j=i*i ; j<=10001 ; j+=i)
          isprime[i]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=10001 ; i+=2) if(isprime[i]) prime.pb(i) ;
  }

int get(int x)
  {
    for(auto p:prime)
      {
        y=p*p ;
        if(abs(x)<y) break ;
        while(x%y==0) x/=y ;
      }
    return x ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    sieve() ;
    cin>> n ;
    a.resize(n+1) ;
    ans.assign(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        a[i]=get(x) ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        unordered_map<int, int> cnt ;
        for(int j=i+1)

      }
