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



long long int solve()
  {
    long long int x1, y1, x2, y2, xc, yc, R ;
    cin>> x1 >> y1 >> x2 >> y2 >> xc >> yc >> R ;
    long long int ans=0, dR, uR, dC, uC, u, d ;
    if(x1>x2) swap(x1, x2), swap(y1, y2) ;
    for(long long int i=x1 ; i<=x2 ; i++)
      if(R*R>=(i-xc)*(i-xc))
        {
          dR=y1 ; uR=y2 ;
          dC=min(yc+sqrt(R*R-(i-xc)*(i-xc)), yc-sqrt(R*R-(i-xc)*(i-xc))) ;
          uC=max(yc+sqrt(R*R-(i-xc)*(i-xc)), yc-sqrt(R*R-(i-xc)*(i-xc))) ;
          if((dC-yc)*(dC-yc)+(i-xc)*(i-xc)>R*R) dC++ ;
          if((uC-yc)*(uC-yc)+(i-xc)*(i-xc)>R*R) uC++ ;
          if((dC-yc)*(dC-yc)+(i-xc)*(i-xc)>R*R || (uC-yc)*(uC-yc)+(i-xc)*(i-xc)>R*R) continue ;
          if(dC>uR || uC<dR) continue ;
          d=max(dC, dR) ;
          u=min(uC, uR) ;
          ans+=(u-d+1) ;
        }
      return ans ;
  }

int main()
  {
    cout<< solve() ;
  }
