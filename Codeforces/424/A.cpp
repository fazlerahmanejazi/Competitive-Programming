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
    int n, l, r ;
    cin>> n ;
    vi a(n) ;
    l=0 ; r=n-1 ;
    bool check=true ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=1 ; i<n ; i++)
      if(a[i]<=a[i-1])
        {
          l=i-1 ;
          break ;
        }
      else if(i==n-1) l=n-1 ;
    for(int i=n-1 ; i>0 ; i--)
      if(a[i]>=a[i-1])
        {
          r=i ;
          break ;
        }
      else if(i==1) r=0 ;
    for(int i=l+1 ; i<=r ; i++)
      if(a[i]!=a[i-1])
        check=false ;
    if(check) cout<< "YES" ;
    else cout<< "NO" ;
  }
