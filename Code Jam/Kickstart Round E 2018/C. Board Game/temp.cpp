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

vector<vlli> B ;

ld getWins(vlli &b, vlli &a, vlli &c, lli n)
  {
    ld ans ;
    vlli d ;
    lli wins=0, curr, y=0, tot=0 ;
    sort(all(b)) ;
    do
      {
        curr=0 ; d.clear() ;
        for(int i=0 ; i<n ; i++) y+=b[i] ;
        d.pb(y) ; y=0 ;
        for(int i=n ; i<2*n ; i++) y+=b[i] ;
        d.pb(y) ; y=0 ;
        for(int i=2*n ; i<3*n ; i++) y+=b[i] ;
        d.pb(y) ; y=0 ;
        for(int i=0 ; i<3 ; i++) if(c[i]>d[i]) curr++ ;
        if(curr>=2) wins++ ;
      } while(next_permutation(all(b))) ;
    ans=wins ;
    ans/=tot ;
    return ans ;
  }

ld getWins2(vlli &a, vlli &c, lli n)
  {
    ld ans ;
    lli wins=0, curr, y=0, tot=0 ;
    for(auto d:B)
      {
        curr=0 ;
        for(int i=0 ; i<3 ; i++) if(c[i]>d[i]) curr++ ;
        if(curr>=2) wins++ ;
        tot++ ;
      }
    ans=wins ;
    ans/=tot ;
    return ans ;
  }

void permute(vlli &b, lli l, lli r, lli n)
  {
    if(l==r)
      {
        vlli d ;
        lli y=0 ;
        for(int i=0 ; i<n ; i++) y+=b[i] ;
        d.pb(y) ; y=0 ;
        for(int i=n ; i<2*n ; i++) y+=b[i] ;
        d.pb(y) ; y=0 ;
        for(int i=2*n ; i<3*n ; i++) y+=b[i] ;
        d.pb(y) ;
        B.pb(d) ;
      }
    else
      {
        for(int i=l ; i<=r ; i++)
          {
            swap(b[l], b[i]) ;
            permute(b, l+1, r, n) ;
            swap(b[l], b[i]) ;
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        B.clear() ;
        lli n, x=0, y=0, z=0 ;
        ld ans=0 ;
        set<lli> S ;
        cin>> n ;
        vlli a(3*n), b(3*n), c, temp ;
        for(int i=0 ; i<3*n ; i++) cin>> a[i] ;
        for(int i=0 ; i<3*n ; i++) cin>> b[i] ;
        sort(all(a)) ;
        for(int i=0 ; i<n ; i++) x+=a[i] ;
        for(int i=n ; i<3*n ; i++) temp.pb(a[i]), z+=a[i] ;
        do
          {
            y=0 ;
            for(int i=0 ; i<n ; i++) y+=temp[i] ;
            S.insert(y) ;
          } while(next_permutation(all(temp))) ;
        permute(b, 0, 3*n-1, n) ;
        for(auto i:S)
          {
            c.clear() ;
            c.pb(x) ; c.pb(i) ; c.pb(z-i) ;
            ans=max(ans, getWins2(a, c, n)) ;
          }
        cout<< "Case #"<< tc << ": " ;
        cout<< fixed << setprecision(9) << ans << endl ;
      }
  }
