#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
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
    int n, l, r, Ql, Qr, x ;
    lli ans=INF, curr ;
    cin>> n >> l >> r >> Ql >> Qr ;
    vi w(n+1) ;
    for(int i=1 ; i<=n ; i++)
      cin>> w[i] ;
    vlli sum(n+2, 0) ;
    for(int i=1 ; i<=n ; i++)
      sum[i]+=sum[i-1]+w[i] ;
    for(int i=0 ; i<=n ; i++)
      {
        x=abs((n-i)-i)-1 ;
        if(x<0) x=0 ;
        if(i<=n/2)
          {
            curr=sum[i]*l + (sum[n]-sum[i])*r + x*Qr ;
            ans=min(ans, curr) ;
          }
        else
          {
            curr=sum[i]*l + (sum[n]-sum[i])*r + x*Ql ;
            ans=min(ans, curr) ;
          }
      }
    cout<< ans ;
  }
