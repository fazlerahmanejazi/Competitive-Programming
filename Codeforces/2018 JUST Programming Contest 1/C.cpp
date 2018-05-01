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

lli phi[1000005] ;

void computeTotient()
  {
    for(lli i=1 ; i<=1000000 ; i++) phi[i]=i ;
    for(lli p=2 ; p<=1000000 ; p++)
      if(phi[p]==p)
        {
          phi[p]=p-1 ;
          for(int i=2*p ; i<=1000000 ; i+=p) phi[i]=(phi[i]/p)*(p-1) ;
        }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    computeTotient() ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli x ;
        cin>> x ;
        cout<< phi[x]*(x-1) << endl ;
      }
  }
