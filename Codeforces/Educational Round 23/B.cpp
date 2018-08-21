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
    lli n, ans=0, c=0, x ;
    cin>> n ;
    vlli a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    sort(all(a)) ;
    if(a[0]==a[1] && a[1]==a[2])
      {
        x=a[0] ;
        for(int i=0 ; i<n ; i++)
          if(x==a[i]) c++ ;
          else break ;
        ans=c*(c-1)*(c-2) ;
        ans=ans/(6) ;
        cout<< ans ;
        return 0 ;
      }
    else if(a[0]==a[1])
      {
        x=a[2] ;
        ans=1 ;
        for(int i=3 ; i<n ; i++)
          if(x==a[i]) ans++ ;
          else break ;
        cout<< ans ;
        return 0 ;
      }
    else if(a[1]==a[2])
      {
        x=a[1] ;
        c=0 ;
        for(int i=1 ; i<n ; i++)
          if(x==a[i]) c++ ;
          else break ;
        ans=(c*(c-1))/2 ;
        cout<< ans ;
        return 0 ;
      }
    else
      {
        x=a[2] ;
        ans=1 ;
        for(int i=3 ; i<n ; i++)
          if(x==a[i]) ans++ ;
          else break ;
        cout<< ans ;
        return 0 ;
      }
  }
