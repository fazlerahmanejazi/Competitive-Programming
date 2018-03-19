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

vi tree(100005, 0), ans(100005) ;

int sum(int i)
  {
    int temp=0 ;
    for( ; i>=0 ; i=(i&(i+1))-1)
      temp+=tree[i] ;
    return temp ;
  }

void update(int i, int val)
  {
    for( ; i<100005 ; i=(i|(i+1)))
      tree[i]+=val ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, x, y ;
    cin>> n ;
    vpii point ;
    vector<pair<double, int>> slope ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        point.pb(mp(x, y)) ;
        slope.pb(mp((1.0*y)/x, i)) ;
      }
    sort(all(slope)) ;
    for(auto i:slope)
      {
        tie(x, y)=point[i.se] ;
        ans[i.se]=sum(x) ;
        update(x, 1) ;
      }
    for(int i=0 ; i<n ; i++) cout<< ans[i] << endl ;
  }
