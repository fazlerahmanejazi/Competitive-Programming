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
    void update(int k, T val)  { for( ; k<=SZ ; k+=(k&-k)) bit[k]+=val ; }
    T getSum(int k)
      {
        T temp=0 ;
        for ( ; k>0 ; k-=(k&-k)) temp+=bit[k] ;
        return temp ;
      }
    T query(int l, int r) { return getSum(r)-getSum(l-1) ; }
  } ;

lli n, k, x, ans, inv, l, r ;
vlli a, b ;
BIT<lli, 100010> tree ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    if(!k) return cout<< n*(n+1)/2, 0 ;
    a.resize(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i], a[i]++ ;
    b=a ;
    sort(all(b)) ;
    for(int i=0 ; i<n ; i++) a[i]=lower_bound(all(b), a[i])-b.begin()+1 ;
    tree.update(a[0], 1) ;
    while(l<n)
      {
        while(inv<k && r+1<n)
          {
            r++ ;
            inv+=tree.query(a[r]+1, 100001) ;
            tree.update(a[r], 1) ;
          }
        if(inv<k) break ;
        ans+=n-r ;
        tree.update(a[l], -1) ;
        inv-=tree.getSum(a[l]-1) ;
        l++ ;
      }
    cout<< ans ;
  }
