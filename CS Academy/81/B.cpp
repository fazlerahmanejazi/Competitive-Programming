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
    lli a1, a2, l1, l2, c, x, y, ans=0, A1, L1, A2, L2, t ;
    cin>> a1 >> l1 >> a2 >> l2 >> c >> x >> y ;
    for(int i=0 ; i<=c ; i++)
      {
        A1=a1+i*x ;
        L1=l1+(c-i)*y ;
        A2=a2 ;
        L2=l2 ;
        t=ceil((1.0*L2)/(1.0*A1))-1 ;
        if(L1-A2*t>0) ans=1 ;
      }
    cout<< ans ;
  }
