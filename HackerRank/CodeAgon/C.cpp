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

lli n, m, k, x, c, l, r, p, ans, curr, in, diff ;
vi a ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k ;
    a.pb(1) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        if(x) a.pb(i), c++ ;
      }
    if(c<m)
      {
        cout<< -1 ;
        return 0 ;
      }
    p=a.size() ;
    l=1 ; r=m ;
    in=a[1]-1 ;
    curr=diff=0 ;
    ans=INF ;
    for(int i=2 ; i<=m ; i++)
      {
        curr+=(a[i]-a[i-1])*(i-1)*k ;
        diff+=(a[i]-a[i-1])*k ;
      }
    ans=min(ans, curr+in) ;
    while(1)
      {
        r++ ; l++ ;
        if(r>=p) break ;
        curr-=diff ;
        curr+=(m-1)*k*(a[r]-a[r-1]) ;
        diff-=(a[l]-a[l-1])*k ;
        diff+=(a[r]-a[r-1])*k ;
        in=a[l]-1 ;
        ans=min(ans, curr+in) ;
      }
    cout<< ans ;
  }
