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

lli t1, t2, x1, x2, t0, z, mx, ans1, ans2 ;
long double diff, curr ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> t1 >> t2 >> x1 >> x2 >> t0 ;
    if(t0==t2)
      {
        if(t0==t1) cout<< x1 << " " << x2 ;
        else cout<< 0 << " " << x2 ;
        return 0 ;
      }
    diff=t2-t0 ;
    ans1=0 ; ans2=mx=x2 ;
    for(lli y1=0 ; y1<=x1 ; y1++)
      {
        z=(y1*(t0-t1))/(t2-t0) ;
        for(lli y2=max(z-2, 0LL) ; y2<=z+2 ; y2++)
          if(y1+y2>0)
            {
              curr=(1.0*(t1*y1+t2*y2))/(1.0*(y1+y2)) ;
              if(y2<=x2 && curr>=t0 && curr-t0<=diff)
                {
                  if(curr-t0==diff && y1+y2>=mx) mx=y1+y2, ans1=y1, ans2=y2 ;
                  else if(curr-t0<diff) diff=curr-t0, mx=y1+y2, ans1=y1, ans2=y2 ;
                }
            }
      }
    cout<< ans1 << " " << ans2 ;
  }
