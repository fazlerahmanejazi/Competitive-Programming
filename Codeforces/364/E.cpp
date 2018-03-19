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

#define ld long double

ld check(lli n, ld l, ld v1, ld v2, lli k, ld y)
  {
    ld ans=0, x, t, T=0, curr ;
    while(n)
      {
        t=2*y/(v1+v2) ;
        n-=min(n, k) ;
        if(!n) ans=max(ans, T+l/v2) ;
        else
          {
            curr=T ;
            curr+=min(y, l)/v2 ;
            curr+=(l-min(y, l))/v1 ;
            ans=max(ans, curr) ;
          }
        x=t*v1 ;
        l-=x ;
        T+=t ;
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, k ;
    ld l, v1, v2, s, e, m1, m2, f1, f2 ;
    cin>> n >> l >> v1 >> v2 >> k ;
    s=0 ; e=l ;
    while (e-s>eps)
      {
        m1=s+(e-s)/3 ; m2=e-(e-s)/3 ;
        f1=check(n, l, v1, v2, k, m1) ;
        f2=check(n, l, v1, v2, k, m2) ;
        if(f1>f2) s=m1 ;
        else e=m2 ;
      }
    cout<< fixed << setprecision(9) << check(n, l, v1, v2, k, e) ;
  }
