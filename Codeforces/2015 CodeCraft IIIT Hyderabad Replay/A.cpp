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

const int N=100005 ;
const int blockSize=sqrt(N) ;

int n, m, d, u, v, y, x, t, T ;
lli freq[blockSize+5][N], sum[blockSize+5] ;
vi start(N), finish(N), depth(N), rev(N) ;
vlli val(N, 0) ;
vvi adj(N) ;

void dfs(int u, int prev, int d)
  {
    start[u]=++T ;
    rev[T]=u ;
    depth[u]=d ;
    for(auto v:adj[u]) if(v!=prev) dfs(v, u, d+1) ;
    finish[u]=T ;
  }

int get(int idx)
  {
    return idx/blockSize ;
  }

void update(int d, lli y)
  {
    val[d]+=y ;
    int B=0 ;
    while(B<=T/blockSize)
      {
        sum[B]+=freq[B][d]*y ;
        B++ ;
      }
  }

lli query(int x)
  {
    lli res=0 ;
    int l=start[x], r=finish[x], p=l ;
    while(p<=r && get(p)==get(l)) res+=val[depth[rev[p]]], p++ ;
    while(p+blockSize<=r) res+=sum[get(p)], p+=blockSize ;
    while(p<=r) res+=val[depth[rev[p]]], p++ ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1, 0) ;
    for(int i=1 ; i<=T ; i++) freq[get(i)][depth[rev[i]]]++ ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> t ;
        if(t==1)
          {
            cin>> d >> y ;
            update(d, y) ;
          }
        else
          {
            cin>> x ;
            cout<< query(x) << endl ;
          }
      }
  }
