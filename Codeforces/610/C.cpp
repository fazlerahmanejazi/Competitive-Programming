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
    int tc ;
    cin>> tc ;
    while(tc--)
      {
        lli n, T, a, b, req=0, tot=0, ans=0, curr, cnta=0, cntb=0, rema=0, remb=0 ;
        cin>> n >> T >> a >> b ;
        vlli type(n), ti(n) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> type[i] ;
            if(type[i]) remb++ ;
            else rema++ ;
          }
        for(int i=0 ; i<n ; i++) cin>> ti[i] ;
        vector<pair<lli, lli>> p ;
        for(int i=0 ; i<n ; i++) p.pb(mp(ti[i], type[i])) ;
        sort(all(p)) ;
        for(auto i:p)
          {
            tot=i.fi-1 ;
            if(req<=tot)
              {
                ans=max(ans, cnta+cntb) ;
                lli extra=tot-req, x, y ;
                if(extra>0)
                  {
                    x=min(extra/a, rema) ;
                    extra-=x*a ;
                    y=min(extra/b, remb) ;
                    extra-=y*b ;
                    ans=max(ans, cnta+cntb+x+y) ;
                  }
              }
            if(i.se) req+=b, cntb++, remb-- ;
            else req+=a, cnta++, rema-- ;
          }
        if(req<=T) ans=n ;
        cout<< ans << endl ;
      }
  }
