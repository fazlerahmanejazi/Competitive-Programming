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
    int n, diff, x ;
    lli ans=2*INF, curr=0, maxm=0 ;
    cin>> n ;
    int grid[n+1][n+1], orig[n+1][n+1], res[n+1][n+1] ;
    lli sum[n+1] ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        {
          cin>> grid[i][j] ;
          orig[i][j]=grid[i][j] ;
        }
      // 1
      maxm=0 ;
    for(int k=0 ; k<n ; k++)
      {
        sum[k]=0 ;
        for(int i=k ; i<n ; i++)
          {
            x=max(grid[k][i], grid[i][k]) ;
            grid[k][i]=grid[i][k]=x ;
          }
        for(int i=0 ; i<n ; i++)
          sum[k]+=grid[k][i] ;
        maxm=max(maxm, sum[k]) ;
      }
    for(int i=0 ; i<n ; i++)
      if(sum[i]<maxm)
        grid[i][i]+=maxm-sum[i] ;
    curr=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        curr+=grid[i][j]-orig[i][j] ;
    if(curr<ans)
      {
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            res[i][j]=grid[i][j] ;
        ans=curr ;
      }

      // 2
      maxm=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        grid[i][j]=orig[i][j] ;
    for(int k=0 ; k<n ; k++)
      {
        sum[n-k-1]=0 ;
        for(int i=k ; i<n ; i++)
          {
            x=max(grid[n-k-1][i], grid[n-i-1][k]) ;
            grid[n-k-1][i]=grid[n-i-1][k]=x ;
          }
        for(int i=0 ; i<n ; i++)
          sum[n-k-1]+=grid[n-k-1][i] ;
        maxm=max(maxm, sum[n-k-1]) ;
      }
    for(int i=0 ; i<n ; i++)
      if(sum[n-i-1]<maxm)
        grid[n-i-1][i]+=maxm-sum[n-i-1] ;
    curr=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        curr+=grid[i][j]-orig[i][j] ;
    if(curr<ans)
      {
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            res[i][j]=grid[i][j] ;
        ans=curr ;
      }

      // 3
      maxm=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        grid[i][j]=orig[i][j] ;
    for(int k=0 ; k<n ; k++)
      {
        sum[n-k-1]=0 ;
        for(int i=k ; i<n ; i++)
          {
            x=max(grid[n-k-1][n-i-1], grid[n-i-1][n-k-1]) ;
            grid[n-k-1][n-i-1]=grid[n-i-1][n-k-1]=x ;
          }
        for(int i=0 ; i<n ; i++)
          sum[n-k-1]+=grid[n-k-1][i] ;
        maxm=max(maxm, sum[n-k-1]) ;
      }
    for(int i=0 ; i<n ; i++)
      if(sum[n-i-1]<maxm)
        grid[n-i-1][n-i-1]+=maxm-sum[n-i-1] ;
    curr=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        curr+=grid[i][j]-orig[i][j] ;
    if(curr<ans)
      {
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            res[i][j]=grid[i][j] ;
        ans=curr ;
      }

      // 4
      maxm=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        grid[i][j]=orig[i][j] ;
    for(int k=0 ; k<n ; k++)
      {
        sum[k]=0 ;
        for(int i=k ; i<n ; i++)
          {
            x=max(grid[k][n-i-1], grid[i][n-k-1]) ;
            grid[k][n-i-1]=grid[i][n-k-1]=x ;
          }
        for(int i=0 ; i<n ; i++)
          sum[k]+=grid[k][i] ;
        maxm=max(maxm, sum[k]) ;
      }
    for(int i=0 ; i<n ; i++)
      if(sum[i]<maxm)
        grid[i][n-i-1]+=maxm-sum[i] ;
    curr=0 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        curr+=grid[i][j]-orig[i][j] ;
    if(curr<ans)
      {
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<n ; j++)
            res[i][j]=grid[i][j] ;
        ans=curr ;
      }

    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<n ; j++)
          cout<< res[i][j] << " " ;
        cout<< endl ;
      }

  }
