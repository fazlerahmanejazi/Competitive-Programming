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
map<lli, lli> cnt[2] ;

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
    lli curr ;
    if(idx==e)
      {
        for(int i=1 ; i<=6 ; i++)
          {
            curr=(num*f[idx][i])%mod ;
            cnt[p][curr]++ ;
          }
        return ;
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
        cnt[0].clear() ; cnt[1].clear() ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=6 ; j++)
            cin>> f[i][j] ;
        if(n==1)
          {
            for(int i=1 ; i<=6 ; i++) if(f[1][i]==x) ans=1 ;
            cout<< ans ;
            continue ;
          }
        solve(1, 1, 0, n/2) ;
        solve((n/2)+1, 1, 1, n) ;
        auto x1=cnt[0].begin() ;
        while(x1!=cnt[0].end())
          {
            lli temp=divide(x, (*x1).fi) ;
            auto x2=cnt[1].find(temp) ;
            if(x2!=cnt[1].end()) ans+=((*x2).se)*((*x1).se) ;
            x1++ ;
          }
        cout<< ans << endl ;
      }
  }
