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
    int n, k, curr, ans=inf, idx, pos, cnt ;
    cin>> n >> k ;
    for(int i=1 ; i<=k+1 ; i++)
      {
        idx=i ;
        cnt=1 ;
        while(idx+2*k+1<=n) idx+=(2*k+1), cnt++ ;
        if(idx+k>=n && cnt<ans) ans=cnt, pos=i ;
      }
    cout<< ans << endl ;
    idx=pos ;
    while(idx<=n) cout<< idx<< " ", idx+=2*k+1 ;
  }
