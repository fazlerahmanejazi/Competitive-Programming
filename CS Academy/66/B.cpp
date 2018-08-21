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

lli n, X, a, b, ans, d, curr ;
vpii data ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> X ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> b ;
        data.pb(mp(a, b)) ;
      }
    sort(all(data)) ;
    ans=X ;
    for(int i=0 ; i<n ; i++)
      if(data[i].fi<X)
        {
          d+=data[i].se ;
          curr=X-d ;
          ans=min(ans, curr) ;
        }
      else
        {
          d+=data[i].se ;
          curr=data[i].fi-d ;
          ans=min(ans, curr) ;
        }
    cout<< ans ;
  }
