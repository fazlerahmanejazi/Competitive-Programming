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

lli n, m, k, u, v, x, ans, curr, T ;
vlli c ;

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

template<class T> struct DSU
  {
    map<T, T> par ;
    T comp_sz=n ;
    T get(T u)
      {
        if(par.find(u)==par.end()) return u ;
        return par[u]=get(par[u]) ;
      }
    void unite(T x, T y)
      {
        T X=get(x), Y=get(y) ;
        if(X==Y) return ;
        par[Y]=X ;
        --comp_sz ;
      }
  } ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k ;
    c.resize(n+1) ;
    map<lli, DSU<lli>> virus ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        x=c[u]^c[v] ;
        virus[x].unite(u, v) ;
      }
    ans=((fast_exp(2, k)-virus.size()+mod)*fast_exp(2, n))%mod ;
    for(auto i:virus)
      {
        curr=(i.se).comp_sz ;
        ans=(ans+fast_exp(2, curr))%mod ;
      }
    cout<< ans ;
  }
