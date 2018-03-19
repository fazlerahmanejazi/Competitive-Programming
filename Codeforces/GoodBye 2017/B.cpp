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

int n, m, l, ans ;
pii start ;
bool reach, pos ;
vi D(4) ;
string s ;
char grid[101][101] ;

pii dir(int d)
  {
    if(D[d]==0) return mp(1, 0) ;
    else if(D[d]==1) return mp(0, 1) ;
    else if(D[d]==2) return mp(-1, 0) ;
    else if(D[d]==3) return mp(0, -1) ;
  }

void travel(int x, int y, int i)
  {
    if(grid[x][y]=='E')
      {
        reach=true ;
        return ;
      }
    if(i==l) return ;
    int d=s[i]-'0', dx, dy ;
    tie(dx, dy)=dir(d) ;
    if(x+dx<1 || x+dx>n || y+dy<1 || y+dy>m)
      {
        pos=false ;
        return ;
      }
    if(grid[x+dx][y+dy]!='#') travel(x+dx, y+dy, i+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        {
          cin>> grid[i][j] ;
          if(grid[i][j]=='S') start=mp(i, j) ;
        }
    cin>> s ;
    l=s.length() ;
    for(int i=0 ; i<4 ; i++) D[i]=i ;
    do
      {
        pos=true ;
        reach=false ;
        travel(start.fi, start.se, 0) ;
        if(reach && pos) ans++ ;
      } while(next_permutation(all(D))) ;
    cout<< ans ;
  }
