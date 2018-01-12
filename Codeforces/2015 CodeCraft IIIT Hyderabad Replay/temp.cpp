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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, x ;
    lli ans ;
    cin>> T ;
    while(T--)
      {
        vi n(3) ;
        vvi a(3) ;
        ans=0 ;
        for(int i=0 ; i<3 ; i++)
          {
            cin>> n[i] ;
            for(int j=0 ; j<n[i] ; j++) cin>> x, a[i].pb(x) ;
          }
        vlli suf(n[1]+2, 0) ;
        for(int i=min(n[1], n[2])-1 ; i>=0 ; i--)
          {
            x=lower_bound(a[2].begin()+i, a[2].end(), a[1][i])-a[2].begin() ;
            suf[i]=suf[i+1]+(n[2]-x) ;
          }
        for(int i=0 ; i<min({n[0], n[1], n[2]}) ; i++)
          {
            x=lower_bound(a[1].begin()+i, a[1].end(), a[0][i])-a[1].begin() ;
            ans+=suf[x] ;
          }
        cout<< ans << endl ;
      }
  }
