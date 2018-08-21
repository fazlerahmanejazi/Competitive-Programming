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
    int n, q, c, x1, y1, x2, y2, s, t, x, y, res ;
    cin>> n >> q >> c ;
    int sky[11][111][111], ans[11][111][111] ;
    vector<tuple<int, int, int>> stars ;
    for(int k=0 ; k<=10 ; k++)
      for(int i=0 ; i<=100 ; i++)
        for(int j=0 ; j<=100 ; j++)
          {
            sky[k][i][j]=0 ;
            ans[k][i][j]=0 ;
          }
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y >> s ;
        stars.pb(mt(x, y, s)) ;
      }
    for(int k=0 ; k<=10 ; k++)
      {
        for(int i=0 ; i<n ; i++)
          {
            tie(x, y, s)=stars[i] ;
            sky[k][y][x]+=s ;
            s++ ;
            if(s>c) s=0 ;
            stars[i]=mt(x, y, s) ;
          }
        for(int i=1 ; i<=100 ; i++)
          for(int j=1 ; j<=100 ; j++)
            ans[k][i][j]=sky[k][i][j]+ans[k][i-1][j]+ans[k][i][j-1]-ans[k][i-1][j-1] ;

      }
    for(int i=0 ; i<q ; i++)
      {
        cin>> t >> x1 >> y1 >> x2 >> y2 ;
        t=t%(c+1) ;
        res=ans[t][y2][x2]-ans[t][y1-1][x2]-ans[t][y2][x1-1]+ans[t][y1-1][x1-1] ;
        cout<< res << endl ;
      }
  }
