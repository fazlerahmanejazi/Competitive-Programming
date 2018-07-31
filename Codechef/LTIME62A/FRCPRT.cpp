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

int n, m, l, L, U, D, R, grid[110][110] ;
char c ;
string s ;

void perform(char c)
  {
    if(c=='L')
      for(int i=1 ; i<=n ; i++)
        {
          int cnt=0 ;
          for(int j=1 ; j<=m ; j++) cnt+=grid[i][j] ;
          for(int j=1 ; j<=m ; j++)
            if(j<=cnt) grid[i][j]=1 ;
            else grid[i][j]=0 ;
        }
    else if(c=='R')
      for(int i=1 ; i<=n ; i++)
        {
          int cnt=0 ;
          for(int j=1 ; j<=m ; j++) cnt+=grid[i][j] ;
          for(int j=1 ; j<=m ; j++)
            if(j<=cnt) grid[i][m-j+1]=1 ;
            else grid[i][m-j+1]=0 ;
        }
    else if(c=='U')
      for(int j=1 ; j<=m ; j++)
        {
          int cnt=0 ;
          for(int i=1 ; i<=n ; i++) cnt+=grid[i][j] ;
          for(int i=1 ; i<=n ; i++)
            if(i<=cnt) grid[i][j]=1 ;
            else grid[i][j]=0 ;
        }
    else
      for(int j=1 ; j<=m ; j++)
        {
          int cnt=0 ;
          for(int i=1 ; i<=n ; i++) cnt+=grid[i][j] ;
          for(int i=1 ; i<=n ; i++)
            if(i<=cnt) grid[n-i+1][j]=1 ;
            else grid[n-i+1][j]=0 ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m ;
        for(int i=1 ; i<=n ; i++) for(int j=1 ; j<=m ; j++) cin>> c, grid[i][j]=c-'0' ;
        cin>> s ;
        l=s.length() ;
        s='#'+s ;
        map<char, int> posMax, posMin ;
        set<pair<int, char>> idx ;
        for(int i=1 ; i<=l ; i++)
          {
            posMax[s[i]]=max(posMax[s[i]], i) ;
            if(posMin[s[i]]) posMin[s[i]]=min(posMin[s[i]], i) ;
            else posMin[s[i]]=i ;
          }
        for(auto i:posMax) idx.insert(mp(i.se, i.fi)) ;
        for(auto i:posMin) idx.insert(mp(i.se, i.fi)) ;
        for(auto i:idx) perform(i.se) ;
        for(int i=1 ; i<=n ; i++)
          {
            for(int j=1 ; j<=m ; j++) cout<< grid[i][j] ;
            cout<< endl ;
          }
      }
  }
