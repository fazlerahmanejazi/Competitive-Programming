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

lli R, B, C, M, S, P, ans, l, r, m ;
vector<tuple<lli, lli, lli>> data ;

bool check(lli x)
  {
    lli b=0, y ;
    vlli robots ;
    for(int i=0 ; i<C ; i++)
      {
        tie(M, S, P)=data[i] ;
        if(x>P)
          {
            y=(x-P)/S ;
            robots.pb(min(y, M)) ;
          }
      }
    sort(all(robots)) ;
    reverse(all(robots)) ;
    for(int i=0 ; i<min((int)robots.size(), (int)R) ; i++) b+=robots[i] ;
    if(b>=B) return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> R >> B >> C ;
        data.clear() ;
        for(int i=0 ; i<C ; i++)
          {
            cin>> M >> S >> P ;
            data.pb(mt(M, S, P)) ;
          }
        l=0 ; ans=r=5*INF ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            if(check(m)) r=m-1, ans=min(ans, m) ;
            else l=m+1 ;
          }
        cout<< "Case #" << tc << ": " << ans << endl ;
      }
  }
