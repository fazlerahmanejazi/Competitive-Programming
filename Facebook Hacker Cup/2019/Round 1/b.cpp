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

string s ;
lli n, k, cnt, curr, ans, m, p[2000000] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    p[0]=2 ;
    for(lli i=1 ; i<=1000000 ; i++) p[i]=(2*p[i-1])%mod ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> k >> s ;
        ans=m=0 ;
        for(int i=n-1 ; i>=0 ; i--)
          {
            m=max(m, 0LL) ;
            if(s[i]=='B')
              {
                if(m==k) ans=(ans+p[i])%mod, m-- ;
                else m++ ;
              }
            else m-- ;
          }
        cout<< "Case #" << tc << ": " << ans << endl ;
      }
  }
