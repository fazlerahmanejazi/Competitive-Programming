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

int n, dp[100005], x, idx, ans ;
vb check(100005, 0) ;
vi a(100005), seq ;

int solve()
  {
    dp[0]=1 ;
    for(int i=1 ; i<=n ; i++)
      {
        x=a[i] ;
        idx=upper_bound(seq.begin(), seq.end(), x)-seq.begin() ;
        if(idx==seq.size()) seq.pb(x) ;
        else seq[idx]=x ;
        dp[i]=idx+1 ;
        ans=max(ans, dp[i]) ;
      }
    return n-ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i], a[i]-=i ;
    cout<< solve() ;
  }
