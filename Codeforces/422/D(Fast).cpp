#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
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

lli t, l, r, c, d, ans ;
vlli X, F ;

void seive()
  {
    X.resize(r+1) ;
    F.resize(r+1) ;
    for(lli i=1 ; i<=r ; i++)
      X[i]=i ;
    for(lli i=2 ; i*i<=r ; i++)
      if(X[i]==i)
        for(lli j=i*i ; j<=r ; j+=i)
          if(X[j]==j)
            X[j]=i ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> t >> l >> r ;
    seive() ;
    d=ans=0 ;
    for(lli i=1 ; i<=r ; i++)
      {
        c=i/X[i] ;
        F[i]=(F[c]+(c*((X[i]-1)*X[i]/2)%mod)%mod)%mod ;
      }
    for(lli i=r ; i>=l ; i--)
      {
        ans*=t ;
        ans%=mod ;
        ans+=F[i] ;
        ans%=mod ;
      }
    cout << ans ;
  }
