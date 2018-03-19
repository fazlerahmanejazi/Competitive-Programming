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

int n ;
lli temp ;
bool check ;
vlli a ;
lli dp[200005][2] ;
bool done[200005][2] ;

lli dfs(lli x, int type)
  {
    lli temp ;
    if(x>n || x<=0) return 0 ;
    if(done[x][type])
      {
        dp[x][type]=-1 ;
        return dp[x][type] ;
      }
    if(dp[x][type]) return dp[x][type] ;
    done[x][type]=true ;
    if(type)
      {
        temp=dfs(x-a[x], 1-type) ;
        if(temp<0) dp[x][type]=temp ;
        else dp[x][type]=a[x]+temp ;
      }
    else
      {
        temp=dfs(x+a[x], 1-type) ; ;
        if(temp<0) dp[x][type]=temp ;
        else dp[x][type]=a[x]+temp ;
      }
    return dp[x][type] ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n+1) ;
    memset(dp, 0, sizeof dp) ;
    for(int i=2 ; i<=n ; i++)
      cin>> a[i] ;
    for(int i=1 ; i<=n-1 ; i++)
      {
        memset(done, false, sizeof done) ;
        dp[1][0]=i ;
        done[1][0]=true ;
        temp=dfs(i+1, 1) ;
        if(temp<0) cout<< -1 << endl ;
        else cout<< dp[1][0]+temp << endl ;
      }
  }
