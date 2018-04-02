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

int n, T, a, b, c ;
map<int, int> cnv ;
set<int> temp ;
vector<tuple<int, int, int>> data ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a >> b >> c ;
        temp.insert(a) ; temp.insert(b) ;
        data.pb(mt(a, b, c)) ;
      }
    for(auto i:temp) cnv[i]=++T ;
