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

lli n, q, x, l, r, mode, median, idx, t ;
vlli a(N) ;
vector<pair<lli, lli>> treeMAX ;
vlli treeSUM ;

void init()
  {
    treeMAX.clear() ; treeSUM.clear() ;
    treeMAX.resize(4*N) ;
    treeSUM.assign(4*N, 0) ;
  }

void buildTreeSum(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e) { treeSUM[idx]=a[s] ; return ; }
    buildTreeSum(2*idx, s, (s+e)/2) ;
    buildTreeSum(2*idx+1, (s+e)/2+1, e) ;
    treeSUM[idx]=treeSUM[2*idx]+treeSUM[2*idx+1] ;
  }

lli querySum(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return 0LL ;
    if(s>=qs && e<=qe) return treeSUM[idx] ;
    return querySum(2*idx, s, (s+e)/2, qs, qe)+querySum(2*idx+1, (s+e)/2+1, e, qs, qe) ;
  }

void updateNodeSum(int idx, int s, int e, int pos, int val)
  {
    if(pos<s || pos>e) return ;
    if(s==e) { treeSUM[idx]=val ; return ; }
    updateNodeSum(2*idx, s, (s+e)/2, pos, val) ;
    updateNodeSum(2*idx+1, (s+e)/2+1, e, pos, val) ;
    treeSUM[idx]=treeSUM[2*idx]+treeSUM[2*idx+1] ;
  }

void buildTreeMax(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e) { treeMAX[idx]=mp(a[s], s) ; return ; }
    buildTreeMax(2*idx, s, (s+e)/2) ;
    buildTreeMax(2*idx+1, (s+e)/2+1, e) ;
    if(treeMAX[2*idx].fi>treeMAX[2*idx+1].fi) treeMAX[idx]=treeMAX[2*idx] ;
    else treeMAX[idx]=treeMAX[2*idx+1] ;
  }

pair<lli, lli> queryMax(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return mp(0LL, 0LL) ;
    if(s>=qs && e<=qe) return treeMAX[idx] ;
    pair<lli, lli> x, y ;
    x=queryMax(2*idx, s, (s+e)/2, qs, qe) ;
    y=queryMax(2*idx+1, (s+e)/2+1, e, qs, qe) ;
    if(x.fi>y.fi) return x ;
    else return y ;
  }

void updateNodeMax(int idx, int s, int e, int pos, int val)
  {
    if(pos<s || pos>e) return ;
    if(s==e) { treeMAX[idx]=mp(val, s) ; return ; }
    updateNodeMax(2*idx, s, (s+e)/2, pos, val) ;
    updateNodeMax(2*idx+1, (s+e)/2+1, e, pos, val) ;
    if(treeMAX[2*idx].fi>treeMAX[2*idx+1].fi) treeMAX[idx]=treeMAX[2*idx] ;
    else treeMAX[idx]=treeMAX[2*idx+1] ;
  }

lli getMedian(lli L, lli R)
  {
    lli m, l=L, r=R, ans=R, curr, val=(querySum(1, 0, n-1, L, R)+1)/2 ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        curr=querySum(1, 0, n-1, L, m) ;
        if(curr>=val) ans=min(ans, m), r=m-1 ;
        else l=m+1 ;
      }
    return ans+1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        init() ;
        cin>> n >> q ;
        for(int i=0 ; i<n ; i++) cin>> a[i] ;
        buildTreeMax(1, 0, n-1) ;
        buildTreeSum(1, 0, n-1) ;
        for(int i=0 ; i<q ; i++)
          {
            cin>> t ;
            if(t==1)
              {
                cin>> l >> r ;
                l-- ; r-- ;
                mode=queryMax(1, 0, n-1, l, r).se+1 ;
                median=getMedian(l, r) ;
                x=__gcd(mode, median) ;
                cout<< (mode/x)*median << endl ;
                //cout<< mode << " " << median << endl ;
              }
            else
              {
                cin>> idx >> x ;
                idx-- ;
                updateNodeMax(1, 0, n-1, idx, x) ;
                updateNodeSum(1, 0, n-1, idx, x) ;
              }
          }
      }
  }
