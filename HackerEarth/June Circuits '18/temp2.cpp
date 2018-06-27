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

#define sz 100000

vi euler, depthArr ;
int FAI[sz], level[sz], ptr, dp[sz][22], logn[sz], p2[22] ;

lli n, m, u, v, x, w, idx, MXLOG, curr ;
vector<vpii> adj ;
vvi par ;
vlli dist, h, newDist ;

void init()
  {
    adj.resize(sz) ; h.assign(sz, 0) ;
    dist.resize(sz) ;
    newDist.resize(sz) ;
    MXLOG=20 ;
  }

void buildSparseTable(int n)
  {
    memset(dp, -1, sizeof(dp)) ;
    for(int i=1 ; i<n ; i++)
    dp[i-1][0]=(depthArr[i]>depthArr[i-1])?i-1:i ;
    for(int l=1 ; l<20 ; l++)
      for(int i=0 ; i<n ; i++)
        if(dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1) dp[i][l]=(depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])?dp[i+p2[l-1]][l-1]:dp[i][l-1] ;
    else break ;
  }

int query(int l,int r)
  {
    int d=r-l ;
    int dx=logn[d] ;
    if(l==r) return l ;
    if(depthArr[dp[l][dx]]>depthArr[dp[r-p2[dx]][dx]]) return dp[r-p2[dx]][dx] ;
    else return dp[l][dx] ;
  }

void preprocess()
  {
    p2[0]=1 ;
    for(int i=1 ; i<20 ; i++)
    p2[i]=p2[i-1]*2 ;
    int val=1, ptr=0 ;
    for(int i=1 ; i<sz ; i++)
      {
        logn[i]=ptr-1 ;
        if(val==i) val*=2, logn[i]=ptr++ ;
      }
  }

void dfs(int cur, int prev, int dep, lli D)
  {
    if(FAI[cur]==-1) FAI[cur]=ptr ;
    level[cur]=dep ;
    euler.pb(cur) ;
    dist[cur]=D ;
    ptr++ ;
    for(auto x:adj[cur])
      if(x.fi!=prev)
        {
          dfs(x.fi, cur, dep+1, D+x.se) ;
          euler.pb(cur) ;
          ptr++ ;
        }
  }

void makeArr() { for(auto x:euler) depthArr.pb(level[x]) ; }

int LCA(int u,int v)
  {
    if(u==v) return u ;
    if(FAI[u]>FAI[v]) swap(u, v) ;
    return euler[query(FAI[u], FAI[v])] ;
  }

lli get(int u, int v)
  {
    lli res=dist[u]+dist[v]-2*dist[LCA(u, v)] ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=1 ; i<n ; i++)
      {
        cin>> u >> v >> w ;
        adj[u].pb(mp(v, w)) ;
        adj[v].pb(mp(u, w)) ;
      }
    preprocess() ;
    ptr=0 ;
    memset(FAI, -1, sizeof FAI) ;
    dfs(1, -1, 0, 0) ;
    makeArr() ;
    buildSparseTable(depthArr.size()) ;
    cout<< 0 << " " ;
    newDist[1]=0 ;
    for(int i=2 ; i<=n ; i++)
      {
        lli curr=INF ;
        for(int j=1 ; j<i ; j++)  curr=min(curr, newDist[j]+get(i, j)) ;
        newDist[i]=curr ;
        cout<< curr << " " ;
      }
  }
