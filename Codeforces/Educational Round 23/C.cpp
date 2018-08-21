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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, s, l, r, m, curr, f, x, ans ;
    cin>> n >> s ;
    l=0 ; r=n ;
    f=INF ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        x=m ;
        curr=0 ;
        while(x)
          {
            curr+=x%10 ;
            x/=10 ;
          }
        curr=m-curr ;
        if(curr>=s)
          {
            f=min(f, m) ;
            r=m-1 ;
          }
        else l=m+1 ;
      }
    ans=n-f+1 ;
    if(ans<0) ans=0 ;
    cout<< ans ;
  }
