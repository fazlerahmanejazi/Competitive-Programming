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
    lli n, k, x, y, z, cnt, ans=INF, xx, yy, zz ;
    cin>> n >> k ;
    vector<tuple<lli, lli, lli>> a ;
    set<pair<lli, lli>> b ;
    for(int i=0 ; i<n ; i++) cin>> x >> y >> z, a.pb(mt(x, y, z)) ;
    sort(all(a)) ;
    for(int i=0 ; i<n ; i++)
      {
        tie(x, y, z)=a[i] ;
        b.insert(mp(y, z)) ;
        cnt=0 ;
        Tree<pair<lli, lli>> T ;
        if(b.size()>=k)
          for(auto j:b)
            {
              T.insert(mp(j.se, cnt++)) ;
              if(cnt>=k)
                {
                  tie(xx, yy, zz)=mt(x, j.fi, (*T.find_by_order(k-1)).fi) ;
                  ans=min(ans, xx+yy+zz) ;
                }
            }
      }
    cout<< ans ;
  }
