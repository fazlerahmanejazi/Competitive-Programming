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
    int n, k, l, r, ans=0, zero=0, L=inf, R=inf ;
    cin>> n >> k ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    l=0 ; r=0 ;
    if(!a[0]) zero=1 ;
    while(l<n && r<n)
      {
        if(r==l && (a[r]+k) && ans<1)
          {
            ans=1 ;
            L=l ; R=r ;
          }
        else if(r>l && ans<r-l+1)
          {
            ans=r-l+1 ;
            L=l ; R=r ;
          }
        if(r+1<n && zero+!a[r+1]<=k)
          {
            r++ ;
            if(!a[r]) zero++ ;
          }
        else
          {
            l++ ;
            if(!a[l-1]) zero-- ;
          }
      }
    R=min(R, n-1) ;
    for(int i=L ; i<=R ; i++)
      a[i]=1 ;
    cout<< ans << endl ;
    for(int i=0 ; i<n ; i++)
      cout<< a[i] << " " ;
  }
