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

lli n, m, k, d, ans, x, y ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> d ;
    while(d--)
      {
        cin>> n >> m >> k ;
        k++ ;
        ans=0 ;
        if(k>4)
          {
            cout<< 0 << endl ;
            continue ;
          }
        else if(k==4)
          {
            for(int i=2 ; i<=min(n, m) ; i++)
              {
                x=n-i+1 ;
                y=m-i+1 ;
                ans+=4*3*2*(x*y) ;
                ans%=mod ;
              }
            for(int i=3 ; i<=min(n, m) ; i+=2)
              {
                x=n-i+1 ;
                y=m-i+1 ;
                ans+=4*3*2*(x*y) ;
                ans%=mod ;
              }
            cout<< ans << endl ;
          }
        else if(k==3)
          {
            for(int i=2 ; i<=min(n, m) ; i++)
              {
                x=n-i+1 ;
                y=m-i+1 ;
                ans+=4*3*2*(x*y) ;
                ans%=mod ;
              }
            for(int i=3, j=2 ; i<=n && j<=m ; i+=2, j++)
              {
                x=n-i+1 ;
                y=m-j+1 ;
                ans+=3*2*2*(x*y) ;
                ans%=mod ;
              }
            for(int i=3, j=2 ; i<=m && j<=n ; i+=2, j++)
              {
                x=m-i+1 ;
                y=n-j+1 ;
                ans+=3*2*2*(x*y) ;
                ans%=mod ;
              }
            cout<< ans << endl ;
          }
        else if(k==2)
          {
            for(int i=2 ; i<=min(n, m) ; i++)
              {
                x=n-i+1 ;
                y=m-i+1 ;
                ans+=2*2*(x*y) ;
                ans%=mod ;
              }
            for(int i=2 ; i<=n ; i++)
              {
                x=n-i+1 ;
                y=m ;
                ans+=2*(x*y) ;
                ans%=mod ;
              }
            for(int i=2 ; i<=m ; i++)
              {
                x=m-i+1 ;
                y=n ;
                ans+=2*(x*y) ;
                ans%=mod ;
              }
            cout<< ans << endl ;
          }
      }
  }
