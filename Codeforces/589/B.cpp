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
    lli h, w, x, grid[1010][1010], check[1010][1010], ans=1, p=0, r[1010], c[1010] ;
    memset(grid, 0, sizeof grid) ;
    memset(check, 0, sizeof check) ;
    cin>> h >> w ;
    for(int i=1 ; i<=h ; i++)
      {
        cin>> x ;
        r[i]=x ;
        for(int j=1 ; j<=x ; j++) grid[i][j]=check[i][j]=1 ;
        grid[i][x+1]=1 ;
      }
    for(int j=1 ; j<=w ; j++)
      {
        cin>> x ;
        c[j]=x ;
        for(int i=1 ; i<=x ; i++) grid[i][j]=check[i][j]=1 ;
        grid[x+1][j]=1 ;
      }
    for(int i=1 ; i<=h ; i++)
      for(int j=1 ; j<=w ; j++)
        if(!grid[i][j])
          p++ ;
    for(int i=1 ; i<=p ; i++) ans=(ans*2)%mod ;
    for(int i=1 ; i<=h ; i++)
      for(int j=1 ; j<=w ; j++)
        if(check[i][j])
          {
            if(r[i]+1==j && c[j]>=i) ans=0 ;
            if(c[j]+1==i && r[i]>=j) ans=0 ;
          }
    cout<< ans ;
  }
