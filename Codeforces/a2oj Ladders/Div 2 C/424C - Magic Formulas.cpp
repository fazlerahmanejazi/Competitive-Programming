#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    long long int n, ans=0, x ;
    cin>> n ;
    vlli p(n+1), f(n+1) ;
    f[0]=0 ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> p[i] ;
        f[i]=f[i-1]^i ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        if((n/i)%2) x=p[i]^f[i-1]^f[n%i] ;
        else x=p[i]^f[n%i] ;
        ans^=x ;
      }
    cout<< ans ;
  }
