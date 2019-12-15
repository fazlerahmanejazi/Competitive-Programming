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

lli n, k, l, r, m, ans, curr ;
set<lli> found ;

lli calc1(lli x)
  {
    lli s=n, ans=0, d=x-1, c=1 ;
    while(s>=0)
      {
        s-=d ;
        if(s>=0) ans+=min(s, c) ;
        s-=c ;
        if(c!=1) d*=2 ;
        c*=2 ;
      }
    return ans;
  }

lli calc2(lli x)
  {
    return calc1(x)+calc1(x+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    if(n==k) ans=1 ;
    else ans=2 ;
    l=1 ; r=n ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        curr=calc2(2*m+1) ;
        if(curr>=k) l=m+1, ans=max(ans, 2*m+1) ;
        else r=m-1 ;
      }
    l=2 ; r=n ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        curr=calc1(2*m) ;
        if(curr>=k) l=m+1, ans=max(ans, 2*m) ;
        else r=m-1 ;
      }
    cout<< ans ;
  }
