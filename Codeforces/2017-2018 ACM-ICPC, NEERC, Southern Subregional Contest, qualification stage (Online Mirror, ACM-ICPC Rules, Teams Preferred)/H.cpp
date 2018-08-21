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
    lli n, curr, ans=INF ;
    cin>> n ;
    vlli a(n+1, 0) ;
    vector<pair<lli, lli>> dpL(n+1), dpR(n+1) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    dpL[1].fi=0 ; dpL[1].se=a[1] ;
    dpR[n].fi=0 ; dpR[n].se=a[n] ;
    for(int i=2 ; i<=n ; i++)
      if(dpL[i-1].se<a[i]) dpL[i]=mp(dpL[i-1].fi, a[i]) ;
      else dpL[i]=mp(dpL[i-1].fi+(dpL[i-1].se+1-a[i]), dpL[i-1].se+1) ;
    for(int i=n-1 ; i>=1 ; i--)
      if(dpR[i+1].se<a[i]) dpR[i]=mp(dpR[i+1].fi, a[i]) ;
      else dpR[i]=mp(dpR[i+1].fi+(dpR[i+1].se+1-a[i]), dpR[i+1].se+1) ;
    for(int i=2 ; i<n ; i++)
      {
        curr=dpL[i-1].fi+dpR[i+1].fi ;
        curr+=max(0LL, max(dpL[i-1].se, dpR[i+1].se)+1-a[i]) ;
        ans=min(curr, ans) ;
      }
    if(n>=2)
      {
        curr=dpL[n-1].fi ;
        curr+=max(0LL, dpL[n-1].se+1-a[n]) ;
        ans=min(curr, ans) ;
        curr=dpR[2].fi ;
        curr+=max(0LL, dpR[2].se+1-a[1]) ;
        ans=min(curr, ans) ;
      }
    else if(n==1) ans=0 ;
    cout<< ans ;
  }
