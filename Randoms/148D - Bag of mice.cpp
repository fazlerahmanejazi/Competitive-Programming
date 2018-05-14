#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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

map<pair<int, int>, double> done ;

double solve(double w, double b)
  {
    if(w<=0) return 0 ;
    if(b<=0) return 1 ;
    if(done.find(mp(w, b))!=done.end()) return done[mp(w, b)] ;
    double ans=w/(w+b), temp, x, y, z ;
    if(b>=2)
      {
        x=(b/(w+b)) ;
        y=((b-1)/(w+b-1)) ;
        z=w/(w+b-2) ;
        ans+=x*y*z*solve(w-1, b-2) ;
        z=(b-2)/(w+b-2) ;
        ans+=x*y*z*solve(w, b-3) ;
      }
    done[mp(w, b)]=ans ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    double w, b, ans ;
    cin>> w >> b ;
    ans=solve(w, b) ;
    cout<< fixed << setprecision(9) << ans ;
  }
