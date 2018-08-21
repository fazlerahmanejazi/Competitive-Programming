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
    lli ans=-1, curr, x, idx, y ;
    vlli a(15), b ;
    for(int i=0 ; i<14 ; i++) cin>> a[i] ;
    for(int i=0 ; i<14 ; i++)
      if(a[i])
        {
          b=a ;
          x=a[i]/14 ;
          y=a[i]%14 ;
          idx=(i+1)%14 ;
          b[i]=0 ;
          for(int j=0 ; j<14 ; j++) b[j]+=x ;
          while(y)
            {
              b[idx]++ ;
              idx=(idx+1)%14 ;
              y-- ;
            }
          curr=0 ;
          for(int j=0 ; j<14 ; j++) if(!(b[j]%2)) curr+=b[j] ;
          ans=max(curr, ans) ;
        }
    cout<< ans ;
  }
