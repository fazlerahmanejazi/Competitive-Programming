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
    lli n, s, t, l[3], c[3], a[10010], dp[10010] ;
    for(int i=0 ; i<3 ; i++) cin>> l[i] ;
    for(int i=0 ; i<3 ; i++) cin>> c[i] ;
    cin>> n >> s >> t ;
    s-- ; t-- ;
    if(s>t) swap(s, t) ;
    for(int i=1 ; i<n ; i++) cin>> a[i] ;
    memset(dp, INF, sizeof dp) ;
    dp[s]=a[0]=0 ;
    for(int i=s+1 ; i<=t ; i++)
      for(int j=s ; j<i ; j++)
        for(int k=0 ; k<3 ; k++)
          if(a[i]-a[j]<=l[k])
            dp[i]=min(dp[i], dp[j]+c[k]) ;
    cout<< dp[t] ;
  }
