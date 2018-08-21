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
    lli i, n, m, k, x, y, ans ;
    cin>> n >> m ;
    if(m>=n)
      {
        cout<< n ;
      }
    else
      {
        lli l=m, r=n+1 ;
        while(l<=r)
          {
            lli mid=(l+r)/2 ;
            x=2*m+(mid-m)*(mid-m+1) ;
            y=2*n ;
            if(x>=y)
              {
                r=mid-1 ;
                ans=mid ;
              }
            else l=mid+1 ;
          }
        cout<< ans ;
      }
  }
