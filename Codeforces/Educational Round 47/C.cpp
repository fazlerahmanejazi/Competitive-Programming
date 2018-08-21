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

lli get(lli n)
  {
    return (n*(n+1))/2 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, m, x, d, tot=0 ;
    cin>> n >> m ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> x >> d ;
        tot+=x*n ;
        if(d<0)
          {
            tot+=d*get(n/2)*2 ;
            if(!(n%2)) tot-=(n/2)*d ;
          }
        else tot+=d*get(n-1) ;
      }
    long double ans=tot ;
    cout<< fixed << setprecision(9) << ans/n ;
  }
