#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int curr[505][505], n, m, h, cnt ;

bool check()
  {
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(curr[i][j]!=h)
          return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, prev[505][505] ;
    cin>> T ;
    while(T--)
      {
        h=-inf ;
        cnt=0 ;
        memset(prev, 0, sizeof prev) ;
        cin>> n >> m ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=m ; j++)
            {
              cin>> prev[i][j] ;
              curr[i][j]=prev[i][j] ;
              h=max(curr[i][j], h) ;
            }
        while(1)
          {
            if(check()) break ;
            for(int i=1 ; i<=n ; i++)
              for(int j=1 ; j<=m ; j++)
                if(prev[i][j]==h)
                  {
                    curr[i][j-1]=h ; curr[i][j+1]=h ;
                    curr[i+1][j-1]=h ; curr[i+1][j+1]=h ; curr[i+1][j]=h ;
                    curr[i-1][j-1]=h ; curr[i-1][j+1]=h ; curr[i-1][j]=h ;
                  }
            for(int i=1 ; i<=n ; i++)
              for(int j=1 ; j<=m ; j++)
                prev[i][j]=curr[i][j] ;
            cnt++ ;
          }
        cout<< cnt << endl ;
      }
  }
