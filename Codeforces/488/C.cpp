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
    int x, y, start, end, val, px, qx, py, qy, up, down ;
    bool pos=false ;
    vpii sq1, sq2 ;
    for(int i=0 ; i<4 ; i++) cin>> x >> y, sq1.pb(mp(x, y)) ;
    for(int i=0 ; i<4 ; i++) cin>> x >> y, sq2.pb(mp(x, y)) ;
    sort(all(sq1)) ; sort(all(sq2)) ;
    start=sq2[0].fi ; end=sq2[3].fi ;
    px=sq1[0].fi ; qx=sq1[3].fi ;
    py=min(sq1[0].se, sq1[1].se) ; qy=max(sq1[0].se, sq1[1].se) ;
    for(int i=start ; i<=end ; i++)
      {
        val=min(i-start, end-i) ;
        up=sq2[0].se+val ;
        down=sq2[0].se-val ;
        for(int j=down ; j<=up ; j++)
          if(i>=px && i<=qx && j>=py && j<=qy)
            pos=true ;
      }
    if(pos) cout<< "Yes" ;
    else cout<< "No" ;
  }
