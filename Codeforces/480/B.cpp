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
    int n, k ;
    cin>> n >> k ;
    char grid[4][200] ;
    for(int i=0 ; i<4 ; i++)
      for(int j=0 ; j<n ; j++)
        grid[i][j]='.' ;
    if(k>=1)
      {
        grid[1][n/2]='#' ;
        if((k%2)==0)
          {
            grid[2][n/2]='#' ;
            k-- ;
          }
        k-- ;
        for(int i=0 ; i<k/2 ; i++)
          {
            grid[(i%2)+1][i/2+1]='#' ;
            grid[(i%2)+1][n-1-(i/2+1)]='#' ;
          }
      }
    cout<< "YES" << endl ;
    for(int i=0 ; i<4 ; i++)
      {
        for(int j=0 ; j<n ; j++) cout<< grid[i][j] ;
        cout<< endl ;
      }
  }
