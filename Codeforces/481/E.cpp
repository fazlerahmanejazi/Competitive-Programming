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
    lli n, w, x, curr=0, mn, mx ;
    cin>> n >> w ;
    vlli a(n) ;
    mn=0 ; mx=w ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        curr+=a[i] ;
        mn=min(mn, curr) ;
        mx=min(mx, w-curr) ;
      }
    if(mx<0) cout<< 0 ;
    else cout<< max(mx+mn+1, 0LL) ;
  }
