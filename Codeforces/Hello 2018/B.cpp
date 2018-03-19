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

int n, x ;
bool pos=true ;
vvi adj(1005) ;
vi deg(1005) ;
vb isleaf(1005) ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> x ;
        adj[x].pb(i) ;
        adj[i].pb(x) ;
        deg[x]++ ;
        deg[i]++ ;
      }
    for(int i=1 ; i<=n ; i++) if(deg[i]==1 && i!=1) isleaf[i]=true ;
    for(int i=1 ; i<=n ; i++)
      if(!isleaf[i])
        {
          int cnt=0 ;
          for(auto v:adj[i]) if(isleaf[v]) cnt++ ;
          if(cnt<3) pos=false ;
        }
    if(pos) cout<< "Yes" ;
    else cout<< "No" ;
  }
