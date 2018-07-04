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
    lli n, q, x, y, z, cnt ;
    cin>> n >> q ;
    vlli a(n), p2 ;
    map<lli, lli> check ;
    p2.pb(1) ;
    for(lli i=1 ; i<=31 ; i++) p2.pb(p2[i-1]*2) ;
    for(int i=0 ; i<n ; i++) cin>> x, check[x]++ ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> y ;
        cnt=0 ;
        for(int j=31 ; j>=0 ; j--)
          if(y>=p2[j])
            {
              z=min(y/p2[j], check[p2[j]]) ;
              y-=z*p2[j] ;
              cnt+=z ;
            }
        if(!y) cout<< cnt << endl ;
        else cout<< -1 << endl ;
      }
  }
