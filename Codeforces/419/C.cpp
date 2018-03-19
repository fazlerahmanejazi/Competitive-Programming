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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m ;
    cin>> n >> m ;
    vi row(n), col(m) ;
    vvi grid(n, vi(m)), level(n, vi(m)) ;
    vpii ans1, ans2, ans ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> grid[i][j] ;
          level[i][j]=grid[i][j] ;
        }
    for(int i=0 ; i<n ; i++)
      {
        int x=inf ;
        for(int j=0 ; j<m ; j++)
          x=min(x, grid[i][j]) ;
        row[i]=x ;
      }
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<m ; j++)
          grid[i][j]-=row[i] ;
        for(int j=0 ; j<row[i] ; j++)
          ans1.pb(mp(0, i+1)) ;
      }
    for(int i=0 ; i<m ; i++)
      {
        int x=inf ;
        for(int j=0 ; j<n ; j++)
          x=min(x, grid[j][i]) ;
        col[i]=x ;
      }
    for(int i=0 ; i<m ; i++)
      {
        for(int j=0 ; j<n ; j++)
          grid[j][i]-=col[i] ;
        for(int j=0 ; j<col[i] ; j++)
          ans1.pb(mp(1, i+1)) ;
      }
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        if(grid[i][j]!=0)
          {
            cout<< -1 ;
            return 0 ;
          }
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        grid[i][j]=level[i][j] ;
    for(int i=0 ; i<m ; i++)
      {
        int x=inf ;
        for(int j=0 ; j<n ; j++)
          x=min(x, grid[j][i]) ;
        col[i]=x ;
      }
    for(int i=0 ; i<m ; i++)
      {
        for(int j=0 ; j<n ; j++)
          grid[j][i]-=col[i] ;
        for(int j=0 ; j<col[i] ; j++)
          ans2.pb(mp(1, i+1)) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        int x=inf ;
        for(int j=0 ; j<m ; j++)
          x=min(x, grid[i][j]) ;
        row[i]=x ;
      }
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<m ; j++)
          grid[i][j]-=row[i] ;
        for(int j=0 ; j<row[i] ; j++)
          ans2.pb(mp(0, i+1)) ;
      }
    if(ans1.size()<ans2.size()) ans=ans1 ;
    else ans=ans2 ;
    cout<< ans.size() << endl ;
    for(int i=0 ; i<ans.size() ; i++)
      if(ans[i].fi==0) cout<< "row " << ans[i].se << endl ;
      else cout<< "col " << ans[i].se << endl ;
  }
