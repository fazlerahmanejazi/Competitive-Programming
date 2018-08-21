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
    int n, c=0, len ;
    cin>> n ;
    double x, sum=0, ans=inf ;
    for(int i=0 ; i<2*n ; i++)
      {
        cin>> x ;
        if(floor(x)==x) c++ ;
        else sum+=(x-floor(x)) ;
      }
    len=2*n-c ;
    if(!len) ans=0 ;
    else if(c<n)
      for(int i=n-c-1 ; i<n ; i++)
          {
            x=abs((len-i-1)-(sum)) ;
            ans=min(ans, x) ;
          }
    else
      for(int i=-1 ; i<len ; i++)
        {
          x=abs((len-i-1)-(sum)) ;
          ans=min(ans, x) ;
        }
    cout<< fixed << setprecision(3) << ans ;
  }
