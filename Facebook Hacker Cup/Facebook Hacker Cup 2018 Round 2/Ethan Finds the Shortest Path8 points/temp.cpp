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
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli n, k, u, v, w, x, curr, lim, y=0, ans ;
        vi a ;
        vector<tuple<lli, lli, lli>> edges ;
        cin>> n >> k ;
        curr=2 ;
        x=k ;
        edges.pb(mt(1, n, k)) ;
        lim=min(k-2, n-2) ;
        if(lim>0)
          {
            a.pb(n) ;
            while(lim--) a.pb(curr++) ;
            a.pb(1) ;
            curr=k-1 ;
            if(a.size()>2) for(int i=a.size()-1 ; i>0 ; i--) y+=curr, edges.pb(mt(a[i], a[i-1], curr--)) ;
            ans=abs(x-y) ;
          }
        else ans=0 ;
        cout<< "Case #" << tc << ": " << ans<< endl ;
        for(auto i:edges)
          {
            tie(u, v, w)=i ;
            cout<< u << " " << v << " " << w << endl ;
          }
      }
  }
