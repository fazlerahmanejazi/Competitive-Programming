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

lli nCr[5010][5010] ;

void init()
  {
    for(int i=0 ; i<=5000 ; i++) nCr[i][0]=nCr[i][i]=1 ;
    for(int i=1 ; i<=5000 ; i++)
      for(int j=1 ; j<=i ; j++)
        nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%(mod-1) ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    init() ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli n, k, x, ans=1 ;
        cin>> n >> k ;
        vlli a(n) ;
        for(int i=0 ; i<n ; i++) cin>> a[i] ;
        sort(all(a)) ;
        for(int i=0 ; i<n ; i++)
          {
            x=(nCr[n-1][k-1]-nCr[n-i-1][k-1]-nCr[i][k-1]+mod-1+mod-1)%(mod-1) ;
            ans=(ans*fast_exp(a[i], x))%mod ;
          }
        cout<< ans << endl ;
      }
  }
