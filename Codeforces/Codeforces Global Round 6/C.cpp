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
    lli n, r, c, mat[600][600], x[600], y[600] ;
    cin>> r >> c ;
    n=r+c ;
    for(int i=1 ; i<=r ; i++)
      for(int j=1 ; j<=c ; j++)
        mat[i][j]=1 ;
    if(r==1 && c==1) return cout<< 0, 0 ;
    if(r==1)
      {
        for(int i=2 ; i<=c+1 ; i++) cout<< i << " " ;
        return 0 ;
      }
    if(c==1)
      {
        for(int i=2 ; i<=r+1 ; i++) cout<< i << endl ;
        return 0 ;
      }
    for(int i=1 ; i<=r ; i++, n--)
      for(int j=1 ; j<=c ; j++)
        mat[i][j]*=n ;
    for(int j=1 ; j<=c ; j++, n--)
      for(int i=1 ; i<=r ; i++)
        mat[i][j]*=n ;
    for(int i=1 ; i<=r ; i++, cout<<endl)
      for(int j=1 ; j<=c ; j++)
        cout<< mat[i][j] << " " ;
  }
