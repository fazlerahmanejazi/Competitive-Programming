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

lli fact[400005] ;

void init()
  {
    fact[0]=1 ;
    for (lli i=1 ; i<=400000 ; i++)
      fact[i]=(fact[i-1]*i)%mod ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1;
    while(exp>0)
      {
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
      }
    return res%mod;
  }

lli getInverse(lli n)
  {
    return fast_exp(n, mod-2) ;
  }

lli divide(lli a, lli b)
  {
    a=a%mod ;
    b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

lli nPr(lli n, lli r)
  {
    if(r>n || r<0) return 0 ;
    return divide(fact[n], fact[n-r])%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    lli n, x, ans=1, k, y, z=0 ;
    cin>> n ;
    map<lli, lli> cnt ;
    vlli a ;
    for(int i=0 ; i<n ; i++) cin>> x, cnt[x]++ ;
    for(auto i:cnt) a.pb(i.se), z=max(z, i.se) ;
    sort(all(a)) ;
    for(int i=0 ; i<a.size()-1 ; i++)
      {
        x=a[i] ;
        ans*=nPr(z, x) ;
        ans%=mod ;
      }
    cout<< ans ;
  }
