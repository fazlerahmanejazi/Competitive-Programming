#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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
    int n, q, x, m ;
    string s ;
    char fav ;
    cin>> n >> s >> q ;
    s='*'+s ;
    int sum[30][n+2], ans[30][n+2] ;
    memset(sum, 0, sizeof sum) ;
    memset(ans, 0, sizeof ans) ;
    for(int i=0 ; i<26 ; i++)
      {
        sum[i][0]=0 ;
        char y='a'+i ;
        for(int j=1 ; j<=n ; j++)
          if(s[j]==y) sum[i][j]=sum[i][j-1]+1 ;
          else sum[i][j]=sum[i][j-1] ;
      }
    for(int k=0 ; k<26 ; k++)
      {
        for(int i=1 ; i<=n ; i++)
          for(int j=i ; j<=n ; j++)
            {
              x=j-i+1-(sum[k][j]-sum[k][i-1]) ;
              ans[k][x]=max(ans[k][x], j-i+1) ;
            }
        for(int i=1 ; i<=n ; i++)
          ans[k][i]=max(ans[k][i], ans[k][i-1]) ;
      }
    for(int i=0 ; i<q ; i++)
      {
        cin>> m >> fav ;
        cout<< ans[fav-'a'][m] << endl ;
      }
  }
