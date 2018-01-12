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
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, m, ans=0, x, ones=0 ;
        char c ;
        cin>> n >> m ;
        int grid[n+1][m+1] ;
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<m ; j++)
            {
              cin>> c ;
              grid[i][j]=c-'0' ;
              if(grid[i][j]) ones++ ;
            }
        if(ones>=2*(n+m)-4)
          {
            for(int i=1 ; i<n-1 ; i++)
              {
                if(!grid[i][0]) ans++ ;
                if(!grid[i][m-1]) ans++ ;
              }
            for(int i=1 ; i<m-1 ; i++)
              {
                if(!grid[0][i]) ans++ ;
                if(!grid[n-1][i]) ans++ ;
              }
            if(!grid[0][0]) ans++ ;
            if(m>1 && !grid[0][m-1]) ans++ ;
            if(n>1 && !grid[n-1][0]) ans++ ;
            if(n>1 && m>1 && !grid[n-1][m-1]) ans++ ;
            cout<< ans << endl ;
          }
        else cout<< -1 << endl ;
      }
  }
