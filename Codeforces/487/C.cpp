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

void plant(char grid[100][100], char W, char B, int a, int b)
  {
    int x, y ;
    if(a<b) swap(a, b), swap(B, W) ;
    for(int i=1 ; i<=25 ; i++)
      for(int j=1 ; j<=50 ; j++)
        grid[i][j]=B ;
    x=2 ; y=1 ;
    while(a-1>0)
      {
        grid[x][y]=W ;
        if(y+2>50) x+=2, y=1 ;
        else y+=2 ;
        a-- ;
      }
    x+=2 ; y=1 ;
    for(int i=x ; i<=25 ; i++)
      for(int j=1 ; j<=50 ; j++)
        grid[i][j]=W ;
    x++ ;
    while(b-1>0)
      {
        grid[x][y]=B ;
        if(y+2>50) x+=2, y=1 ;
        else y+=2 ;
        b-- ;
      }
  }

void print(char grid[100][100])
  {
    for(int i=1 ; i<=25 ; i++, cout<< endl)
      for(int j=1 ; j<=50 ; j++)
        cout<< grid[i][j] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int a, b, c, d ;
    char grid1[100][100], grid2[100][100] ;
    cin>> a >> b >> c >> d ;
    plant(grid1, 'A', 'B', a, b) ;
    plant(grid2, 'C', 'D', c, d) ;
    cout<< 50 << " " << 50 << endl ;
    print(grid1) ;
    print(grid2) ;
  }
