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

lli n, x, off ;
long double ans, curr ;
vlli a, nge ;
vector<long double> dp ;

lli get(lli x)
  {
    if(x==1) return 2 ;
    else if(x==-1) return -2 ;
    else return 1 ;
  }

void nextGreater()
  {
    stack<lli> S ;
    for(int i=n ; i>=0 ; i--)
      {
        while(!S.empty() && a[S.top()]<a[i]) S.pop() ;
        if(!S.empty()) nge[i]=S.top() ;
        else nge[i]=i ;
        S.push(i) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.pb(0) ; nge.pb(0) ;
    dp.assign(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        a.pb(get(x)) ;
        nge.pb(i) ;
      }
    for(int i=1 ; i<=n ; i++) a[i]+=a[i-1], off=min(a[i], off) ;
    for(int i=0 ; i<=n ; i++) a[i]+=abs(off) ;
    nextGreater() ;
    for(lli i=n-1 ; i>=0 ; i--)
      {
        x=nge[i] ;
        if(x==i)
          {
            curr=n-i ;
            dp[i]=curr ;
          }
        else
          {
            if(a[x]>a[i]) x-- ;
            if(a[x]==a[i]) curr=x-i+dp[x] ;
            else curr=x-i+0.5+dp[x] ;
            dp[i]=curr ;
          }
        ans=max(ans, curr) ;
      }
    cout<< ans ;
  }
