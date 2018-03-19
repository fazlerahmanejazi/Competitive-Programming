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
    lli A, B, x, y, z, ans=0, c ;
    cin>> A >> B ;
    cin>> x >> y >> z ;
    if(x>A/2)
      {
        c=A/2 ;
        x-=c ;
        A-=2*c ;
        ans+=2*x ;
      }
    else A-=2*x ;
    if(z>B/3)
      {
        c=B/3 ;
        z-=c ;
        B-=3*c ;
        ans+=3*z ;
      }
    else B-=3*z ;
    ans+=max(0LL, y-A) ;
    ans+=max(0LL, y-B) ;
    cout<< ans ;
  }
