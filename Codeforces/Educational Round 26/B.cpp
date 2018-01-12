#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    int n, m, c=1 ;
    cin>> n >> m ;
    char flag[n+1][m+1] ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        cin>> flag[i][j] ;
    int lines[n+1] ;
    bool horiz=true ;
    for(int i=0 ; i<n ; i++)
      {
        char x=flag[i][0] ;
        for(int j=1 ; j<m ; j++)
          if(flag[i][j]!=x)
            horiz=false ;
      }
    if(horiz)
      {
        char x=flag[0][0] ;
        int a=1, b=0, c=0, i ;
        for(i=1 ; i<n ; i++)
          if(flag[i][0]!=x) break ;
          else a++ ;
        if(i<n)
          {
            b=1 ;
            x=flag[i][0] ;
            i++ ;
            for( ; i<n ; i++)
              if(flag[i][0]!=x) break ;
              else b++ ;
          }
        if(i<n)
          {
            c=1 ;
            x=flag[i][0] ;
            i++ ;
            for( ; i<n ; i++)
              if(flag[i][0]!=x) break ;
              else c++ ;
          }
        if(a==b && b==c && i==n)
          {
            cout<< "YES" ;
            return 0 ;
          }
      }
    bool vert=true ;
    for(int i=0 ; i<m ; i++)
      {
        char x=flag[0][i] ;
        for(int j=1 ; j<n ; j++)
          if(flag[j][i]!=x)
            vert=false ;
      }
    if(vert)
      {
        char x=flag[0][0] ;
        int a=1, b=0, c=0, i ;
        for(i=1 ; i<m ; i++)
          if(flag[0][i]!=x) break ;
          else a++ ;
        if(i<m)
          {
            b=1 ;
            x=flag[0][i] ;
            i++ ;
            for( ; i<m ; i++)
              if(flag[0][i]!=x) break ;
              else b++ ;
          }
        if(i<m)
          {
            c=1 ;
            x=flag[0][i] ;
            i++ ;
            for( ; i<m ; i++)
              if(flag[0][i]!=x) break ;
              else c++ ;
          }
        if(a==b && b==c && i==m)
          {
            cout<< "YES" ;
            return 0 ;
          }
      }
    cout<< "NO" ;
  }
