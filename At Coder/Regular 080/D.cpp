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
    int n, m, N, i, j, c ;
    bool dir=true ;
    cin>> n >> m ;
    cin>> N ;
    int grid[n+1][m+1]={0} ;
    vi a(N) ;
    for(int i=0 ; i<N ; i++)
      cin>> a[i] ;
    i=0 ; j=0 ; c=0 ;
    while(i<n)
      {
        if(dir)
          {
            if(a[c])
              {
                while(a[c])
                  {
                    grid[i][j]=c+1 ;
                    a[c]-- ;
                    if(j+1<m) j++ ;
                    else
                      {
                        i++ ;
                        j=m-1 ;
                        dir=false ;
                        break ;
                      }
                  }
              }
            else c++ ;
          }
        else
          {
            if(a[c])
              {
                while(a[c])
                  {
                    grid[i][j]=c+1 ;
                    a[c]-- ;
                    if(j-1>=0) j-- ;
                    else
                      {
                        i++ ;
                        j=0 ;
                        dir=true ;
                        break ;
                      }
                  }
              }
            else c++ ;
          }
      }
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<m ; j++)
          cout<< grid[i][j] << " " ;
        cout<< endl ;
      }
  }
