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
    lli n, m, l=1, r=-1, mid, ans=0, curr, res ;
    cin>> n >> m ;
    vlli a(n+1), b(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i], r=max(r, a[i]) ;
    for(int i=1 ; i<=n ; i++) cin>> b[i] ;
    sort(all(b)) ;
    res=r ;
    while(l<=r)
      {
        mid=(l+r)/2 ;
        curr=0 ;
        for(int i=1 ; i<=n ; i++) curr+=max(0LL, a[i]-mid) ;
        if(curr<=m) r=mid-1, res=mid ;
        else l=mid+1 ;
      }
    for(int i=1 ; i<=n ; i++) a[i]=min(a[i], res) ;
    sort(all(a)) ;
    reverse(all(b)) ;
    for(int i=1 ; i<=n ; i++) ans+=a[i]*b[i] ;
    cout<< ans ;
}
