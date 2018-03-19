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

int T, n, q, l, r ;
vi a, ans ;

int calc(lli x)
  {
    if(x==1) return 0 ;
    int res ;
    if(x%2) res=2+calc((x-1)/2) ;
    else res=1+calc(x/2) ;
    return res ;
  }

int main()
  {
    scanf("%d", &T);
    while(T--)
      {
        scanf("%d %d", &n, &q);
        a.clear() ;
        a.resize(n) ;
        ans.clear() ;
        ans.resize(n) ;
        for(int i=0 ; i<n ; i++)
          scanf("%d", &a[i]);
        ans[0]=calc(a[0]) ;
        for(int i=1 ; i<n ; i++)
          {
            ans[i]=calc(a[i]) ;
            ans[i]+=ans[i-1] ;
          }
        for(int i=0 ; i<q ; i++)
          {
            scanf("%d %d", &l, &r);
            l-- ; r-- ;
            if(l) printf("%d\n", ans[r] - ans[l-1]);
            else printf("%d\n", ans[r]);
          }
      }
  }
