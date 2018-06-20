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

bool overflow(lli x, lli y)
  {
    return (x>INF/y) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, k, p, s, curr, extra, ans=0 ;
    cin>> n >> k ;
    vlli a(n), nxt(n) ;
    curr=n ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        nxt[i]=curr ;
        if(a[i]!=1) curr=i ;
      }
    for(int i=0 ; i<n ; i++)
      {
        p=1 ;
        s=0 ;
        for(int j=i ; j<n ; j=nxt[j])
          {
            if(overflow(p, a[j])) break ;
            p*=a[j] ;
            s+=a[j] ;
            extra=nxt[j]-j-1 ;
            if(!(p%k) && s<=p/k && p/k<=s+extra) ans++ ;
            s+=extra ;
          }
      }
    cout<< ans ;
  }
