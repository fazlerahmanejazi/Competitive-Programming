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

template<class T, int SZ> struct BIT
  {
    T bit[SZ+1] ;
    BIT() { memset(bit, 0, sizeof bit) ; }
    void update(int k, T val)  { for( ; k<=SZ ; k+=(k&-k)) bit[k]+=val ; }
    T getSum(int k)
      {
        T temp=0 ;
        for ( ; k>0 ; k-=(k&-k)) temp+=bit[k] ;
        return temp ;
      }
    T query(int l, int r) { return getSum(r)-getSum(l-1) ; }
  } ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, z, x, y ;
    set<pair<int, int>> stars ;
    vector<tuple<int, int, int>> ans ;
    char c ;
    cin>> n >> m ;
    int grid[n+1][m+1], r[n+1][m+1], l[n+1][m+1], u[n+1][m+1], d[n+1][m+1] ;
    BIT<int, 1001> h[n+1] ;
    BIT<int, 1001> v[m+1] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        {
          cin>> c ;
          if(c=='.') grid[i][j]=0 ;
          else grid[i][j]=1 ;
        }
    for(int i=1 ; i<=n ; i++)
      {
        l[i][1]=grid[i][1] ;
        for(int j=2 ; j<=m ; j++)
          if(grid[i][j]) l[i][j]=1+l[i][j-1] ;
          else l[i][j]=0 ;
        r[i][m]=grid[i][m] ;
        for(int j=m-1 ; j>=1 ; j--)
          if(grid[i][j]) r[i][j]=1+r[i][j+1] ;
          else r[i][j]=0 ;
      }
    for(int i=1 ; i<=m ; i++)
      {
        u[1][i]=grid[1][i] ;
        for(int j=2 ; j<=n ; j++)
          if(grid[j][i]) u[j][i]=1+u[j-1][i] ;
          else u[j][i]=0 ;
        d[n][i]=grid[n][i] ;
        for(int j=n-1 ; j>=1 ; j--)
          if(grid[j][i]) d[j][i]=1+d[j+1][i] ;
          else d[j][i]=0 ;
      }
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(grid[i][j])
          {
            z=min({l[i][j], r[i][j], d[i][j], u[i][j]}) ;
            if(z!=1) h[i].update(j-z+1, 1), h[i].update(j+z, -1), v[j].update(i-z+1, 1), v[j].update(i+z, -1), ans.pb(mt(i, j, z-1)) ;
          }
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(grid[i][j])
          if(h[i].getSum(j)<=0 && v[j].getSum(i)<=0)
            {
              cout<< -1 ;
              return 0 ;
            }
    cout<< ans.size() << endl ;
    for(auto i:ans)
      {
        tie(x, y, z)=i ;
        cout<< x << " " << y << " " << z << endl ;
      }
  }
