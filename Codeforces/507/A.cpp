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
    int n, a, b, ans=0 ;
    cin>> n >> a >> b ;
    vi d(n) ;
    for(int i=0 ; i<n ; i++) cin>> d[i] ;
    for(int i=0 ; i<n/2 ; i++)
      {
        if(d[i]+d[n-i-1]==1) return cout<< -1, 0 ;
        if(d[i]+d[n-i-1]==4) ans+=2*min(a, b) ;
        else if(d[i]==d[n-i-1]) continue ;
        else if((d[i]==1 && d[n-i-1]==2) || (d[i]==2 && d[n-i-1]==1)) ans+=b ;
        else if((d[i]==0 && d[n-i-1]==2) || (d[i]==2 && d[n-i-1]==0)) ans+=a ;
      }
    if(n%2 && d[n/2]==2) ans+=min(a, b) ;
    cout<< ans ;
  }
