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
    lli x, n, ans=1, y, z ;
    vlli px ;
    cin>> x >> n ;
    for(lli i=2 ; i*i<=x ; i++)
      if(!(x%i))
        {
          while(!(x%i)) x/=i ;
          px.pb(i) ;
        }
    if(x!=1) px.pb(x) ;
    for(auto p:px)
      {
        y=n ;
        z=0 ;
        while(y) y/=p, z+=y ;
        ans=(ans*fast_exp(p, z))%mod ;
      }
    cout<< ans ;
  }
