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

template<class T, int SZ> struct BIT
  {
    T bit[SZ+1] ;
    BIT() { memset(bit, 0, sizeof bit) ; }
    void init() { memset(bit, 0, sizeof bit) ; }
    void update(int k, T val)  { for( ; k<=SZ ; k+=(k&-k)) bit[k]+=val ; }
    T getSum(int k)
      {
        T temp=0 ;
        for ( ; k>0 ; k-=(k&-k)) temp+=bit[k] ;
        return temp ;
      }
    T query(int l, int r) { return getSum(r)-getSum(l-1) ; }
  } ;

lli n, x, l=inf, r, m, ans, f1, f2 ;
vlli a, pre(100010) ;
BIT<lli, 200010> tree ;

bool check(lli x)
  {
    f1=0 ;
    f2=(n*(n+1)/4) ;
    tree.init() ;
    pre[0]=n+1 ;
    tree.update(n+1, 1) ;
    for(int i=1 ; i<=n ; i++)
      {
        pre[i]=pre[i-1] ;
        if(a[i]>=x) pre[i]++ ;
        else pre[i]-- ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        f1+=tree.getSum(pre[i]) ;
        tree.update(pre[i], 1) ;
      }
    return f1>=f2 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i], l=min(l, a[i]), r=max(r, a[i]) ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m)) l=m+1, ans=m ;
        else r=m-1 ;
      }
    cout<< ans ;
  }
