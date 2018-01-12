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
    int n, m, k, ans=0, idx ;
    cin>> n >> m >> k ;
    int rowCost[n+1], colCost[m+1] ;
    char grid[n+1][m+1] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> grid[i][j] ;
    if(k%2 && m%2)
      {
        for(int i=1 ; i<=n/2 ; i++)
          if(grid[i][(m+1)/2]!=grid[n-i+1][(m+1)/2])
            ans++ ;
        k/=2 ;
      }
    else k/=2
    memset(rowCost, 0, sizeof rowCost) ;
    memset(colCost, 0, sizeof colCost) ;
    for(int i=1 ; i<=n/2 ; i++)
      for(int j=1 ; j<=m/2 ; j++)
        if(grid[i][j]!=grid[n-i+1][j])
          {
            set<char> temp ;
            temp.insert(grid[i][j]) ;
            temp.insert(grid[i][m-j+1]) ;
            temp.insert(grid[n-i+1][j]) ;
            temp.insert(grid[n-i+1][m-j+1]) ;
            colCost[j]+=temp.size()-1 ;
          }
    priority_queue<pair<int, int>> pq ;
    for(int i=1 ; i<=m/2 ; i++) pq.push(mp(-colCost[i], i)) ;
    while(k)
      {
        tie(ignore, idx)=pq.top() ;
        pq.pop() ;
        for(int i=1 ; i<=n/2 ; i++)
          {
            map<char, int> cnt ;
            char c ; int mx=-1 ;
            cnt[grid[i][idx]]++ ;
            cnt[grid[i][m-idx+1]]++ ;
            cnt[grid[n-i+1][idx]]++ ;
            cnt[grid[n-i+1][m-idx+1]]++ ;
            for(auto it:cnt) if(it.se>mx) mx=it.se, c=it.fi ;
            grid[i][idx]=grid[i][m-idx+1]=grid[n-i+1][idx]=grid[n-i+1][m-idx+1]=c ;
            ans+=(4-mx) ;
          }
        k-- ;
      }
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        if(grid[i][j]!=grid[i][m-j+1])
          ans+=1 ;
    cout<< ans ;
  }
