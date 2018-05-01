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

lli n, x1, x2, l, r, m, ans ;
vlli c ;



int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> x1 >> x2 ;
    c.resize(n) ;
    for(int i=0 ; i<n ; i++) cin>> c[i] ;
    sort(all(c)) ;
    l=-1 ; r=n ;
    while(r-l>1)
      {
        m=(l+r)/2 ;
        f1=check(m) ; f2=check(m+1) ;
        if(f1>f2)
          {
            r=m ;
            ans=max(ans, f1) ;
          }
        else
          {
            l=m ;
            ans=max(ans, f2) ;
          }
      }
