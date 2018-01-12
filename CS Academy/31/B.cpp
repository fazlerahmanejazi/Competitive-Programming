#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, l, x, ans=-1, cnt ;
    cin>> n >> m ;
    vector<vector<bool>> a(n+1, vector<bool>(m+1)) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        a[i][j]=false ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> l ;
        for(int j=0 ; j<l ; j++)
          {
            cin>> x ;
            a[i][x]=true ;
          }
      }
    for(int i=1 ; i<=n ; i++)
      for(int j=i+1 ; j<=n ; j++)
        {
          cnt=0 ;
          for(int k=1 ; k<=m ; k++)
            if(a[i][k] && a[j][k])
              cnt++ ;
          ans=max(ans, cnt) ;
        }
    cout<< ans ;
  }
