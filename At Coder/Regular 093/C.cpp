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
    lli n, tot=0, x, curr ;
    cin>> n ;
    vlli a ;
    a.pb(0) ;
    for(int i=1 ; i<=n ; i++) cin>> x, a.pb(x) ;
    for(int i=1 ; i<=n ; i++) tot+=abs(a[i]-a[i-1]) ;
    tot+=abs(a[n]) ;
    for(int i=1 ; i<n ; i++)
      {
        curr=tot-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]) ;
        cout<< curr << endl ;
      }
    curr=tot-abs(a[n]-a[n-1])-abs(a[n])+abs(a[n-1]) ;
    cout<< curr << endl ;
  }
