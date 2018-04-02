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

void in(vector<vlli> &X, lli n)
  {
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        cin>> X[i][j] ;
  }

vlli perform(vector<vlli> &X, vlli Y, lli n)
  {
    vlli res(n, 0) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        res[i]=(res[i]+(X[i][j]*Y[j])%mod)%mod ;
    return res ;
  }

vlli get(lli n)
  {
    vlli res(n) ;
    for(int i=0 ; i<n ; i++) res[i]=rand() ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n ;
    cin>> n ;
    vlli P, Q ;
    vector<vlli> A(n, vlli(n)), B(n, vlli(n)), C(n, vlli(n)) ;
    in(A, n) ; in(B, n) ; in(C, n) ;
    P=Q=get(n) ;
    P=perform(B, P, n) ;
    P=perform(A, P, n) ;
    Q=perform(C, Q, n) ;
    if(P==Q) cout<< "YES" ;
    else cout<< "NO" ;
  }
