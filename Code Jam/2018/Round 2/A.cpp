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

char grid[150][150] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int n, m, x, curr, y, z, ans=1 ;
        bool pos=true ;
        cin>> m ;
        vi a(m+1) ;
        vb taken(m+1, false) ;
        vvi adj(m+1) ;
        for(int i=1 ; i<=m ; i++) cin>> a[i] ;
        for(int i=0 ; i<=110 ; i++) for(int j=0 ; j<=110 ; j++) grid[i][j]='.' ;
        a[1]-- ; a[m]-- ;
        for(int i=1 ; i<=m ; i++)
          {
            for(int j=2 ; j<m && a[i]>0 ; j++)
              if(!taken[j])
                {
                  taken[j]=true ;
                  adj[i].pb(j) ;
                  a[i]-- ;
                }
            if(a[i]!=0) pos=false ;
          }
        for(int i=1 ; i<=m ; i++)
          for(auto j:adj[i])
            if(j==i) continue ;
            else if(j<i)
              {
                x=1 ; y=j ;
                while(y<i) grid[x++][y++]=92 ;
                ans=max(ans, x) ;
              }
            else
              {
                x=1 ; y=j ;
                while(y>i) grid[x++][y--]=47 ;
                ans=max(ans, x) ;
              }
        if(!pos) cout<< "Case #" << tc << ": IMPOSSIBLE" << endl ;
        else
          {
            cout<< "Case #" << tc << ": " << ans << endl ;
            for(int i=1 ; i<=ans ; i++)
              {
                for(int j=1 ; j<=m ; j++) cout<< grid[i][j] ;
                cout<< endl ;
              }
          }
      }
  }
