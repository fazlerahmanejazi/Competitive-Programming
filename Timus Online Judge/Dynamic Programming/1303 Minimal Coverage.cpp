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

int n, m, l, r, x, c ;
int dp[50010] ;
vpii line, ans ;
map<int, int> R, L ;

void reconstruct(int x)
  {
    if(x<=0) return ;
    for(int i=x-1 ; i>=0 ; i--)
      if(dp[x]==dp[i]+1)
        {
          ans.pb(mp(R[x], x)) ;
          reconstruct(i) ;
          return ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> m ;
    while(cin>> l >> r && (l || r))
      {
        if(r>=1 && l<m)
          {
            if(R.find(r)!=R.end()) R[r]=min(R[r], l) ;
            else R[r]=l ;
          }
        if(l<m && r>0)
          {
            if(L.find(l)!=L.end()) L[l]=max(L[l], r) ;
            else L[l]=r ;
          }
      }
    for(auto x:R) line.pb(mp(x.se, x.fi)) ;
    for(auto x:L) line.pb(mp(x.fi, x.se)) ;
    n=line.size() ;
    sort(all(line), [&](pii a, pii b){return a.se<b.se ;}) ;
    memset(dp, inf, sizeof dp) ;
    dp[0]=0 ;
    for(int i=0 ; i<n ; i++)
      {
        tie(l, r)=line[i] ;
        l=max(0, l) ; r=min(r, m) ;
        for(int j=l ; j<=r ; j++)
          if(dp[r]>=1+dp[j])
            {
              x=line[i].se ;
              dp[r]=1+dp[j] ;
            }
      }
    for(int i=m+1 ; i<=x ; i++) dp[i]=dp[i-1] ;
    if(dp[m]!=inf)
      {
        cout<< dp[m] << endl ;
        reconstruct(x) ;
        sort(all(ans)) ;
        for(int i=0 ; i<ans.size() ; i++) cout<< ans[i].fi << " " << ans[i].se << endl ;
      }
    else cout<< "No solution" ;
  }
