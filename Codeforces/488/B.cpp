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
    lli n, k, idx, p, c, x ;
    cin>> n >> k ;
    vlli ans(n, 0) ;
    vector<tuple<lli, lli, lli>> a(n) ;
    multiset<lli> temp ;
    for(int i=0 ; i<n ; i++) cin>> get<0>(a[i]) ;
    for(int i=0 ; i<n ; i++) cin>> get<1>(a[i]) ;
    for(int i=0 ; i<n ; i++) get<2>(a[i])=i ;
    sort(all(a)) ;
    for(auto i:a)
      {
        tie(p, c, idx)=i ;
        x=k ;
        ans[idx]+=c ;
        auto it=temp.begin() ;
        while(it!=temp.end() && x--) ans[idx]-=*it, it++ ;
        temp.insert(-c) ;
      }
    for(auto i:ans) cout<< i << " " ;
  }
