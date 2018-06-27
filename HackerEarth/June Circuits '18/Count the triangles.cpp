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

const int N=200005 ;

lli ans ;
int n, x ;
vi a(N), treeMAX(4*N) ;
vpii treeMIN(4*N) ;

void buildTreeMax(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e) { treeMAX[idx]=a[s] ; return ; }
    buildTreeMax(2*idx, s, (s+e)/2) ;
    buildTreeMax(2*idx+1, (s+e)/2+1, e) ;
    treeMAX[idx]=max(treeMAX[2*idx], treeMAX[2*idx+1]) ;
  }

lli queryMax(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return 0LL ;
    if(s>=qs && e<=qe) return treeMAX[idx] ;
    return max(queryMax(2*idx, s, (s+e)/2, qs, qe), queryMax(2*idx+1, (s+e)/2+1, e, qs, qe)) ;
  }

void updateNodeMax(int idx, int s, int e, int pos, int val)
  {
    if(pos<s || pos>e) return ;
    if(s==e) { treeMAX[idx]=val ; return ; }
    updateNodeMax(2*idx, s, (s+e)/2, pos, val) ;
    updateNodeMax(2*idx+1, (s+e)/2+1, e, pos, val) ;
    treeMAX[idx]=max(treeMAX[2*idx], treeMAX[2*idx+1]) ;
  }

void buildTreeMin(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e) { treeMIN[idx]=mp(a[s], s) ; return ; }
    buildTreeMin(2*idx, s, (s+e)/2) ;
    buildTreeMin(2*idx+1, (s+e)/2+1, e) ;
    if(treeMIN[2*idx].fi<treeMIN[2*idx+1].fi) treeMIN[idx]=treeMIN[2*idx] ;
    else treeMIN[idx]=treeMIN[2*idx+1] ;
  }

pair<lli, lli> queryMin(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return mp(inf, 0LL) ;
    if(s>=qs && e<=qe) return treeMIN[idx] ;
    pair<lli, lli> x, y ;
    x=queryMin(2*idx, s, (s+e)/2, qs, qe) ;
    y=queryMin(2*idx+1, (s+e)/2+1, e, qs, qe) ;
    if(x.fi<y.fi) return x ;
    else return y ;
  }

void updateNodeMin(int idx, int s, int e, int pos, int val)
  {
    if(pos<s || pos>e) return ;
    if(s==e) { treeMIN[idx]=mp(val, s) ; return ; }
    updateNodeMin(2*idx, s, (s+e)/2, pos, val) ;
    updateNodeMin(2*idx+1, (s+e)/2+1, e, pos, val) ;
    if(treeMIN[2*idx].fi<treeMIN[2*idx+1].fi) treeMIN[idx]=treeMIN[2*idx] ;
    else treeMIN[idx]=treeMIN[2*idx+1] ;
  }

pii getMin(int l, int r)
  {
    pii p1=queryMin(1, 0, n-1, l, r) ;
    updateNodeMin(1, 0, n-1, p1.se, inf) ;
    pii p2=queryMin(1, 0, n-1, l, r) ;
    updateNodeMin(1, 0, n-1, p1.se, p1.fi) ;
    return mp(p1.fi, p2.fi) ;
  }

int getMax(int l, int r)
  {
    return queryMax(1, 0, n-1, l, r) ;
  }

int get(int idx)
  {
    int l=idx+2, r=n-1, m, mx, res=idx ;
    pii mn ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        mn=getMin(idx, m) ;
        mx=getMax(idx, m) ;
        if(mn.fi+mn.se>=mx) l=m+1, res=max(res, m) ;
        else r=m-1 ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    buildTreeMax(1, 0, n-1) ;
    buildTreeMin(1, 0, n-1) ;
    ans=2*n-1 ;
    for(int i=0 ; i<n ; i++) ans+=max(get(i)-i-1, 0) ;
    cout<< ans ;
  }
