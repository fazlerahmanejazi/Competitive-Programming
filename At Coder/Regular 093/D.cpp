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
    int a, b, x, y ;
    char B='#', W='.' ;
    cin>> a >> b ;
    if(a<b) swap(a, b), swap(B, W) ;
    char grid[105][105] ;
    for(int i=1 ; i<=100 ; i++)
      for(int j=1 ; j<=100 ; j++)
        grid[i][j]=B ;
    x=2 ; y=1 ;
    while(a-1>0)
      {
        grid[x][y]=W ;
        if(y+2>100) x+=2, y=1 ;
        else y+=2 ;
        a-- ;
      }
    x+=2 ; y=1 ;
    for(int i=x ; i<=100 ; i++)
      for(int j=1 ; j<=100 ; j++)
        grid[i][j]=W ;
    x++ ;
    while(b-1>0)
      {
        grid[x][y]=B ;
        if(y+2>100) x+=2, y=1 ;
        else y+=2 ;
        b-- ;
      }
    cout<< 100 << " " << 100 << endl ;
    for(int i=1 ; i<=100 ; i++, cout<< endl)
      for(int j=1 ; j<=100 ; j++)
        cout<< grid[i][j] ;
  }
