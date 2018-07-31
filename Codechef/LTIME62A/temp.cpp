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

int n, m, ans ;
string a[25][100010] ;
vector<string> temp ;
vector<vector<string>> adj ;

void solve(int idx)
  {
    if(idx>n)
      {
        if(temp.size()>1) adj.pb(temp) ;
        return ;
      }
    solve(idx+1) ;
    for(int i=1 ; i<=m ; i++)
      {
        temp.pb(a[idx][i]) ;
        solve(idx+1) ;
        temp.pop_back() ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> a[i][j] ;
    solve(1) ;
    sort(all(adj)) ;
    for(auto i:adj)
      {
        sort(all(i)) ;
        for(auto j:i) cout<< j << " " ;
        cout<< endl ;
      }
  }
