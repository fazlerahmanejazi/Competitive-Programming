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

int n, m, l, r ;
vi a, tree ;
vector<tuple<int, int, int>> d ;

int left (int p) { return p<<1 ; }
int right(int p) { return (p<<1)+1 ; }

void build(int p, int l, int r)
  {
    if(l==r) { tree[p]=a[l] ; return ; }
    build(left(p), l, (l+r)/2) ;
    build(right(p), (l+r)/2 + 1, r) ;
    tree[p]=max(tree[left(p)], tree[right(p)]) ;
  }

int query(int p, int l, int r, int i, int j)
  {
    if(i>r || j<l) return -1 ;
    if(i<=l && j>=r) return tree[p] ;
    return max(query(left(p), l, (l+r)/2, i, j), query(right(p), (l+r)/2 + 1, r, i, j)) ;
  }

bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b)
  {
    int l1, l2, r1, r2, x, y ;
    tie(l1, r1, ignore)=a ;
    tie(l2, r2, ignore)=b ;
    if(l1==l2 && r1==r2) return false ;
    bool p, q=true ;
    if(l1>l2) swap(l1, l2), swap(r1, r2), q=false ;
    if(l1<=l2 && r2<=r1)
      {
        p=false ;
        if(!q) p=!p ;
        return p ;
      }
    x=min(r1, l2-1) ; y=max(r1+1, l2) ;
    r1=x ; l2=y ;
    x=query(1, 0, n-1, l1-1, r1-1); y=query(1, 0, n-1, l2-1, r2-1) ;
    if(x<y) p=true ;
    else p=false ;
    if(!q) p=!p ;
    return p ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n) ;
    tree.resize(4*n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    build(1, 0, n-1) ;
    cin>> m ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> l >> r ;
        d.pb(mt(l, r, i+1)) ;
      }
    sort(all(d), cmp) ;
    for(auto i:d) cout<< get<2>(i) << endl ;
  }
