#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
#define MOD (lli)1000000009
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

lli fast_exp(lli base, lli exp, lli m)
  {
    base=base%m ;
    lli res=1;
    while(exp>0)
      {
        if(exp%2==1) res=(res*base)%m ;
        base=(base*base)%m ;
        exp/=2;
      }
    return res%m ;
  }

lli modInv(lli a, lli m)
  {
    return fast_exp(a, m-2, m) ;
  }

lli solve(lli p, lli q1, lli q2, lli m)
  {
    lli ans ;
    ans=q1%m ; q2=q2%m ;
    ans=(ans*q2)%m ;
    ans=(ans*(modInv(p, m)%m))%m ;
    return ans ;
  }

lli gcd(lli a, lli b)
  {
    return b==0? a:gcd(b, a%b);
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    lli n, p, q, q1, q2, x ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        if(n==1)
          {
            cout<< "0 0" << endl ;
            continue ;
          }
        n-- ;
        p=2*n-1 ;
        if(n%2)
          {
            q1=(n+1)/2 ;
            q2=n ;
          }
        else
          {
            q1=n/2 ;
            q2=n+1 ;
          }
        x=gcd(p, q1) ;
        p/=x ; q1/=x ;
        x=gcd(p, q2) ;
        p/=x ; q2/=x ;
        cout<< solve(p, q1, q2, mod) << " " << solve(p, q1, q2, MOD) << endl ;
      }
  }
