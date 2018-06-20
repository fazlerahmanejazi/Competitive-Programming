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
    int n, x, y, l1, l2, u, v, dp[550], prev[550], mx=1, idx=0 ;
    cin>> n ;
    vi ans ;
    vector<tuple<int, int, int, int>> seg ;
    for(int i=0 ; i<n ; i++) cin>> x >> y, seg.pb(mt(y-x, x, y, i+1)) ;
    sort(all(seg)) ;
    dp[0]=1 ; prev[0]=-1 ;
    for(int i=1 ; i<n ; i++)
      {
        tie(l1, x, y, ignore)=seg[i] ;
        dp[i]=1 ;
        prev[i]=-1 ;
        for(int j=0 ; j<i ; j++)
          {
            tie(l2, u, v, ignore)=seg[j] ;
            if(l2<l1 && x<u && v<y && dp[j]+1>dp[i]) dp[i]=dp[j]+1, prev[i]=j ;
          }
        if(dp[i]>mx) mx=dp[i], idx=i ;
      }
    while(idx!=-1) ans.pb(get<3>(seg[idx])), idx=prev[idx] ;
    reverse(all(ans)) ;
    cout<< mx << endl ;
    for(auto i:ans) cout<< i << " " ;
  }
