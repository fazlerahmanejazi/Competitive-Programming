#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n ;
    long long int z ;
    cin>> n ;
    vector<vector<int>> board(n+2, vector<int>(n+2)) ;
    vector<long long int> a(2*n+1, 0), b(2*n+1, 0), ans(2, 0), x(2), y(2) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        {
          cin>> z ;
          board[i][j]=z ;
          a[i+j]+=z ;
          b[i-j+n]+=z ;
        }
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        {
          z=a[i+j]+b[i-j+n]-board[i][j] ;
          if(ans[(i+j)%2]<=z)
            {
              ans[(i+j)%2]=z ;
              x[(i+j)%2]=i+1 ;
              y[(i+j)%2]=j+1 ;
            }
        }
    cout<< ans[0]+ans[1] << endl ;
    cout<< x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl ;
  }
