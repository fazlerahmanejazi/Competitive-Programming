#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

template<class T> using Tree=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli n, x, ans=0 ;
        vlli a ;
        Tree<pair<lli, lli>> T ;
        cin>> n ;
        for(int i=0 ; i<n ; i++) cin>> x, a.pb(x) ;
        T.insert(mp(2*a[0], 0)) ;
        for(int i=1 ; i<n ; i++)
          {
            x=T.order_of_key(mp(a[i]+1, -INF)) ;
            ans+=x ;
            T.insert(mp(2*a[i], i)) ;
          }
        cout<< ans << endl ;
      }
  }
