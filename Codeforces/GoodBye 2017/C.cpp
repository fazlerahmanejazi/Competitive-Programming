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

#define ld long double

lli n, r ;
vlli x(1010) ;
vector<ld> y ;
ld p, Y ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> r ;
    for(int i=0 ; i<n ; i++) cin>> x[i] ;
    y.pb(r) ;
    for(int i=1 ; i<n ; i++)
      {
        Y=r ;
        for(int j=0 ; j<i ; j++)
          {
            if(abs(x[j]-x[i])>2*r) continue ;
            p=4*r*r-(x[j]-x[i])*(x[j]-x[i]) ;
            p=y[j]+sqrt(p) ;
            Y=max(Y, p) ;
          }
        y.pb(Y) ;
      }
    for(auto i:y) cout<< fixed << setprecision(9) << i << " " ;
  }
