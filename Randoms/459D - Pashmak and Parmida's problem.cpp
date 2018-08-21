#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, x, pos ;
lli ans ;
vpii L, R ;
vi tree, res, a ;
unordered_map<int, int> cnt ;

lli sum(int i)
  {
    lli temp=0 ;
    for( ; i>=0 ; i=(i&(i+1))-1)
      temp+=tree[i] ;
    return temp ;
  }

void update(int i, int val)
  {
    for( ; i<n ; i=(i|(i+1)))
      tree[i]+=val ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    tree.assign(n, 0) ;
    L.resize(n) ; R.resize(n) ; a.resize(n) ;
    cnt.clear() ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        cnt[a[i]]++ ;
        L[i].fi=cnt[a[i]] ;
        L[i].se=i ;
      }
    cnt.clear() ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        cnt[a[i]]++ ;
        R[i].fi=cnt[a[i]] ;
        R[i].se=i ;
      }
    R[0].fi=-inf ;
    sort(all(L)) ; reverse(all(L)) ;
    sort(all(R)) ; reverse(all(R)) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        while(pos<n && L[pos].fi>R[i].fi)
          update(L[pos++].se, 1) ;
        ans+=sum(R[i].se-1) ;
      }
    cout<< ans ;

  }
