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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, x ;
    cin>> n ;
    vpii a, b ;
    vi c(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.pb(mp(x, i)) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        b.pb(mp(x, i)) ;
      }
    sort(all(a)) ;
    reverse(all(a)) ;
    sort(all(b)) ;
    for(int i=0 ; i<n ; i++)
      c[b[i].se]=a[i].fi ;
    for(int i=0 ; i<n ; i++)
      cout<< c[i] << " " ;
  }
