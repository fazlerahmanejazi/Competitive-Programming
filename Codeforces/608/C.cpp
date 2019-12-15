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

lli n, sx, sy, x[200010], y[200010], ans, ansX, ansY, curr ;

lli check(lli tx, lli ty)
  {
    if(tx<0 || ty<0) return 0 ;
    lli cnt=0 ;
    for(int i=1 ; i<=n ; i++)
      if(min(sx, x[i])<=tx && tx<=max(sx, x[i]) && min(sy, y[i])<=ty && ty<=max(sy, y[i])) cnt++ ;
    return cnt ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> sx >> sy ;
    for(int i=1 ; i<=n ; i++) cin>> x[i] >> y[i] ;
    curr=check(sx-1, sy) ;
    if(curr>ans) ans=curr, ansX=sx-1, ansY=sy ;
    curr=check(sx+1, sy) ;
    if(curr>ans) ans=curr, ansX=sx+1, ansY=sy ;
    curr=check(sx, sy-1) ;
    if(curr>ans) ans=curr, ansX=sx, ansY=sy-1 ;
    curr=check(sx, sy+1) ;
    if(curr>ans) ans=curr, ansX=sx, ansY=sy+1 ;
    cout<< ans << endl << ansX << " " << ansY ;
  }
