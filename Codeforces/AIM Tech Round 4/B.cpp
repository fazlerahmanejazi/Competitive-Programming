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
    lli n, m, black, white, curr, ans=0, B, W ;
    cin>> n >> m ;
    lli grid[n+1][m+1] ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        cin>> grid[i][j] ;
    for(int i=0 ; i<n ; i++)
      {
        curr=0 ;
        for(int j=0 ; j<m ; j++)
          if(grid[i][j]) curr++ ;
        white=curr ;
        black=m-curr ;
        W=pow(2, white)-1-white ;
        B=pow(2, black)-1-black ;
        ans+=B+W ;
      }
    for(int i=0 ; i<m ; i++)
      {
        curr=0 ;
        for(int j=0 ; j<n ; j++)
          if(grid[j][i]) curr++ ;
        white=curr ;
        black=n-curr ;
        W=pow(2, white)-1-white ;
        B=pow(2, black)-1-black ;
        ans+=B+W ;
      }
    ans+=n*m ;
    cout<< ans ;
  }
