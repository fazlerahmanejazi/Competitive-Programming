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
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, c=1 ;
        bool isRainbow=true, reverse=false, same=true ;
        cin>> n ;
        vi a(n) ;
        for(int i=0 ; i<n ; i++)
          cin>> a[i] ;
        if(a[0]!=c) isRainbow=false ;
        for(int i=0 ; i<n ; i++)
          {
            if(a[i]!=c)
              {
                same=false ;
                if(c==7) reverse=true ;
                if(reverse) c-- ;
                else c++ ;
                if(a[i]!=c) isRainbow=false ;
              }
            if(a[i]!=a[n-i-1] || a[i]>7) isRainbow=false ;
          }
        if(isRainbow && !same) cout<< "yes" << endl ;
        else cout<< "no" << endl ;
      }
  }
