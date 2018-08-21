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

int left (int p) { return p<<1 ; }
int right(int p) { return (p<<1)+1 ; }
using node = tuple<int, int, int>  ;
#define L(p) get<0>(p)
#define R(p) get<1>(p)
#define correct(p) get<2>(p)

int n, q, lq, rq ;
string s ;
vector<node> tree ;

node merge(node x, node y)
  {
    node z ;
    int c=min(L(x), R(y)) ;
    L(z)=L(x)+L(y)-c ;
    R(z)=R(x)+R(y)-c ;
    correct(z)=c+correct(x)+correct(y) ;
    return z ;
  }

void build(int p, int l, int r)
  {
    if(l==r)
      {
        if(s[l]=='(') tree[p]=mt(1, 0, 0) ;
        else tree[p]=mt(0, 1, 0) ;
      }
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2 + 1, r) ;
        node x=tree[left(p)] ;
        node y=tree[right(p)] ;
        tree[p]=merge(x, y) ;
      }
  }

node query(int p, int l, int r, int lq, int rq)
  {
    if(lq>r || rq<l) return mt(0, 0, 0) ;
    if(lq<=l && rq>=r) return tree[p] ;
    node x=query(left(p), l, (l+r)/2, lq, rq) ;
    node y=query(right(p), (l+r)/2 + 1, r, lq, rq) ;
    return merge(x, y) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    n=s.length() ;
    tree.assign(4*n, mt(0, 0, 0)) ;
    build(1, 0, n-1) ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> lq >> rq ;
        lq-- ; rq-- ;
        node z=query(1, 0, n-1, lq, rq) ;
        cout<< 2*correct(z) << endl ;
      }
  }
