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
    int n, ans=0, res=0 ;
    cin>> n ;
    vi a(n), b ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<n ; i++)
      if(a[i]%10==0) ans+=a[i] ;
      else b.pb(a[i]) ;
    sort(all(b)) ;
    reverse(all(b)) ;
    for(int i=0 ; i<b.size() ; i++)
      {
        ans+=b[i] ;
        if(ans%10) res=max(ans, res) ;
      }
    cout<< res ;
  }
