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

lli T, n, c, x, y, s, e, idx, mx, val, curr, L ;
vlli fact(21), ans, factors ;
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
    sort(all(res)) ;
    return res ;
  }

void init()
  {
    s=0 ;
    //while(fact[min(19, (int)(n+s))]<=c*fact[s]) s++ ;
    //s=max(s-1, 0LL) ;
    fact[0]=fact[1]=1 ;
    for(int i=2 ; i<=19 ; i++) fact[i]=i*fact[i-1] ;
    ans.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) ans[i]=i ;
    mx=INF ;
    curr=1 ;
    e=n ;
  }

void solve(lli idx)
  {
    val=curr ;
    y=idx ;
    for(lli i=idx ; i<=e ; i++)
      {
        x=curr*(i-idx+1) ;
        if(!(c%x) && c/x<mx)
          {
            mx=c/x ;
            ans[idx]=i ;
            val=x ;
            y=i ;
          }
      }
    e=y ;
    curr=val ;
  }

bool check()
  {
    lli res=1 ;
    for(int i=1 ; i<=n ; i++) res*=(ans[i]-i+1) ;
    return (res==c) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> c ;
        init() ;
        factors=factorize(c) ;
        L=n ;
        while(1)
          {
            mx=INF ;
            curr=L-n+1 ;
            e=L ;
            for(int i=1 ; i<=n ; i++) ans[i]=i ;
            ans[n]=e ;
            for(int i=n-1 ; i>=1 ; i--) solve(i) ;
            ans[n]+=((c/curr)-1) ;
            if(check()) break ;
            L++ ;
          }
        for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
        cout<< endl ;
      }
  }
