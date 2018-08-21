#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define finishl '\n'
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

const int N=400005 ;
int left (int p) {return p<<1 ;}
int right(int p) {return (p<<1)+1 ; }

lli n, m, u, v, x, c, T, res, q ;
string t ;
vvi adj ;
vlli light, start, finish, idx(4*N), tree(4*N, 0), lazy(4*N, 0), cnt ;

void init()
  {
    light.resize(n+1) ; adj.resize(n+1) ;
    start.resize(n+1) ; finish.resize(n+1) ;
    cnt.assign(n+1, 0) ;
  }

int dfs(int u, int par)
  {
    start[u]=++T ;
    idx[T]=u ;
    cnt[u]++ ;
    for(auto v:adj[u]) if(v!=par) cnt[u]+=dfs(v, u) ;
    finish[u]=++T ;
    idx[T]=u ;
    return cnt[u] ;
  }

void build(int p, int l, int r)
  {
    if(l==r) tree[p]=light[idx[l]] ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2+1, r) ;
        tree[p]=tree[left(p)]+tree[right(p)] ;
      }
  }


void range_update(int id,int left ,int right ,int lq ,int rq)
{
	if(lazy[id])
	{
		tree[id] = (right-left+1)-tree[id];
		if(left != right)
		{
			lazy[2*id] ^= 1;
			lazy[2*id+1] ^= 1;
		}
		lazy[id] = 0;
	}
	if( left > rq || right < lq)
		return;
	if(left >= lq && right <= rq)
	{
		tree[id] = (right-left+1)-tree[id];
		if(left != right)
		{
			lazy[2*id] ^= 1;
			lazy[2*id+1] ^= 1;
		}
		lazy[id] = 0;
		return;
	}
	int mid = (left+right)/2;
	range_update(2*id,left,mid,lq,rq);
	range_update(2*id+1,mid+1,right,lq,rq);
	tree[id] = tree[2*id] + tree[2*id+1];
}

int range_query(int id,int left ,int right,int lq ,int rq)
{
	if(lazy[id])
	{
		tree[id] = (right-left+1)-tree[id];
		if(left != right)
		{
			lazy[2*id] ^= 1;
			lazy[2*id+1] ^= 1;
		}
		lazy[id] = 0;
	}
	if( left > rq || right < lq)
		return 0;
	if(left >= lq && right <= rq)
	{
		return tree[id];
	}
	int mid = (left+right)/2;
	return	range_query(2*id,left,mid,lq,rq)+range_query(2*id+1,mid+1,right,lq,rq);
}

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    init() ;
    for(int i=2 ; i<=n ; i++)
      {
        cin>> x ;
        adj[i].pb(x) ;
        adj[x].pb(i) ;
      }
    for(int i=1 ; i<=n ; i++) cin>> light[i] ;
    dfs(1, -1) ;
    build(1, 1, T) ;
    cin>> m ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> t ;
        if(t=="pow")
          {
            cin>> x ;
            range_update(1, 1, T , start[x], finish[x]) ;
          }
        else
          {
            cin>> x ;
            q=range_query(1, 1, T, start[x], finish[x]) ;
            cout<< q/2 << endl ;
          }
      }
  }
