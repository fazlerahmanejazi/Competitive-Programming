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
    lli n, m, x, l, r, tot, curr=0 ;
    cin>> n >> m ;
    vector<tuple<lli, lli, lli>> a ;
    for(int i=0 ; i<n ; i++) cin>> l >> r, a.pb(mt(l-r, l, r)), curr+=l ;
    sort(all(a)) ;
    reverse(all(a)) ;
    if(curr<=m) return cout<< 0, 0 ;
    for(int i=0 ; i<n ; i++)
      {
        tie(x, l, r)=a[i] ;
        curr-=l ;
        curr+=r ;
        if(curr<=m) return cout<< i+1, 0 ;
      }
    cout<< -1 ;
  }
