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

long long int A, B ;

long long int phi(long long int n)
  {
    long long int res=n ;
    for(long long int p=2 ; p*p<=n ; p++)
      if(!(n%p))
        {
          while(!(n%p)) n/=p ;
          res-=res/p ;
        }
    if(n>1) res-=res/n ;
    return res ;
  }

long long int phi2(long long int n, long long int a)
  {
    long long int res=n ;
    vector<int> temp ;
    for(long long int p=2 ; p*p<=a ; p++)
      if(!(a%p))
        {
          while(!(a%p)) a/=p ;
          temp.push_back(p) ;
        }
    if(a>1) temp.push_back(a) ;
    for(auto p:temp)
      if(!(n%a))
        {
          while(!(n%p)) n/=p ;
          res+=res/p ;
        }
    if(n>1) res+=res/n ;
    return res ;
  }

long long int solve()
  {
    long long int ans=phi(A*B) ;
    long long int x=__gcd(A, B) ;
    long long int a=A/x, b=B/x ;
    ans+=phi2(A*B, a) ;
    ans+=phi2(A*B, b) ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> A >> B ;
    cout<< phi(A) << " " << phi(B) << " " << solve() ;
  }
