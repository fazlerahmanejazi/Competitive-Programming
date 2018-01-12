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

lli gcd(lli a, lli b)
 {
   return b==0 ? a : gcd(b, a%b) ;
 }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, ans, x ;
    cin>> n ;
    vlli T(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> T[i] ;
    sort(all(T)) ;
    reverse(all(T)) ;
    ans=T[0] ;
    if(ans==1e18)
      {
        cout<< ans ;
        return 0 ;
      }
    for(int i=1 ; i<n ; i++)
      {
        x=((T[i])/(gcd(T[i], ans))) ;
        ans=ans*x ;
      }
    cout<< ans ;
  }
