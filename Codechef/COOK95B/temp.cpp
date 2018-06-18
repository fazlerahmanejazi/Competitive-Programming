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

const int N=400010 ;

lli n, a, b, l, r, m, ans ;
vlli B ;
vector<pair<lli, lli>> tree, data ;
unordered_map<lli, lli> idx ;

void init()
  {
    ans=0 ;
    tree.clear() ; data.clear() ; idx.clear() ; B.clear() ;
    tree.assign(4*N, mp(0, 0)) ;
  }

pair<lli, lli> operator +(const pair<lli, lli>& x, const pair<lli, lli>& y) { return mp(x.fi+y.fi, x.se+y.se) ; }

pair<lli, lli> query(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return mp(0, 0) ;
    if(s>=qs && e<=qe) return tree[idx] ;
    return query(2*idx, s, (s+e)/2, qs, qe)+query(2*idx+1, (s+e)/2+1, e, qs, qe) ;
  }

void update(int idx, int s, int e, int pos, int val)
  {
    if(pos<s || pos>e) return ;
    if(s==e) { tree[idx]=tree[idx]+mp(val, 1) ; return ; }
    update(2*idx, s, (s+e)/2, pos, val) ;
    update(2*idx+1, (s+e)/2+1, e, pos, val) ;
    tree[idx]=tree[2*idx]+tree[2*idx+1] ;
  }

lli get(lli p)
  {
    lli l=0, r=n-1, m, res=0 ;
    pair<lli, lli> curr ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        curr=query(1, 0, n-1, 0, m) ;
        if(data[p].fi*(curr.se+1)>=curr.fi+data[p].se) l=m+1, res=max(res, curr.se+1) ;
        else r=m-1 ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n ;
        init() ;
        for(int i=0 ; i<n ; i++) cin>> a >> b, data.pb(mp(a, b)), B.pb(b) ;
        sort(all(data)) ;
        sort(all(B)) ;
        for(int i=0 ; i<n ; i++) idx[B[i]]=i ;
        for(int i=n-1 ; i>=0 ; i--)
          {
            ans=max(ans, get(i)) ;
            update(1, 0, n-1, idx[data[i].se], data[i].se) ;
          }
        cout<< ans << endl ;
      }
  }
