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
    int T, n, d ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> d ;
        if(n!=1)
          {
            long double x=1.0+((1.0*d*n)/sqrt(1.0*n-1)) ;
            for(int i=1 ; i<n ; i++) cout<< 1 << " " ;
            cout<< x << endl ;
          }
        else if(d) cout<< -1 << endl ;
        else cout<< 1 << endl ;
      }
  }
