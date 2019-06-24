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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli n, k, v, x ;
        vi ans ;
        vpii data ;
        cin>> n >> k >> v ;
        vector<string> name(n) ;
        for(int i=0 ; i<n ; i++) cin>> name[i], data.pb(mp(0, i)) ;
        v=(v-1)%n ;
        while(v--)
          {
            for(int i=0 ; i<k ; i++) data[i].fi++ ;
            sort(all(data)) ;
          }
        for(int i=0 ; i<k ; i++) ans.pb(data[i].se) ;
        sort(all(ans)) ;
        cout<< "Case #" << tc << ": " ;
        for(auto i:ans) cout<< name[i] << " " ;
        cout<< endl ;
      }
  }
