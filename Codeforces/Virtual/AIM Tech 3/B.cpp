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
    int n, x, r1, r2, l1, l2 ;
    vi ans ;
    cin>> n >> x ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    sort(all(a)) ;
    if(n==1)
      {
        cout<< 0 ;
        return 0 ;
      }
    r1=max(0, a[n-1]-x) ;
    r2=max(0, a[n-2]-x) ;
    l1=max(0, x-a[0]) ;
    l2=max(0, x-a[1]) ;
    ans.pb(2*r1+l2) ; ans.pb(2*l2+r1) ;
    ans.pb(2*r2+l1) ; ans.pb(2*l1+r2) ;
    sort(all(ans)) ;
    cout<< ans[0] ;
  }
