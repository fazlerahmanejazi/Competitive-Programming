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

int n, h, w, g, p, t ;
map<int, vpii> X, Y ;
set<int> check ;
vpii ans ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> w >> h ;
    ans.resize(n+1) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> g >> p >> t ;
        if(g==1) X[p-t].pb(mp(p, i+1)) ;
        else Y[p-t].pb(mp(p, i+1)) ;
        check.insert(p-t) ;
      }
    for(auto c:check)
      {
        sort(all(X[c])) ; sort(all(Y[c])) ; reverse(all(Y[c])) ;
        queue<pii> temp ;
        for(auto i:X[c]) temp.push(mp(i.fi, h)) ;
        for(auto i:Y[c]) temp.push(mp(w, i.fi)) ;
        for(auto i:Y[c]) ans[i.se]=temp.front(), temp.pop() ;
        for(auto i:X[c]) ans[i.se]=temp.front(), temp.pop() ;
      }
    for(int i=1 ; i<=n ; i++) cout<< ans[i].fi << " " << ans[i].se << endl ;
  }
