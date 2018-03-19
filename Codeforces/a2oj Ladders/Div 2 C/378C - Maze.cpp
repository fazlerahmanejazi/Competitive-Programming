#include <bits/stdc++.h>
using namespace std ;

int n, m, x, y, k, z, c ;
char grid[510][510] ;

void dfs(int i, int j)
  {
    if(c<z)
      {
        grid[i][j]='$' ;
        c++ ;
      }
    if(i+1<n && grid[i+1][j]=='.' && c<z) dfs(i+1, j) ;
    if(j+1<m && grid[i][j+1]=='.' && c<z) dfs(i, j+1) ;
    if(i-1>=0 && grid[i-1][j]=='.' && c<z) dfs(i-1, j) ;
    if(j-1>=0 && grid[i][j-1]=='.' && c<z) dfs(i, j-1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    cin>> n >> m >> k ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> grid[i][j] ;
          if(grid[i][j]=='.')
            {
              z++ ;
              x=i ;
              y=j ;
            }
        }
    z=z-k ;
    dfs(x, y) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        if(grid[i][j]=='.') grid[i][j]='X' ;
        else if(grid[i][j]=='$') grid[i][j]='.' ;
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<m ; j++)
          cout<< grid[i][j] ;
        cout<< endl ;
      }
  }
