#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
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

bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
  {
    return get<0>(a)<get<0>(b) ;
  }

struct node
  {
    int val ;
    node* left, *right ;
    node() {}
    node(node* l, node* r, int v)
    {
        left=l;
        right=r;
        val=v;
    }
  } ;

vector<node*> root ;

int T, n, m, u, v, c, k, x, pos, xorU, xorV, ans ;
vector<vpii> adj ;
vector<tuple<int, int, int>> dist ;
vi par, magNum ;
map<int, int> cnc ;
vb visit ;

void init()
  {
    adj.clear() ; visit.clear() ; par.clear() ; dist.clear() ; root.clear() ; magNum.clear() ; cnc.clear() ;
    adj.resize(n+1) ; par.resize(n+1) ; root.resize(n+1) ;
    visit.assign(n+1, false) ;
    par[1]=-1 ;
    dist.pb(mt(0, 1, 0)) ;
    for(int i=1 ; i<=n ; i++)
      root[i]=new node(NULL, NULL, 0) ;
  }

void dfs(int u, int d)
  {
    visit[u]=true ;
    for(int i=0 ; i<adj[u].size() ; i++)
      {
        int v=adj[u][i].fi, c=adj[u][i].se ;
        if(!visit[v])
          {
            dist.pb(mt(d+1, v, c)) ;
            par[v]=u ;
            dfs(v, d+1) ;
          }
      }
  }

void build(node* n, int l ,int r)
  {
    if(l==r)
      {
        n->val=0 ;
        return ;
      }
    int m=(l+r)/2 ;
    n->left=new node(NULL, NULL, 0) ;
    n->right=new node(NULL, NULL, 0) ;
    build(n->left, l, m) ;
    build(n->right, m+1, r) ;
    n->val=0 ;
  }

void upgrade(node* prev, node* curr, int l, int r, int idx)
  {
    if(idx>r || idx<l || l>r)
      return ;
    if(l==r)
      {
        curr->val=(prev->val)^(magNum[idx]) ;
        return ;
      }
    int m=(l+r)/2 ;
    if(idx<=m)
      {
        curr->right=prev->right ;
        curr->left=new node(NULL, NULL, 0) ;
        upgrade(prev->left, curr->left, l, m, idx) ;
      }
    else
      {
        curr->left=prev->left ;
        curr->right=new node(NULL, NULL, 0) ;
        upgrade(prev->right, curr->right, m+1, r, idx) ;
      }
    curr->val=(curr->left->val)^(curr->right->val) ;
  }

int query(node* n, int l, int r, int lq, int rq)
  {
    if(lq>r || rq<l || l>r)
      return 0 ;
    if(lq<=l && r<=rq)
      return n->val ;
    int m=(l+r)/2 ;
    int x=query(n->left, l, m, lq, rq) ;
    int y=query(n->right, m+1, r, lq, rq) ;
    return x^y ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=0 ; i<n-1 ; i++)
          {
            cin>> u >> v >> c ;
            adj[u].pb(mp(v, c)) ;
            adj[v].pb(mp(u, c)) ;
            magNum.pb(c) ;
          }
        sort(all(magNum)) ;
        for(int i=0 ; i<n-1 ; i++)
          cnc[magNum[i]]=i ;
        dfs(1, 0) ;
        sort(all(dist), cmp) ;
        build(root[1], 0, n-1) ;
        for(int i=1 ; i<n ; i++)
          {
            tie(x, v, c)=dist[i] ;
            u=par[v] ;
            upgrade(root[u], root[v], 0, n-1, cnc[c]) ;
          }
        cin>> m ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> v >> k ;
            if(k<magNum[0]) cout<< 0 << endl ;
            else
              {
                pos=upper_bound(all(magNum), k)-magNum.begin() ;
                pos-- ;
                xorU=query(root[u], 0, n-1, 0, pos) ;
                xorV=query(root[v], 0, n-1, 0, pos) ;
                ans=xorU^xorV ;
                cout<< ans << endl ;
              }
          }
      }
  }
