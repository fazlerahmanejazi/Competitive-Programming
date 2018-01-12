#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, x, ans ;
vi a, b ;
vpii q ;
vlli tree ;

int sum(int i)
  {
    int temp=0 ;
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
    a.clear() ; b.clear() ; tree.clear() ;
    tree.assign(n, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.pb(x) ; b.pb(x) ;
      }
    sort(all(b)) ;
    for(int i=0 ; i<n ; i++)
      {
        x=lower_bound(all(b), a[i])-b.begin() ;
        q.pb(mp(x, i)) ;
      }
    sort(all(q)) ; reverse(all(q)) ;
    for(int i=0 ; i<n ; i++)
      {
        ans=max(ans, sum(q[i].se)) ;
        update(q[i].fi, 1) ;
      }
    cout<< ans+1 << endl ;
  }
