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

int T, n, l, a, b, x, s, e, m1, m2 ;
lli ans ;
vi pos ;

lli calc(int idx)
  {
    lli res=0 ;
    for(int i=0 ; i<n ; i++)
      {
        res+=abs(idx-pos[i]) ;
        idx+=l ;
      }
    if(idx>b) res=2*INF ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        pos.clear() ;
        ans=2*INF ;
        cin>> n >> l >> a >> b ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            pos.pb(x) ;
          }
        sort(all(pos)) ;
        s=a ; e=b ;
        while(e-s>=3)
          {
            m1=s+(e-s)/3 ;
            m2=e-(e-s)/3 ;
            if(calc(m1)>calc(m2)) s=m1 ;
            else e=m2 ;
          }
        for(int i=s ; i<=e ; i++)
          ans=min(ans, calc(i)) ;
        cout<< ans << endl ;
      }
  }
