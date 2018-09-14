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
using pii = pair<lli, lli> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<lli, lli>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli w, d, x, y, dx=0, dy=0, x1, y1 ;
    string s ;
    cin>> w >> d >> x >> y >> x1 >> y1 >> s ;
    for(auto i:s)
      if(i=='F') dy+=y, y=0 ;
      else if(i=='B') dy+=d-y, y=d ;
      else if(i=='R') dx+=w-x, x=w ;
      else dx+=x, x=0 ;
    dx+=abs(x-x1) ;
    dy+=abs(y-y1) ;
    cout<< fixed << setprecision(9) << sqrt(double(dx*dx+dy*dy)) ;
  }
