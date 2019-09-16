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
    int n, m, mat[55][55], check[55][55] ;
    memset(check, 0, sizeof check) ;
    vpii ans ;
    bool pos=true ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> mat[i][j] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(mat[i][j] && i+1<=n && j+1<=m && mat[i+1][j] && mat[i+1][j+1] && mat[i][j+1])
          {
            check[i][j]=1 ;
            check[i+1][j]=1 ;
            check[i][j+1]=1 ;
            check[i+1][j+1]=1 ;
            ans.pb(mp(i, j)) ;
          }
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(check[i][j]!=mat[i][j])
          pos=false ;
    if(pos)
      {
        cout<< ans.size() << endl ;
        for(auto i:ans) cout<< i.fi << " " << i.se << endl ;
      }
    else cout<< -1 ;
  }
