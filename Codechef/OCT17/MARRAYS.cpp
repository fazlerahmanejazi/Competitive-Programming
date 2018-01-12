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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli n, m, x, ans=0, y ;
        cin>> n ;
        vector<vlli> dp(n+1), a(n+1) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> m ;
            for(int j=0 ; j<m ; j++)
              {
                cin>> x ;
                a[i].pb(x) ;
                dp[i].pb(0) ;
              }
          }
        if(n==1) cout<< 0 << endl ;
        else if(n==2)
          {
            sort(all(a[0])) ; sort(all(a[1])) ;
            x=abs(a[1][a[1].size()-1]-a[0][0]) ;
            ans=max(x, ans) ;
            x=abs(a[1][0]-a[0][a[0].size()-1]) ;
            ans=max(x, ans) ;
            cout<< ans << endl ;
          }
        else
          {
            for(int i=n-2 ; i>=0 ; i--)
              for(int j=0 ; j<a[i].size() ; j++)
                {
                  y=j-1 ;
                  if(!j) y=a[i].size()-1 ;
                  for(int k=0 ; k<a[i+1].size() ; k++)
                    {
                      x=dp[i+1][k]+abs(a[i+1][k]-a[i][y])*(lli)(i+1) ;
                      dp[i][j]=max(x, dp[i][j]) ;
                    }
                }
            for(auto i:dp[0]) ans=max(ans, i) ;
            cout<< ans << endl ;
          }
      }
  }
