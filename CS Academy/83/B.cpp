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

lli n, m, x, l=1, r=100000000000, mid, res=100000000000, ans ;
vlli a ;

bool check(lli x)
  {
    lli res=0 ;
    for(int i=0 ; i<n ; i++)
      if(a[i]<=mid) res++ ;
      else break ;
    if(mid-res>=m) return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=0 ; i<n ; i++) cin>> x, a.pb(x) ;
    sort(all(a)) ;
    while(l<=r)
      {
        mid=(l+r)/2 ;
        if(check(mid)) r=mid-1, res=min(res, mid) ;
        else l=mid+1 ;
      }
    ans=(res*(res+1))/2 ;
    for(int i=0 ; i<n ; i++) if(a[i]<=res) ans-=a[i] ;
    cout<< ans ;
  }
