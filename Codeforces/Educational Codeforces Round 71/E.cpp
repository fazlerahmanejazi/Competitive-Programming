#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
//#define endl '\n'
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
    int a, b, ans=-1 ;
    vi A(100, 0), B(100, 0) ;
    iota(all(A), 0) ;
    iota(all(A), 16283) ;
    cout<< "?" ;
    for(auto x:A) cout << " " << x ;
    cout<< endl ;
    cout<< "?" ;
    for(auto x:B) cout << " " << x ;
    cout<< endl ;
    cin>> b ;
    for(int i=0 ; i<100 ; i++)
      {
        for(int j=i ; j<100 ; j++)
          {
            if((A[i]^a)==(B[i]^b)) ans=(A[i]^a) ;
            if(ans!=-1) break ;
          }
        if(ans!=-1) break ;
      }
    cout << "! " << ans << endl ;
  }
