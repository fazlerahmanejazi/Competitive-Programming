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

#define ld long double

int n, k, T=200 ;
vi a, b ;
vector<ld> K ;
ld x ;
vvi adj ;

void update()
  {
    for(int i=0 ; i<n ; i++)
      {
        ld x=inf, idx, d ;
        for(int j=0 ; j<k ; j++)
          {
            d=abs((K[j]-a[i])*(K[j]-a[i])) ;
            if(d<x) x=d, idx=j ;
          }
        adj[idx].pb(i) ;
      }
    for(int i=0 ; i<k ; i++)
      {
        ld x=0 ;
        for(auto j:adj[i]) x+=a[j] ;
        if(!adj[i].empty()) x/=adj[i].size() ;
        K[i]=x ;
      }
  }

ld solve()
  {
    ld ans=0 ;
    for(int i=0 ; i<k ; i++)
      for(auto j:adj[i])
        ans+=(a[j]-K[i])*(a[j]-K[i]) ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    a.resize(n+1) ;
    b.resize(n+1) ;
    adj.resize(k+1) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=0 ; i<k ; i++) K.pb(a[i]) ;
    while(T--)
      {
        update() ;
        for(int i=0 ; i<k ; i++) adj[i].clear() ;
      }
    update() ;
    cout<< fixed << setprecision(9) << solve() ;
  }
