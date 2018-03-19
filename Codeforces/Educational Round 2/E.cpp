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

int n, u, v ;
vvi adj ;
vector<map<int, int>> cnt ;
vlli c, curr, mx, p, ans ;

void init()
  {
    c.resize(n+1) ; adj.resize(n+1) ; ans.resize(n+1) ;
    mx.resize(n+1) ; cnt.resize(n+1) ; p.resize(n+1) ;
    curr.resize(n+1) ;
    for(int i=0 ; i<=n ; i++) p[i]=i ;
  }

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }

int same(int i, int j)
  {
    return find(i)==find(j) ;
  }

void update(int x, int val)
  {
    if(cnt[x][val]>mx[x]) mx[x]=cnt[x][val], curr[x]=val ;
    else if(cnt[x][val]==mx[x]) curr[x]+=val ;
  }

void unionset(int u, int v)
  {
    int x=find(u), y=find(v), val, count ;
    if(x==y) return ;
    if(cnt[x].size()<cnt[y].size()) swap(x, y) ;
    for(auto i:cnt[y])
      {
        tie(val, count)=i ;
        cnt[x][val]+=count ;
        update(x, val) ;
      }
    p[y]=x ;
  }

void dfs(int u, int prev)
  {
    cnt[u][c[u]]++ ; curr[u]=c[u] ; mx[u]=1 ;
    for(auto v:adj[u])
      if(v!=prev)
        {
          dfs(v, u) ;
          unionset(u, v) ;
        }
    ans[u]=curr[find(u)] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v ;
        adj[u].pb(v) ;
        adj[v].pb(u) ;
      }
    dfs(1, -1) ;
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
