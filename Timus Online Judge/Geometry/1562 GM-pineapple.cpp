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
using pii = pair<lli, lli> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<lli, lli>> ;

int n ;
long double a, b, curr ;

long double ellipsoidalCap(long double h)
  {
    return (pi*a*a*h*h*(3*b-h))/(3*b*b) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> a >> b >> n ;
    a/=2 ; b/=2 ;
    for(int i=1 ; i<=n ; i++)
      {
        curr=ellipsoidalCap(i*(2*b)/n)-ellipsoidalCap((i-1)*(2*b)/n) ;
        cout<< fixed << setprecision(9) << curr << endl ;
      }
  }
