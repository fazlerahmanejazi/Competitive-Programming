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

template<class T, int SZ> struct fenwick
  {
    T bit[SZ+1] ;
    fenwick() { memset(bit, 0, sizeof bit) ; }
    void update(int k, T val)  { for( ; k<=SZ ; k+=(k&-k)) bit[k]+=val ; }
    T getSum(int k)
      {
        T temp=0 ;
        for ( ; k>0 ; k-=(k&-k)) temp+=bit[k] ;
        return temp ;
      }
    T query(int l, int r) { return getSum(r)-getSum(l-1) ; }
  } ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, T, idx, l, r, m, ans=0, cnt, sum, x ;
    cin>> n >> T ;
    fenwick<lli, 300000> tree[2] ;
    vlli a(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=n ; i++) tree[0].update(i, a[i]), tree[1].update(i, 1) ;
    while(tree[1].getSum(n)>0)
      {
        sum=tree[0].getSum(n) ;
        cnt=tree[1].getSum(n) ;
        x=T/sum ;
        ans+=x*cnt ;
        T%=sum ;
        l=1 ; r=idx=n ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            if(tree[0].getSum(m)>T) r=m-1, idx=min(idx, m) ;
            else l=m+1 ;
          }
        tree[0].update(idx, -a[idx]);
        tree[1].update(idx, -1) ;
      }
    cout<< ans ;
  }
