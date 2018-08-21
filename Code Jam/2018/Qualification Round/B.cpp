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
        int n, x, l=0, r=0, ans=-1 ;
        cin>> n ;
        vi a, b, c ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            if(i%2) b.pb(x) ;
            else a.pb(x) ;
          }
        sort(all(a)) ;
        sort(all(b)) ;
        for(int i=0 ; i<n ; i++)
          if(i%2) c.pb(b[r++]) ;
          else c.pb(a[l++]) ;
        for(int i=0 ; i<n-1 ; i++)
          if(c[i]>c[i+1])
            {
              ans=i ;
              break ;
            }
        if(ans!=-1) cout<< "Case #" << tc << ": " << ans << endl ;
        else cout<< "Case #" << tc << ": " << "OK" << endl ;
      }
  }
