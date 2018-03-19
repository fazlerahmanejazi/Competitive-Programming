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

#define maxM 1000000000

lli gcd(lli a, lli b)
 {
   return b==0 ? a : gcd(b, a%b) ;
 }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, m, x ;
    bool pos=true ;
    cin>> n >> m ;
    vlli u(n+1, 1), v(m+1, 1) ;
    vvi mat(n+1, vi(m+1)) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        {
          cin>> x ;
          mat[i][j]=x ;
          if(u[i]%x) u[i]*=(x/gcd(x, u[i])) ;
          if(v[j]%x) v[j]*=(x/gcd(x, v[j])) ;
          if(u[i]>maxM || v[j]>maxM || gcd(u[i], v[j])>mat[i][j]) pos=false ;
        }
    if(pos)
      {
        for(int i=1 ; i<=n ; i++)
          cout<< u[i] << " " ;
        cout<< endl ;
        for(int i=1 ; i<=m ; i++)
          cout<< v[i] << " " ;
      }
    else cout<< -1 ;
  }
