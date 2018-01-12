#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    long double n, a, x, diff, ans, idx ;
    vector<long double> angles ;
    cin>> n >> a ;
    x=180.0-(360.0/n) ;
    diff=180.0/n ;
    angles.pb(x) ;
    for(int i=1 ; i<=n-3 ; i++)
      {
        x-=diff ;
        angles.pb(x) ;
      }
    ans=angles[0] ;
    idx=3 ;
    for(int i=1 ; i<angles.size() ; i++)
      if(abs(angles[i]-a)<abs(ans-a))
        {
          ans=angles[i] ;
          idx=i+3 ;
        }
    cout<< 1 << " " << 2 << " " << idx ;
  }
