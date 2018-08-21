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
    lli l, r, x, y, k, temp, idx=2, a, b=1 ;
    double val ;
    cin>> l >> r >> x >> y >> k ;
    a=k ;
    b=1 ;
    while(a<=r)
      {
        if(b>=x && b<=y && a>=l && a<=r)
          {
            cout<< "YES" ;
            return 0 ;
          }
        a=k*idx ;
        b=idx ;
        idx++ ;
      }
    cout<< "NO" ;
  }
