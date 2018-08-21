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

lli n, l, r, m, ans=INF, f1, f2 ;
vlli h(100005) ;

lli check(lli x)
  {
    if(x<0) return INF ;
    lli res=0 ;
    for(int i=0 ; i<n ; i++) res+=abs(h[i]-x) ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> h[i] ;
    l=-1 ; r=1000000000 ;
    while(r-l>1)
      {
        m=(l+r)/2 ;
        f1=check(m) ; f2=check(m+1) ;
        if(f1<f2)
          {
            r=m ;
            ans=min(ans, f1) ;
          }
        else
          {
            l=m ;
            ans=min(ans, f2) ;
          }
      }
    cout<< ans ;
  }
