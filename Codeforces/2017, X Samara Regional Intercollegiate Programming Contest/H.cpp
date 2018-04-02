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

int n, m, a[1005][1005], b[1005][1005], mx, x, y, ansVal=inf, temp ;
pii MX, ans ;

int calc()
  {
    int mx=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        mx=max(mx, b[i][j]) ;
    return mx ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        {
          cin>> a[i][j] ;
          if(a[i][j]>mx) mx=a[i][j], MX=mp(i, j) ;
        }
    //
    x=MX.fi ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        b[i][j]=a[i][j] ;
    for(int i=0 ; i<m ; i++) b[x][i]=0 ;
    mx=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        if(b[i][j]>mx) mx=b[i][j], y=j ;
    for(int i=0 ; i<n ; i++) b[i][y]=0 ;
    temp=calc() ;
    if(ansVal>temp) ansVal=temp, ans=mp(x, y) ;
    //
    y=MX.se ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        b[i][j]=a[i][j] ;
    for(int i=0 ; i<n ; i++) b[i][y]=0 ;
    mx=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        if(b[i][j]>mx) mx=b[i][j], x=i ;
    for(int i=0 ; i<m ; i++) b[x][i]=0 ;
    temp=calc() ;
    if(ansVal>temp) ansVal=temp, ans=mp(x, y) ;
    cout<< ans.fi+1 << " " << ans.se+1 ;
  }
