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

int gcd(int a, int b)
 {
   return b==0 ? a : gcd(b, a%b) ;
 }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, g, x, ans=0 ;
    cin>> n ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
     cin>> a[i] ;
    g=gcd(a[0], a[1]) ;
    for(int i=2 ; i<n ; i++)
      g=gcd(g, a[i]) ;
    if(g>1) cout<< "YES" << endl << 0 ;
    else
      {
        for(int i=0 ; i<n ; i++)
          if(a[i]%2)
            {
              if(i+1<n && a[i+1]%2)
                {
                  ans++ ;
                  a[i+1]++ ;
                }
              else ans+=2 ;
            }
        cout<< "YES" << endl ;
        cout<< ans ;
      }
  }
