#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

lli n, x, f[15][7], ans ;
set<lli> list[2] ;

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
    a=a%mod ; b=b%mod ;
    return (a*(getInverse(b)%mod))%mod ;
  }

void solve(int idx, lli num, int p, int e)
  {
    if(idx==e)
      for(int i=1 ; i<=6 ; i++)
        {
          curr=(num*f[idx][i])%mod ;
          list[p].insert(curr) ;
        }
    for(int i=1 ; i<=6 ; i++)
      {
        curr=(num*f[idx][i])%mod ;
        solve(idx+1, curr, p, e) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> x ;
        ans=0 ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=6 ; j++)
            cin>> f[i][j] ;
        solve(1, 1, 0, n/2) ;
        solve((n/2)+1, 1, 0, n) ;
        for(auto x1:list[0])
          {
            x2=divide(x, x1) ;
            if(list[1].find(x2)!=list[1].end()) ans++ ;
          }
        cout<< ans << endl ;
      }
  }
