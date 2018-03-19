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
    lli T, n, x, y, z, curr ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        for(int i=1 ; i<=5 ; i++)
          {
            x=((4294967296-i-1)/(n-i)) ;
            y=(x*(n-i)+i+1)%4294967296 ;
            curr=(x*(n-i+1)+i)%4294967296 ;
            if(curr<y)
              {
                for(int j=1 ; j<=i ; j++) cout<< "1" << " " ;
                for(int j=i+1 ; j<=n ; j++) cout<< x << " " ;
                break ;
              }
          }
        cout<< endl ;
      }
  }
