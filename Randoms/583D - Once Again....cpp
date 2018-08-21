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

int n, T, x, res=0, curr, idx ;
vi a, cnt(301, 0), dp, seq, b, ans(301, 0) ;

int get(int val)
  {
    vi dp(n*n, 0), seq ;
    int ans=0, idx ;
    for(int i=0 ; i<n*n ; i++)
      if(a[i]>=val)
        {
          idx=upper_bound(seq.begin(), seq.end(), a[i])-seq.begin() ;
          if(idx==seq.size()) seq.pb(a[i]) ;
          else seq[idx]=a[i] ;
          dp[i]=idx+1 ;
          ans=max(ans, dp[i]) ;
        }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> T ;
    a.resize(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        b.pb(a[i]) ;
        cnt[a[i]]++ ;
      }
    for(int i=2 ; i<=min(T, 2*n) ; i++)
      for(int j=0 ; j<n ; j++)
        a.pb(a[j]) ;
    if(T<=2*n)
      {
        dp.assign(n*T, 0) ;
        for(int i=0 ; i<n*T ; i++)
          {
            x=a[i] ;
            idx=upper_bound(seq.begin(), seq.end(), x)-seq.begin() ;
            if(idx==seq.size()) seq.pb(x) ;
            else seq[idx]=x ;
            dp[i]=idx+1 ;
            res=max(res, dp[i]) ;
          }
      }
    else
      {
        dp.assign(n*n, 0) ;
        for(int i=1 ; i<=300 ; i++)
          ans[i]=get(i) ;
        for(int i=0 ; i<n*n ; i++)
          {
            x=a[i] ;
            idx=upper_bound(seq.begin(), seq.end(), x)-seq.begin() ;
            if(idx==seq.size()) seq.pb(x) ;
            else seq[idx]=x ;
            dp[i]=idx+1 ;
            x=ans[a[i]] ;
            curr=dp[i]+cnt[a[i]]*(T-2*n)+x ;
            res=max(res, curr) ;
          }
      }
    cout<< res ;
  }
