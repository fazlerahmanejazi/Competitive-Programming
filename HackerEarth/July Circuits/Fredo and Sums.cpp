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
    int n, x, T ;
    cin>> T ;
    while(T--)
      {
        lli sMin=0, sMax=0, curr=0 ;
        cin>> n ;
        vlli a(n) ;
        for(int i=0 ; i<n ; i++)
          cin>> a[i] ;
        sort(all(a)) ;
        for(int i=0 ; i<n/2 ; i++)
          sMax+=abs(a[i]-a[n-1-i]) ;
        for(int i=0 ; i+1<n ; i+=2)
          sMin+=abs(a[i]-a[i+1]) ;
        for(int i=n-1 ; i-1>=0 ; i-=2)
          curr+=abs(a[i]-a[i-1]) ;
        sMin=min(sMin, curr) ;
        cout<< sMin << " " << sMax << endl ;
      }
  }
