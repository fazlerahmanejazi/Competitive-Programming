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
    int n, m, k, a, b, ans=0 ;
    cin>> n ;
    for(int i=1 ; i<=sqrt(n) ; i++)
      if(n%i==0)
        {
          if(n/i==i)
            {
              a=m=i ;
              k=m-1 ;
              b=a*k ;
              if(b>=a) ans++ ;
            }
          else
            {
              a=i ;
              m=n/i ;
              k=m-1 ;
              b=a*k ;
              if(b>=a) ans++ ;
              a=n/i ;
              m=i ;
              k=m-1 ;
              b=a*k ;
              if(b>=a) ans++ ;
            }
        }
    cout<< ans ;
  }
