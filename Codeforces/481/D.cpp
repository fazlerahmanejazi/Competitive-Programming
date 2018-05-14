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

lli check(vlli &a, int d, int n)
  {
    lli curr=a[0], res=0 ;
    for(int i=1 ; i<n ; i++)
      {
        curr+=d ;
        if(abs(curr-a[i])>1) return -INF ;
        res+=abs(curr-a[i]) ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, x ;
    cin>> n ;
    vlli a(n), b, ans ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    if(n<=2) cout<< 0 ;
    else
      {
        b=a ;
        for(int i=-1 ; i<=1 ; i++)
          for(int j=-1 ; j<=1 ; j++)
            {
              a=b ;
              a[0]+=i ; a[1]+=j ;
              ans.pb(check(a, a[1]-a[0], n)+abs(i)+abs(j)) ;
            }
        sort(all(ans)) ;
        for(auto i:ans)
          if(i>=0)
            {
              cout<< i ;
              return 0 ;
            }
        cout<< -1 ;
      }
  }
