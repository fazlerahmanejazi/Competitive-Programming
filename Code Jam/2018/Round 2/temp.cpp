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
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli r, b, ans=0, curr, x, y, extra, X, Y ;
        cin>> r >> b ;
        for(lli i=0 ; i<=sqrt(r)+10 ; i++)
          for(lli j=0 ; j<=sqrt(b)+10 ; j++)
            {
              x=((i*(i+1))/2)*(j+1) ;
              y=((j*(j+1))/2)*(i+1) ;
              if(x<=r && y<=b)
                {
                  x=r-x ;
                  y=b-y ;
                  extra=0 ;
                  curr=(i+1)*(j+1)-1 ;
                  for(lli k=0 ; k<=i+1 ; k++)
                    for(lli l=0 ; l<=j+1 ; l++)
                      {
                        if(k==i+1 && l==j+1) continue ;
                        X=((j+1)*k)+((l-1)*l)/2 ;
                        Y=((i+1)*l)+((k-1)*k)/2 ;
                        if(X<=y && Y<=x) extra=k+l ;
                      }
                  ans=max(ans, curr+extra) ;
                }
            }
        cout<< "Case #" << tc << ": " << ans << endl ;
      }
  }
