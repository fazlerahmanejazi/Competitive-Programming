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

bool pos=true, same=true ;
lli n, x, mx, my, ans ;
set<lli> check ;
vlli a(100005), b(100005), c(100005) ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=1 ; i<=n ; i++) cin>> b[i] ;
    for(int i=1 ; i<=n ; i++)
      {
        if(a[i]>=b[i]) c[i]=a[i]-b[i] ;
        else pos=false ;
        mx=max(mx, a[i]) ;
        my=max(my, b[i]) ;
      }
    if(pos)
      {
        x=c[1] ;
        for(int i=1 ; i<=n ; i++) x=__gcd(x, c[i]) ;
        for(int j=1 ; j*j<=x ; j++) if(x%j==0) check.insert(x/j), check.insert(j) ;
        for(int i=1 ; i<=n ; i++) if(a[i]!=b[i]) same=false ;
        if(same)
          {
            cout<< mx+1 ;
            return 0 ;
          }
        ans=x;
        for(auto y:check) if(y>=my+1) ans=min(ans, y) ;
        if(ans>=my+1) cout<< ans ;
        else cout<< -1 ;
      }
    else
      {
        bool chk=true ;
        for(int i=1 ; i<=n ; i++) if(a[i] || b[i]) chk=false ;
        if(chk) cout<< 1 ;
        else cout<< -1 ;
      }
  }
