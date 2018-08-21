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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m=inf, ans=0, cnt=0, l, r, idx, x, res=0 ;
    cin>> n ;
    vi a(n), b, c, d(300005) ;
    vb taken(n, 0) ;
    idx=0 ;
    for(int i=0 ; i<n ; i++) cin>> a[i], m=min(m, a[i]) ;
    b.pb(a[0]) ;
    for(int i=1 ; i<n ; i++) if(a[i]!=b[b.size()-1]) b.pb(a[i]) ;
    for(int i=0 ; i<b.size() ; i++)
      if(i>0 && i<b.size()-1 && b[i-1]<b[i] && b[i+1]<b[i]) c.pb(i) ;
      else if(!i && b[i+1]<b[i]) c.pb(i) ;
      else if(i==b.size()-1 && b[i-1]<b[i]) c.pb(i) ;
    ans=1 ;
    for(int i=0 ; i<c.size() ; i++)
      {
        l=r=idx=c[i] ;
        x=b[idx] ;
        while(l>0 && b[l-1]!=m && b[l-1]<=x) l--, x=b[l] ;
        x=b[idx] ;
        while(r<b.size()-1 && b[r+1]!=m && b[r+1]<=x) r++, x=b[r] ;
        while(taken[l]) l++ ;
        while(taken[r]) r-- ;
        while(l<=r)
          if(b[l]<b[r]) ans++, taken[l]=true, l++ ;
          else if(b[l]>b[r]) ans++, taken[r]=true, r-- ;
          else taken[l]=true, taken[r]=true, l++, r--, ans++ ;
      }
    cout<< res ;
  }
