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

lli n, p, k, a[10010], ans ;

void compute(lli i)
  {
    if(i>n)
      {
        lli sum=0 ;
        for(int i=1 ; i<=n ; i++)
          {
            sum+=a[i] ;
            if(sum<0) return ;
          }
        ans++ ;
        return ;
      }
    a[i]=1 ;
    compute(i+1) ;
    a[i]=-p ;
    compute(i+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> p ;
    compute(1) ;
    cout<< ans ;
}
