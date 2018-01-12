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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T, n, x, ans ;
    string s ;
    cin>> T ;
    getline(cin, s) ;
    while(T--)
      {
        stringstream ss ;
        vi a ;
        ans=-1 ;
        getline(cin, s) ;
        ss<< s ;
        while(ss>> x)
          a.pb(x) ;
        n=a.size()-1 ;
        for(int i=0 ; i<=n ; i++)
          if(a[i]==n)
            {
              a[i]=-1 ;
              break ;
            }
        for(int i=0 ; i<=n ; i++)
          ans=max(ans, a[i]) ;
        cout<< ans << endl ;
      }
  }
