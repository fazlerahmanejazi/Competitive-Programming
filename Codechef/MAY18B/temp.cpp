#include <bits/stdc++.h>
using namespace std ;

#define inf 1000000000000000000
#define lli long long int
#define pb push_back

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli n, l, r, curr, p=-1, mn=inf-1, x, y ;
        cin>> n ;
        vector<lli> a(n+1), pre(n+2, 0), dp(n+2, inf), idx, prev(n+2, -1) ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> a[i] ;
            pre[i]=pre[i-1]+a[i] ;
          }
        if(n==1)
          {
            cout<< -a[1] << '\n' ;
            continue ;
          }
        else if(n==2)
          {
            if(a[1]<a[2]) cout<< -a[1] << " " << a[2] << '\n' ;
            else if(a[1]>a[2]) cout<< a[1] << " " << -a[2] << '\n' ;
            else cout<< a[1] << " " << a[2] << '\n' ;
            continue ;
          }
        if(a[1]<a[2]) idx.pb(1) ;
        for(int i=2 ; i<=n-1 ; i++) if(a[i]<a[i-1] && a[i]<a[i+1]) idx.pb(i) ;
        if(a[n]<a[n-1]) idx.pb(n) ;
        for(int i=0 ; i<idx.size() ; i++)
          {
            if(i==0) dp[idx[i]]=-a[idx[i]] ;
            else
              {
                r=idx[i] ;
                dp[r]=pre[r]-2*a[r] ;
                for(int j=0 ; j<i ; j++)
                  {
                    l=idx[j] ;
                    curr=dp[l]+(pre[r]-pre[l])-2*a[r] ;
                    x=(pre[r]-pre[l])-2*a[r] ;
                    y=(pre[r]-pre[l])-a[l]-a[r] ;
                    if(x>a[l] && y>a[r] && curr<dp[r])
                      {
                        dp[r]=curr ;
                        prev[r]=l ;
                      }
                  }
              }
          }
        for(int i=1 ; i<=n ; i++)
          {
            dp[i]=dp[i]+pre[n]-pre[i] ;
            mn=min(mn, dp[i]) ;
          }
        for(int i=1 ; i<=n ; i++) if(mn==dp[i]) p=i ;
        while(p!=-1) a[p]=-a[p], p=prev[p] ;
        for(int i=1 ; i<=n ; i++) cout<< a[i] << " " ;
        cout<< '\n' ;
      }
  }
