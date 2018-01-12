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

lli get(lli s, lli n)
  {
    lli l=s+1, r=n, m ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(((m-s+1)*(m+s))/2==n) return m ;
        else if(((m-s+1)*(m+s))/2<n) l=m+1 ;
        else r=m-1 ;
      }
    return -1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, x ;
    cin>> n ;
    for(lli i=1 ; i<=(n+1)/2 ; i++)
      {
        x=get(i, n) ;
        if(x!=-1)
          {
            cout<< i << " " << x ;
            return 0 ;
          }
      }
    cout<< -1 ;
  }
