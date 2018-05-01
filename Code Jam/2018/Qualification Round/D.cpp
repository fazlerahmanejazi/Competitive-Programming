#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-9
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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        ld A, l=0, r=pi/4, m, curr, c=0.5, x ;
        cin>> A ;
        while(abs(l-r)>eps)
          {
            m=(l+r)/2 ;
            x=cos(m)+sin(m) ;
            if(x>A) r=m ;
            else l=m ;
          }
        cout<< fixed << setprecision(12) << "Case #" << tc << ":" << endl ;
        cout<< 0 << " " << 0 << " " << 0.5 << endl ;
        cout<< c*cos(l) << " " << -c*sin(l) << " " << 0 << endl ;
        cout<< c*sin(l) << " " << c*cos(l) << " " << 0 << endl ;
      }
  }
