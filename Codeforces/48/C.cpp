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

lli n, l, r, m, ans=3000000000 ;
vlli a ;

bool check(lli d)
  {
    lli curr=0, nxt ;
    nxt=upper_bound(all(a), a[curr]+d)-a.begin() ;
    if(nxt==n) return true ;
    curr=nxt ;
    nxt=upper_bound(all(a), a[curr]+d)-a.begin() ;
    if(nxt==n) return true ;
    curr=nxt ;
    nxt=upper_bound(all(a), a[curr]+d)-a.begin() ;
    if(nxt==n) return true ;
    return false ;
  }

void print(long double x)
  {
    cout<< fixed << setprecision(9) << x << " " ;
  }

void construct(lli d)
  {
    lli curr=0, nxt ;
    long double x ;
    nxt=upper_bound(all(a), a[curr]+d)-a.begin() ;
    x=(a[curr]+a[nxt-1])/2.0 ;
    print(x) ;
    if(nxt==n)
      {
        print(x) ; print(x) ;
        return ;
      }
    else curr=nxt ;
    nxt=upper_bound(all(a), a[curr]+d)-a.begin() ;
    x=(a[curr]+a[nxt-1])/2.0 ;
    print(x) ;
    if(nxt==n)
      {
        print(x) ;
        return ;
      }
    else curr=nxt ;
    nxt=upper_bound(all(a), a[curr]+d)-a.begin() ;
    x=(a[curr]+a[nxt-1])/2.0 ;
    print(x) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    sort(all(a)) ;
    l=0 ; r=3000000000 ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m)) ans=min(ans, m), r=m-1 ;
        else l=m+1 ;
      }
    print(ans/2.0) ;
    cout<< endl ;
    construct(ans) ;
  }
