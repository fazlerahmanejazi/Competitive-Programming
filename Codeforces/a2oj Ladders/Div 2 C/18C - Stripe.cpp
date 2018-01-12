#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, c=0 ;
    cin>> n ;
    vi a(n+1), pre(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a[i] ;
        pre[i]=pre[i-1]+a[i] ;
      }
    for(int i=1 ; i<n ; i++)
      if(pre[i]==pre[n]-pre[i])
        c++ ;
    cout<< c ;
  }
