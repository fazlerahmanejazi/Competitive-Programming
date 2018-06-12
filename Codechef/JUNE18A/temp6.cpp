#include <bits/stdc++.h>
using namespace std ;

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

long long int T, N, n, c, x, y, s, e, idx, mx, val, curr, L ;
vector<long long int> fact(21), ans(35), factors, prime, temp(35), vals(35) ;
vector<bool> isprime ;

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

void factorize(lli x)
  {
    factors.clear() ;
    for(auto p:prime)
      {
        while(!(x%p)) factors.pb(p), x/=p ;
        if(p*p>x) break ;
      }
    if(x!=1) factors.pb(x) ;
    sort(all(factors)) ;
  }

bool check()
  {
    lli res=1 ;
    for(int i=1 ; i<=n ; i++) res*=(ans[i]-i+1) ;
    return (res==c) ;
  }

void solve(lli idx, lli curr)
  {
    if(idx>=L)
      {
        if(temp[N-1]<ans[N-1]) ans=temp ;
        return ;
      }
    for(int i=1 ; i<N ; i++)
      {
        temp[i]=i-1 ;
        vals[i]*=factors[idx] ;
        temp[i]+=vals[i] ;
        curr*=factors[idx] ;
        if(temp[i]<=i+(c*vals[i+1])/curr || i+1==N) solve(idx+1, curr) ;
        curr/=factors[idx] ;
        temp[i]=i-1 ;
        vals[i]/=factors[idx] ;
        temp[i]+=vals[i] ;
      }

  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> c ;
        N=min(n+1, 30LL) ;
        factorize(c) ;
        L=factors.size() ;
        for(int i=1 ; i<N ; i++) temp[i]=i-1, ans[i]=INF ;
        temp[N]=ans[N]=INF ;
        for(int i=1 ; i<=N ; i++) vals[i]=1 ;
        solve(0, 1) ;
        for(int i=1 ; i<N ; i++) cout<< ans[i] << " " ;
        cout<< endl ;
      }
  }
