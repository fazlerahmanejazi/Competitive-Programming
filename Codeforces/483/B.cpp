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
    int n, m, x, y ;
    cin>> n >> m ;
    char grid[200][200] ;
    for(int i=0 ; i<=110 ; i++)
      for(int j=0 ; j<=110 ; j++)
        grid[i][j]='.' ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> grid[i][j] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(grid[i][j]!='*')
          {
            if(grid[i][j]=='.') x=0 ;
            else x=grid[i][j]-'0' ;
            y=0 ;
            for(int k=i-1 ; k<=i+1 ; k++)
              for(int l=j-1 ; l<=j+1 ; l++)
                if((k!=i || l!=j) && grid[k][l]=='*') y++ ;
            if(x!=y)
              {
                cout<< "NO" ;
                return 0 ;
              }
          }
      cout<< "YES" ;
  }
