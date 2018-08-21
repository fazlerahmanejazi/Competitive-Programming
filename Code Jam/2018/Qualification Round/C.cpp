#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
//#define endl '\n'
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

int T, A, x, y, X, Y, r ;
bool check, grid[1010][1010] ;

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> A ;
        memset(grid, false, sizeof grid) ;
        X=Y=2 ;
        while(1)
          {
            r=9 ;
            check=0 ;
            while(r)
              {
                cout<< X << " " << Y << endl ;
                cin>> x >> y ;
                if(!x && !y)
                  {
                    check=1 ;
                    break ;
                  }
                if(!grid[x][y])
                  {
                    grid[x][y]=1 ;
                    r-- ;
                  }
              }
            if(check) break ;
            if(Y+3<=900) Y+=3 ;
            else X+=3, Y=2 ;
          }
      }
  }
