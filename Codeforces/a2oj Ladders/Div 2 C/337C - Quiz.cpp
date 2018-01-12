#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    long long int n, m, k, cnt, x, ans ;
    cin>> n >> m >> k ;
    x=m-(n/k)*(k-1)-n%k ;
    if(x<0) x=0 ;
    ans=((fast_exp(2, x+1)-2)*k+mod)%mod + (m-x*k+mod)%mod ;
    ans=ans%mod ;
    cout<< ans ;
  }
