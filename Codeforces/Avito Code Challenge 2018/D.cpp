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

lli N, K, curr, l, r, m, ans ;
vlli a, pre ;
bool dp[55][55] ;

bool check(lli x)
  {
    memset(dp, false, sizeof dp) ;
    for(int i=1 ; i<=N ; i++) if((pre[i]&x)==x) dp[i][1]=true ;
    for(int i=2 ; i<=N ; i++)
      for(int j=1 ; j<=K ; j++)
        for(int k=1 ; k<=i ; k++)
          if(i-k>=j-1 && ((pre[i]-pre[i-k])&x)==x)
            dp[i][j]|=dp[i-k][j-1] ;
    return dp[N][K] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> N >> K ;
    a.resize(N+1) ;
    pre.assign(N+1, 0) ;
    for(int i=1 ; i<=N ; i++) cin>> a[i], pre[i]=pre[i-1]+a[i] ;
    for(int B=60 ; B>=0 ; B--) if(check(ans+(1LL<<B))) ans+=1LL<<B ;
    cout<< ans ;
  }
