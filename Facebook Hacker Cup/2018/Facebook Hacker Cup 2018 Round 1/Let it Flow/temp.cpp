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

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli n, x, prev, ans ;
        bool pos=true ;
        char grid[1010][1010] ;
        cin>> n ;
        for(int i=1 ; i<=3 ; i++)
          for(int j=1 ; j<=n ; j++)
            cin>> grid[i][j] ;
        if(n==1 || grid[1][1]=='#' || grid[2][1]=='#')
          {
            cout<< "Case #" << tc << ": " << 0 << endl ;
            continue ;
          }
        else ans=0, prev=0 ;
        for(int i=2 ; i<n ; i++)
          if(prev==-1)
            {
              if(grid[3][i]=='#' || grid[2][i]=='#')
                {
                  pos=false ;
                  break ;
                }
              prev=0 ;
            }
          else if(prev==1)
            {
              if(grid[1][i]=='#' || grid[2][i]=='#')
                {
                  pos=false ;
                  break ;
                }
              prev=0 ;
            }
          else if(!prev)
            {
              if(grid[2][i]=='#')
                {
                  pos=false ;
                  break ;
                }
              else if(grid[1][i]!='#' && grid[3][i]!='#')
                {
                  ans++ ;
                  prev=2 ;
                }
              else if(grid[1][i]!='#') prev=1 ;
              else if(grid[3][i]!='#') prev=-1 ;
              else
                {
                  pos=false ;
                  break ;
                }
            }
          else
            {
              if(grid[2][i]=='#')
                {
                  pos=false ;
                  break ;
                }
              else if(grid[1][i]!='#' && grid[3][i]!='#') prev=0 ;
              else if(grid[1][i]!='#' || grid[3][i]!='#') ans--, prev=0 ;
              else
                {
                  pos=false ;
                  break ;
                }
            }
          if(prev || (grid[3][n]=='#' || grid[2][n]=='#')) pos=false ;
          if(!pos) cout<< "Case #" << tc << ": " << 0 << endl ;
          else cout<< "Case #" << tc << ": " << fast_exp(2, ans) << endl ;
      }
  }
