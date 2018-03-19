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
    int v1, v2, v3, vm ;
    cin>> v1 >> v2 >> v3 >> vm ;
    for(int i=v1 ; i<=2*v1 ; i++)
      for(int j=v2 ; j<=2*v2 ; j++)
        for(int k=v3 ; k<=2*v3 ; k++)
          {
            bool pos=false ;
            if(i>j && j>k && i>=vm && j>=vm && k>=vm && 2*vm>=k && 2*vm<j && 2*vm<i)
              {
                cout<< i << endl << j << endl << k ;
                return 0 ;
              }
          }
    cout<< -1 ;
  }
