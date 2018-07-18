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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, d, x ;
    vlli a ;
    cin>> n >> d ;
    set<lli> cnt ;
    for(int i=0 ; i<n ; i++) cin>> x, cnt.insert(x-d), cnt.insert(x+d), a.pb(x) ;
    for(auto i:cnt)
      for(int j=0 ; j<n ; j++)
        if(abs(i-a[j])<d)
          cnt.erase(i) ;
    cout<< cnt.size() ;
  }
