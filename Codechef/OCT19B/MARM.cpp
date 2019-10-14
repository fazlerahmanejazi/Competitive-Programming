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
    int t ;
    cin>> t ;
    while(t--)
      {
        lli n, k, period, idx=0, _k ;
        cin>> n >> k ;
        vlli a(n) ;
        _k=k ;
        for(int i=0 ; i<n ; i++) cin>> a[i] ;
        period=3*n ;
        k%=period ;
        while(k--) a[idx]=a[idx]^a[n-idx-1], idx=(idx+1)%n ;
        if(n%2 && _k>n/2) a[n/2]=0 ;
        for(int i=0 ; i<n ; i++) cout<< a[i] << " " ;
        cout<< endl ;
      }
  }
