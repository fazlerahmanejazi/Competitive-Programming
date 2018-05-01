#include <bits/stdc++.h>
using namespace std ;

int T, h, w ;
char labyrinth[30][30] ;
bool visit[30][30] ;

int dfs(int x, int y)
  {
    int count=0 ;
    visit[x][y]=true ;
    if(x+1<=h && labyrinth[x+1][y]=='.' && !visit[x+1][y])
      {
        count+=dfs(x+1, y) ;
      }
    if(x-1>=1 && labyrinth[x-1][y]=='.' && !visit[x-1][y])
      {
        count+=dfs(x-1, y) ;
      }
    if(y+1<=w && labyrinth[x][y+1]=='.' && !visit[x][y+1])
      {
        count+=dfs(x, y+1) ;
      }
    if(y-1>=1 && labyrinth[x][y-1]=='.' && !visit[x][y-1])
      {
        count+=dfs(x, y-1) ;
      }
    if(count==0) return 1 ;
    else return count ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> h >> w ;
        memset(visit, false, sizeof visit) ;
        for(int i=1 ; i<=h ; i++)
          {
            for(int j=1 ; j<=w ; j++)
              {
                cin>> labyrinth[i][j] ;
              }
          }
        cout<< "Case #" << tc << ": " << dfs(2, 2) << endl ;
      }
  }
