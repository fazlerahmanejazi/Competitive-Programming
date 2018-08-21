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
    lli d1, d2, k, x, y ;
    cin>> d1 >> d2 >> k ;
    for(int i=1 ; i<=k ; i++)
      {
        x=(d1+1)*d2 ;
        y=d1*(d2+1) ;
        if(x>y) d1++ ;
        else d2++ ;
      }
    cout<< fixed << setprecision() << d1*d2/2.0 ;
  }
