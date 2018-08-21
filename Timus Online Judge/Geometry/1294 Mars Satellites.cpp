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

#define pi acos(-1.0)
#define eps 1e-8

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    double AD, AC, BD, BC, a, b, c, d, ans ;
    cin>> AD >> AC >> BD >> BC ;
    a=AC*AC+AD*AD ;
    b=BC*BC+BD*BD ;
    c=2*AC*AD ;
    d=2*BC*BD ;
    if(abs(c-d)<eps) cout<< "Impossible." ;
    else
      {
        ans=(a*d-b*c)/(d-c) ;
        if(ans<-eps) cout<< "Impossible." ;
        else printf("Distance is %.0lf km.\n", sqrt(ans)*1000);
      }
  }
