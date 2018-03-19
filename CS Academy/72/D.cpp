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

int n, m, u, v, x, s ;
vi visit, inDeg, nxt ;

void dfs(int u, int prev)
  {
    visit[u]=1 ;
    if(!visit[nxt[u]]) dfs(nxt[u], u) ;
    if(prev!=-1) cout<< prev << " " << u << endl ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    nxt.assign(n+1, 0) ;
    inDeg.assign(n+1, 0) ;
    visit.assign(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        nxt[i]=x ;
        inDeg[x]++ ;
      }
    for(int i=1 ; i<=n ; i++) if(!visit[i] && !inDeg[i]) dfs(i, -1) ;
    for(int i=1 ; i<=n ; i++) if(!visit[i]) dfs(i, -1) ;
  }
