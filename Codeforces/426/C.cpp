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

lli n, a, b, c, g, x, A, B, pos ;
vlli cubes ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(lli i=1 ; i<=1e6 ; i++)
      cubes.pb(i*i*i) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> b ;
        x=a*b ;
        pos=lower_bound(all(cubes), x)-cubes.begin() ;
        c=pos+1 ;
        A=a/c ; B=b/c ;
        if(A*B==c && a%c==0 && b%c==0) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
