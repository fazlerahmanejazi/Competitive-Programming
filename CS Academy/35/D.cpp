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

int getEven(lli x)
  {
    int dig, ans=0 ;
    while(x>0)
      {
        dig=x%10 ;
        if(dig%2==0) ans++ ;
        x/=10 ;
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, curr, num ;
    lli l=0, r=0, x ;
    cin>> n ;
    num=getEven(n) ;
    if(num==0)
      {
        cout<< -1 ;
        return 0 ;
      }
    x=n ;
    while(1)
      {
        curr=getEven(x) ;
        if(curr<num) break ;
        l++ ;
        x++ ;
      }
    x=n ;
    num=getEven(n) ;
    while(1)
      {
        curr=getEven(abs(x)) ;
        if(curr<num) break ;
        r++ ;
        x-- ;
      }
    cout<< l*r ;
  }
