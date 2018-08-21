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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    long long int a, b, ans=0 ;
    cin>> a >> b ;
    while(1)
      {
        if(b==1)
          {
            ans+=a ;
            cout<< ans ;
            return 0 ;
          }
        else if(a>b)
          {
            ans+=a/b ;
            a-=(a/b)*b ;
          }
        else swap(a, b) ;
      }
  }
