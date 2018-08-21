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
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

long long int gcd(long long int a, long long int b)
  {
    return b==0 ? a : gcd(b, a % b) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    long long int ans, x, y, a, b, c ;
    cin>> n ;
    a=n ;
    b=max(1, n-1) ;
    c=max(1, n-2) ;
    y=a*b*c ;
    x=gcd(a*b, gcd(b*c, c*a)) ;
    y=y/x ;
    ans=y ;
    for(int i=a ; i>=max(n-50, 1) ; i--)
      for(int j=i-1 ; j>=max(n-50, 1) ; j--)
        for(int k=j-1 ; k>=max(n-50, 1) ; k--)
          {
            a=i ; b=j ; c=k ;
            y=a*b*c ;
            x=gcd(a*b, gcd(b*c, c*a)) ;
            y=y/x ;
            ans=max(y, ans) ;
          }
    cout<< ans ;
  }
