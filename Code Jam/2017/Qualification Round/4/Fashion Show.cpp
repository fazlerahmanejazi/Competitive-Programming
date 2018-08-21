#include <bits/stdc++.h>
using namespace std ;

struct triplet
  {
    char one ;
    int two ;
    int three ;
  } ;
triplet temp ;

int T, n, m, r, c, sum, cnt ;
char ch ;
char grid[101][101] ;
vector<triplet> ans ;

bool place(int x, int y, char z)
  {
    if(z=='o' || z=='x')
      {
        for(int i=0 ; i<n ; i++)
          {
            if(i==y) continue ;
            if(grid[x][i]!='.' && grid[x][i]!='+') return false ;
          }
        for(int i=0 ; i<n ; i++)
          {
            if(i==x) continue ;
            if(grid[i][y]!='.' && grid[i][y]!='+') return false ;
          }
      }
    if(z=='o' || z=='+')
      {
        int i=x+1 ; int j=y+1 ;
        while(i<n && j<n)
          {
            if(grid[i][j]!='.' && grid[i][j]!='x') return false ;
            i++ ; j++ ;
          }
        i=x+1 ; j=y-1 ;
        while(i<n && j>=0)
          {
            if(grid[i][j]!='.' && grid[i][j]!='x') return false ;
            i++ ; j-- ;
          }
        i=x-1 ; j=y-1 ;
        while(i>=0 && j>=0)
          {
            if(grid[i][j]!='.' && grid[i][j]!='x') return false ;
            i-- ; j-- ;
          }
        i=x-1 ; j=y+1 ;
        while(i>=0 && j<n)
          {
            if(grid[i][j]!='.' && grid[i][j]!='x') return false ;
            i-- ; j++ ;
          }
      }
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> m ;
        ans.clear() ;
        sum=cnt=0 ;
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            grid[i][j]='.' ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> ch >> r >> c ;
            grid[r-1][c-1]=ch ;
            if(ch=='o') sum+=2 ;
            else sum++ ;
          }
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            {
              if(grid[i][j]=='.')
                {
                  if(place(i, j, 'o'))
                    {
                      grid[i][j]='o' ;
                      cnt++ ;
                      sum+=2 ;
                      temp.one='o' ; temp.two=i+1 ; temp.three=j+1 ;
                      ans.push_back(temp) ;
                    }
                  else if(place(i, j, 'x'))
                    {
                      grid[i][j]='x' ;
                      cnt++ ;
                      sum++ ;
                      temp.one='x' ; temp.two=i+1 ; temp.three=j+1 ;
                      ans.push_back(temp) ;
                    }
                  else if(place(i, j, '+'))
                    {
                      grid[i][j]='+' ;
                      cnt++ ;
                      sum++ ;
                      temp.one='+' ; temp.two=i+1 ; temp.three=j+1 ;
                      ans.push_back(temp) ;
                    }
                }
            }
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            {
              if(grid[i][j]!='.' && grid[i][j]!='o')
                {
                  if(place(i, j, 'o'))
                    {
                      grid[i][j]='o' ;
                      cnt++ ;
                      sum++ ;
                      temp.one='o' ; temp.two=i+1 ; temp.three=j+1 ;
                      ans.push_back(temp) ;
                    }
                }
            }
        /*for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            if(grid[i][j]=='o')
              sum+=2 ;
            else if(grid[i][j]!='.')
              sum++ ;*/
        cout<< "Case #" << tc << ": " << sum << " " << cnt << endl ;
        for(int i=0 ; i<ans.size() ; i++)
          cout<< ans[i].one << " " << ans[i].two << " " << ans[i].three << endl ;
      }
  }
