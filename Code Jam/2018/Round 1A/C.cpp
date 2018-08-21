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

#define ld long double

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli n, w, h ;
        ld req, m, M, curr, x, y, ans, diff=inf, tot=0 ;
        cin>> n >> req ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> w >> h ;
            tot+=2*(w+h) ;
          }
        m=2.0*min(w, h) ;
        M=2.0*sqrt(1.0*w*w+1.0*h*h) ;
        req-=tot ;
        ans=0 ;
        for(lli i=0 ; i<=n ; i++)
          for(lli j=0 ; j<=n-i ; j++)
            {
              curr=i*m+j*M ;
              if(curr<=req)
                {
                  if(req-curr<=diff) diff=req-curr, ans=curr ;
                  if(i+j<n)
                    {
                      if(curr+m<=req && curr+M>=req) diff=0, ans=curr=req ;
                    }
                }
            }
        ans+=tot ;
        cout<< "Case #" << tc << ": " ;
        cout<< fixed << setprecision(9) << ans << endl ;
      }
  }
