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

int n, m, x, y, a, b, cnt ;
int grid[110][110] ;
vector<tuple<int, int, int, int> > ans ;

int deg(int i, int j)
  {
    int res=0 ;
    if(i+1<=n && !grid[i+1][j]) res++ ;
    if(j+1<=m && !grid[i][j+1]) res++ ;
    if(i-1>=1 && !grid[i-1][j]) res++ ;
    if(j-1>=1 && !grid[i][j-1]) res++ ;
    return res ;
  }

bool fill()
  {
    int d, mx=5, p, q ;
    if(a+1<=n && !grid[a+1][b])
      {
        d=deg(a+1, b) ;
        if(d<mx) p=a+1, q=b, mx=d ;
      }
    if(b+1<=m && !grid[a][b+1])
      {
        d=deg(a, b+1) ;
        if(d<mx) p=a, q=b+1, mx=d ;
      }
    if(a-1>=1 && !grid[a-1][b])
      {
        d=deg(a-1, b) ;
        if(d<mx) p=a-1, q=b, mx=d ;
      }
    if(b-1>=1 && !grid[a][b-1])
      {
        d=deg(a, b-1) ;
        if(d<mx) p=a, q=b-1, mx=d ;
      }
    if(mx<5)
      {
        grid[a][b]=grid[p][q]=1 ;
        ans.pb(mt(a, b, p, q)) ;
        cnt-=2 ;
        return true ;
      }
    return false ;
  }

void find()
  {
    int mx=5, d ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(!grid[i][j])
          {
            d=deg(i, j) ;
            if(d<mx)
              {
                a=i ; b=j ;
                mx=d ;
              }
          }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> x >> y ;
    for(int i=1 ; i<=x ; i++) grid[1][i]=1, cnt-- ;
    for(int i=m-y+1 ; i<=m ; i++) grid[n][i]=1, cnt-- ;
    cnt+=n*m ;
    if(cnt%2)
      {
        cout<< "NO" ;
        return 0 ;
      }
    while(cnt>0)
      {
        find() ;
        if(!fill())
          {
            cout<< "NO" ;
            return 0 ;
          }
      }
    cout<< "YES" << endl << ans.size() << endl ;
    for(auto i:ans) cout<< get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << " " << get<3>(i) << endl ;
  }
