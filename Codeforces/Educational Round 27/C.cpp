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
    int n, l, r, c=1 ;
    set<int> t ;
    map<int, int> compress ;
    cin>> n ;
    vi a(500010, 0) ;
    vpii dur ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> l >> r ;
        l++ ; r++ ;
        dur.pb(mp(l, r)) ;
        t.insert(l) ;
        t.insert(r) ;
      }
    for(auto x:t)
      compress[x]=c++ ;
    for(int i=0 ; i<n ; i++)
      {
        tie(l, r)=dur[i] ;
        l=compress[l] ;
        r=compress[r] ;
        a[l]++ ;
        a[r+1]-- ;
      }
    bool possible=true ;
    for(int i=1 ; i<=500000 ; i++)
      {
        a[i]+=a[i-1] ;
        if(a[i]>=3)
          {
            possible=false ;
            break ;
          }
      }
    if(possible) cout<< "YES" ;
    else cout<< "NO" ;
  }
