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
    int n, m, l, r, x, ans=0 ;
    cin>> n ;
    vi a(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=2 ; i<=n ; i++)
      for(int j=1 ; j<i ; j++)
        if(a[j]>a[i]) ans++ ;
    ans=ans%2 ;
    cin>> m ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> l >> r ;
        x=(r-l+1)*(r-l)/2 ;
        ans=(ans+x%2)%2 ;
        if(!ans) cout<< "even" << endl ;
        else cout<< "odd" << endl ;
      }
  }
