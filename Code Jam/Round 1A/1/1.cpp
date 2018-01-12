#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, r, c ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> r >> c ;
        vector<vector<char> > cake(r+1, vector<char>(c+1)) ;
        int cnt=0 ;
        for(int i=0 ; i<r ; i++)
          for(int j=0 ; j<c ; j++)
            {
              cin>> cake[i][j] ;
              if(cake[i][j]=='?') cnt++ ;
            }
        for(int i=0 ; i<r ; i++)
          {
            for(int j=0 ; j<c ; j++)
              {
                if(cake[i][j]!='?' )
                  {
                    char temp=cake[i][j] ;
                    for(int x=i-1 ; x>=0 ; x--)
                      if(cake[x][j]=='?') { cake[x][j]=temp ; cnt-- ; }
                      else break ;
                    for(int x=i+1 ; x<r ; x++)
                      if(cake[x][j]=='?') { cake[x][j]=temp ; cnt-- ; }
                      else break ;
                  }
                if(cnt<=0) break ;
              }
            if(cnt<=0) break ;
          }
        for(int i=0 ; i<r ; i++)
          {
            for(int j=0 ; j<c ; j++)
              {
                if(cake[i][j]!='?' )
                  {
                    char temp=cake[i][j] ;
                    for(int x=j-1 ; x>=0 ; x--)
                      if(cake[i][x]=='?') { cake[i][x]=temp ; cnt-- ; }
                      else break ;
                    for(int x=j+1 ; x<c ; x++)
                      if(cake[i][x]=='?') { cake[i][x]=temp ; cnt-- ; }
                      else break ;
                  }
                if(cnt<=0) break ;
              }
            if(cnt<=0) break ;
          }
        cout<< "Case #" << tc << ":" << endl ;
        for(int i=0 ; i<r ; i++)
          {
            for(int j=0 ; j<c ; j++)
              cout<< cake[i][j] ;
            cout<< endl ;
          }
      }
  }
