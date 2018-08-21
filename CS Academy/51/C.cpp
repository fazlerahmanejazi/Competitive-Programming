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

int p, q, r, s, w, x ;
vi a(3) ;

bool check(int a, int b, int c)
  {
    r=a ; s=0 ;
    int s=b-a, k ;
    if(c>=b-a && c<=a+b && (c-s)%2==0)
      {
        k=(c-s)/2 ;
        if(a<k) return false ;
        w=a-k ;
        x=b-w ;
        return true ;
      }
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> a[0] >> a[1] >> a[2] ;
        sort(all(a)) ;
        p=q=0 ;
        if(check(a[0], a[2], a[1])) cout<< p << " " << q << " " << r << " " << s << " " << w << " " << x << endl ;
        else if(check(a[0], a[1], a[2])) cout<< p << " " << q << " " << r << " " << s << " " << w << " " << x << endl ;
        else cout<< -1 << endl ;
      }
  }
