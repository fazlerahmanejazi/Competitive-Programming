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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, x, period, c ;
    vi a ;
    cin>> n >> k >> x ;
    vvi data ;
    a.resize(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    sort(all(a)) ;
    data.pb(a) ;
    for(int i=1 ; i<=k ; i++)
      {
        for(int i=0 ; i<n ; i++)
          if(i%2==0)
            a[i]^=x ;
        sort(all(a)) ;
        data.pb(a) ;
        c=i ;
        for(int j=0 ; j<i ; j++)
          if(data[j]==data[i])
            {
              period=i-j ;
              k=k-j ;
              k=k%period ;
              k=k+j ;
              cout<< data[k][n-1] << " " << data[k][0] ;
              return 0 ;
            }
      }
    cout<< data[k][n-1] << " " << data[k][0] ;
  }
