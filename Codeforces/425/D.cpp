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

int n, q, a, b, c, x, level=18, A, B, C, D ;
vvi tree ;
vi depth ;
int parent[100000][20] ;

void dfs(int cur, int prev)
  {
    depth[cur]=depth[prev]+1 ;
    parent[cur][0]=prev ;
    for(int i=0 ; i<tree[cur].size() ; i++)
      if(tree[cur][i]!=prev)
        dfs(tree[cur][i], cur) ;
  }

void precomputeSparseMatrix(int n)
  {
    for(int i=1 ; i<level ; i++)
      for(int node=1 ; node<=n ; node++)
        if(parent[node][i-1]!=-1)
          parent[node][i]=parent[parent[node][i-1]][i-1] ;
  }

int lca(int u, int v)
  {
    if(depth[v]<depth[u]) swap(u, v) ;
    int diff=depth[v]-depth[u] ;
    for(int i=0 ; i<level ; i++)
      if((diff>>i)&1)
        v=parent[v][i] ;
    if(u==v) return u ;
    for(int i=level-1 ; i>=0 ; i--)
      if(parent[u][i]!=parent[v][i])
        {
          u=parent[u][i] ;
          v=parent[v][i] ;
        }
    return parent[u][0] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    tree.resize(n+1) ;
    depth.resize(n+1) ;
    depth[0]=0 ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> x ;
        tree[i].pb(x) ;
        tree[x].pb(i) ;
      }
    dfs(1,0);
    precomputeSparseMatrix(n);
    for(int i=0 ; i<q ; i++)
      {
        cin>> a >> b >> c ;
        A=lca(a, b) ;
        B=lca(b, c) ;
        C=lca(a, c) ;
        vi temp ;
        if(A!=B && B!=C)
          {
            D=lca(a, lca(b, c)) ;
            temp.pb(depth[a]-depth[D]) ;
            temp.pb(depth[b]-depth[D]) ;
            temp.pb(depth[c]-depth[D]) ;
            sort(all(temp)) ;
            cout<< temp[2] << endl ;
          }
      }

  }
