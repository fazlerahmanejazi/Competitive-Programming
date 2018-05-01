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

#define ld long double

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int n, w, h ;
        vector<pair<ld, ld>> rectangle ;
        ld req, m, M, dp[110], curr, x, y, ans, diff=inf, tot=0 ;
        cin>> n >> req ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> w >> h ;
            tot+=2*(w+h) ;
            m=2*min(w, h) ;
            M=2*sqrt(1.0*w*w+h*h) ;
            if(m>req) continue ;
            rectangle.pb(mp(m, M)) ;
          }
        req-=tot ;
        n=rectangle.size() ;
        for(int i=1 ; i<=n ; i++)
          {
            tie(m, M)=rectangle[i-1] ;
            dp[i]=min(M, req) ;
            for(int j=1 ; j<i ; j++)
              {
                tie(x, y)=rectangle[j-1] ;
                dp[i]=max(dp[i], dp[j]) ;
                if(dp[j]+m<req)
                  {
                    dp[i]=dp[j]+m ;
                    if(dp[j]+M<req) dp[i]=max(dp[i], dp[j]+M) ;
                    else dp[i]=req ;
                  }
              }
            if(req-dp[i]<diff) diff=req-dp[i], ans=dp[i] ;
          }
        cout<< fixed << setprecision(9) << "Case #" << tc << ": " << tot+ans << endl ;
      }
  }
