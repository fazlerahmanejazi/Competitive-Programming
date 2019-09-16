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

lli n, m, l, x, y, idx, curr, ans[1000010] ;
vector<pair<lli, lli>> a ;
map<lli, lli> cnt ;
  
int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> l ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x >> y ;
        if(y>l) continue ;
        cnt[x+y-l]++ ;
        cnt[x-y+l+1]-- ;
      }
    for(int i=1 ; i<=m ; i++)
      {
        cin>> x ;
        a.pb(mp(x, i)) ;
      }
    sort(all(a)) ;
    for(auto i:cnt)
      {
        while(idx<m && a[idx].fi<i.fi) ans[a[idx++].se]=curr ;
        curr+=i.se ;
      }
    for(int i=1 ; i<=m ; i++) cout<< ans[i] << endl ;
  }
