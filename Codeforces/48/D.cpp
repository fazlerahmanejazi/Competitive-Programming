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

int n, ans=inf, zero ;
vi a ;

int check(int s, int r, int cnt)
  {
    if(!r) return inf ;
    for(int i=s ; i<n-1 ; i++)
      if(a[i+1]!=a[i]*r)
        cnt++, i++ ;
    return cnt ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        if(!a[i]) zero++ ;
      }
    if(n==2)
      {
        if(!a[1]) cout<< 0 ;
        else if(!a[0]) cout<< 1 ;
        else if(!(a[0]%a[1]) || !(a[1]%a[0])) cout<< 0 ;
        else cout<< 1 ;
        return 0 ;
      }
    if(a[0]) ans=min({ans, check(1, a[1]/a[0], 0), check(2, a[2]/a[0], 1)}) ;
    if(a[1]) ans=min(ans, check(2, a[2]/a[1], 1)) ;
    if(a[0]) ans=min(ans, n-zero-1) ;
    reverse(all(a)) ;
    if(a[0]) ans=min({ans, check(1, a[1]/a[0], 0), check(2, a[2]/a[0], 1)}) ;
    if(a[1]) ans=min(ans, check(2, a[2]/a[1], 1)) ;
    ans=min(ans, n-zero) ;
    cout<< min(ans, 2) ;
  }
