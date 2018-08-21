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
    lli n, m, s, e, v, q, x1, y1, x2, y2, idx, ans, curr ;
    cin>> n >> m >> s >> e >> v ;
    vlli elev(e), stairs(s) ;
    for(int i=0 ; i<s ; i++) cin>> stairs[i] ;
    for(int i=0 ; i<e ; i++) cin>> elev[i] ;
    sort(all(stairs)) ;
    sort(all(elev)) ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> x1 >> y1 >> x2 >> y2 ;
        if(x1==x2) ans=abs(y2-y1) ;
        else ans=INF ;
        if(s)
          {
            idx=upper_bound(all(stairs), y2)-stairs.begin() ;
            if(idx!=s)
              {
                curr=abs(y2-stairs[idx])+abs(y1-stairs[idx])+abs(x2-x1) ;
                ans=min(curr, ans) ;
              }
            idx-- ;
            if(idx>=0)
              {
                curr=abs(y2-stairs[idx])+abs(y1-stairs[idx])+abs(x2-x1) ;
                ans=min(curr, ans) ;
              }
          }
        if(e)
          {
            idx=upper_bound(all(elev), y2)-elev.begin() ;
            if(idx!=e)
              {
                curr=abs(y2-elev[idx])+abs(y1-elev[idx])+ceil((1.0*abs(x2-x1)/(1.0*v))) ;
                ans=min(curr, ans) ;
              }
            idx-- ;
            if(idx>=0)
              {
                curr=abs(y2-elev[idx])+abs(y1-elev[idx])+ceil((1.0*abs(x2-x1)/(1.0*v))) ;
                ans=min(curr, ans) ;
              }
          }
        cout<< ans << endl ;
      }
  }
