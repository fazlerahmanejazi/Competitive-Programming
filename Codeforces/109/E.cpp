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

lli n, m, u, v, p[1000010], H[1000010], last=-1, ans, cnt, b=31 ;
vpii edges ;
vlli h ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    p[0]=b ;
    for(int i=1 ; i<=1000000 ; i++) p[i]=(p[i-1]*b) ;
    cin>> n >> m ;
    h.assign(n, 0) ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v ;
        edges.pb(mp(u, v)) ;
        H[u]=(H[u]+p[v]) ;
        H[v]=(H[v]+p[u]) ;
      }
    for(int i=1 ; i<=n ; i++) h[i-1]=H[i] ;
    sort(all(h)) ;
    for(auto i:h)
      if(i==last) cnt++ ;
      else
        {
          ans+=(cnt*(cnt-1))/2 ;
          cnt=1 ;
          last=i ;
        }
    ans+=(cnt*(cnt-1))/2 ;
    for(auto i:edges)
      {
        tie(u, v)=i ;
        H[u]=(H[u]-p[v]) ;
        H[v]=(H[v]-p[u]) ;
        if(H[u]==H[v]) ans++ ;
        H[u]=(H[u]+p[v]) ;
        H[v]=(H[v]+p[u]) ;
      }
    cout<< ans ;
  }
