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

lli X, d, p=2, idx, a=1 ;
map<lli, lli> cnt ;
vlli sq, ans ;

void solve()
  {
    idx=upper_bound(all(sq), X)-sq.begin() ;
    X-=sq[idx-1] ;
    cnt[a]+=idx ;
    a+=d+1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> X >> d ;
    while(1)
      {
        sq.pb(p-1) ;
        p*=2 ;
        if(p>1e10) break ;
      }
    while(X) solve() ;
    for(auto i:cnt) for(int j=0 ; j<i.se ; j++) ans.pb(i.fi) ;
    cout<< ans.size() << endl ;
    for(auto i:ans) cout<< i << " " ;
  }
