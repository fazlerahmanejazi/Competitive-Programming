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

bool check(vi &a, vi &b, int n, int k)
  {
    int cnt=0 ;
    for(int i=0 ; i<n ; i++) if(a[i] && a[i]!=b[i]) return false ;
    for(int i=1 ; i<n ; i++) if(b[i]>b[i-1]) cnt++ ;
    return (cnt==k) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int k, n, ans=0 ;
        cin>> n >> k ;
        vi a(n), b(n) ;
        for(int i=0 ; i<n ; i++) cin>> a[i], b[i]=i+1 ;
        do
          {
            if(check(a, b, n, k)) ans++ ;
          } while(next_permutation(all(b))) ;
        cout<< ans << endl ;
      }
  }
