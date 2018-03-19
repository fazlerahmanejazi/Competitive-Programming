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

lli n, m, q, p, r, c, ans, val ;
char grid[300][300] ;
lli noise[300][300] ;
bool visit[300][300] ;

void solve(int r, int c, lli temp)
  {
    lli x, y, val ;
    memset(visit, false, sizeof visit) ;
    queue<tuple<int, int, lli>> qq ;
    qq.push(mt(r, c, temp)) ;
    while(!qq.empty())
      {
        tie(x, y, val)=qq.front () ; qq.pop() ;
        if(x<0 || x>=n || y<0 || y>=m || val<=0 || grid[x][y]=='*' || visit[x][y]) continue ;
        noise[x][y]+=val ;
        visit[x][y]=true ;
        qq.push(mt(x+1, y, val/2)) ;
        qq.push(mt(x-1, y, val/2)) ;
        qq.push(mt(x, y+1, val/2)) ;
        qq.push(mt(x, y-1, val/2)) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> q >> p ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        cin>> grid[i][j] ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        if(grid[i][j]!='.' && grid[i][j]!='*')
          solve(i, j, (grid[i][j]-'A'+1)*q) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        if(noise[i][j]>p)
          ans++ ;
    cout<< ans ;
  }
