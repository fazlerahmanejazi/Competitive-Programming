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

int n, q, x, u, v, k, T, idx ;
vi seq, pos, last ;
vector<set<int>> adj ;

void dfs(int u)
  {
    seq.pb(u) ;
    pos[u]=T++ ;
    for(auto v:adj[u]) dfs(v) ;
    last[u]=T-1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    pos.resize(n+1) ;
    last.resize(n+1) ;
    adj.resize(n+1) ;
    for(int i=2 ; i<=n ; i++) cin>> x, adj[x].insert(i) ;
    dfs(1) ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> x >> k ;
        if(pos[x]+k-1<=last[x]) idx=seq[pos[x]+k-1] ;
        else idx=-1 ;
        cout<< idx << endl ;
      }
  }
