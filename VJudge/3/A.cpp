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
    int p, x, y, z, c ;
    cin>> p >> x >> y ;
    for(int j=-1 ; x+j*50>=y ; j--)
      {
        z=x+j*50 ;
        z=(z/50)%475 ;
        for(int i=0 ; i<25 ; i++)
          {
            z=(z*96+42)%475 ;
            if(z+26==p)
              {
                cout<< 0 ;
                return 0 ;
              }
          }
      }
    for(int j=0 ; ; j++)
      {
        z=x+j*50 ;
        z=(z/50)%475 ;
        for(int i=0 ; i<25 ; i++)
          {
            z=(z*96+42)%475 ;
            if(z+26==p)
              {
                c=ceil(j/2.0) ;
                cout<< c ;
                return 0 ;
              }
          }
      }
  }
