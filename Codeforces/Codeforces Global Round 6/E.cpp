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

const int N=200010 ;

lli n, q, tot, s, t, u, val, a[N], b[N] ;
map<pair<lli, lli>, lli> cnt ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a[i] ;
        tot+=a[i] ;
      }
    cin>> q ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> s >> t >> u ;
        val=cnt[mp(s, t)] ;
        if(val)
          {
            b[val]-- ;
            if(b[val]<a[val]) tot++ ;
          }
        b[u]++ ;
        cnt[mp(s, t)]++ ;
        if(b[u]<=a[u]) tot-- ;
        cout<< tot << endl ;
      }
  }
