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
    lli x, y, l, r, i=0, j=0, a=1, b=1, temp, ans=0 ;
    vlli arr ;
    cin>> x >> y >> l >> r ;
    for(i=a ; a<=r ; a=a*x)
      {
        b=1 ;
        for(i=b ; b<=r*y ; b=b*y)
            arr.pb(a+b) ;
      }
    arr.pb(l-1) ; arr.pb(r+1) ;
    sort(arr.begin(), arr.end()) ;
    for(int i=1 ; i<arr.size() ; i++)
      if(arr[i-1]>=l-1 && arr[i]<=r+1)
        ans=max(ans, arr[i]-arr[i-1]-1) ;
    cout<< ans ;
  }
