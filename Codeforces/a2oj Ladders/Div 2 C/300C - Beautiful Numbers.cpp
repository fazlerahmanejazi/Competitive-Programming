#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

long long int a, b, n, sum, ans=0, i, temp, digit ;
vlli fact(1000000+10) ;

bool check(long long int x)
  {
    while(x)
      {
        digit=x%10 ;
        if(digit!=a && digit!=b) return false ;
        x/=10 ;
      }
    return true ;
  }

long long int fast_exp(long long int base, long long int exp)
  {
    long long int res=1;
    while(exp>0)
      {
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
      }
    return res%mod;
  }

long long int mod_inv(long long int a)
  {
    return fast_exp(a, mod-2) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    fact[0]=1 ;
    for(i=1 ; i<=1000000 ; i++)
      fact[i]=(i*fact[i-1])%mod ;
    cin>> a >> b >> n ;
    for(i=0 ; i<=n ; i++)
      {
        sum=a*i+b*(n-i) ;
        if(check(sum)) ans+=(fact[n]*((mod_inv(fact[i])*mod_inv(fact[n-i]))%mod)%mod) ;
      }
    cout<< ans%mod ;
  }
