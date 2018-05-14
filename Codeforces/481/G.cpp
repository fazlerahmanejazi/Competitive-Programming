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
    int n, m, s, d, c, idx, cnt ;
    cin>> n >> m ;
    vector<tuple<int, int, int, int>> data ;
    vi ans(n+1, 0) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> s >> d >> c ;
        data.pb(mt(d, s, c, i+1)) ;
      }
    sort(all(data)) ;
    for(auto i:data)
      {
        tie(d, s, c, idx)=i ;
        cnt=c ;
        for(int j=s ; j<d && cnt>0 ; j++) if(!ans[j]) cnt--, ans[j]=idx ;
        if(cnt>0 || ans[d])
          {
            cout<< -1 ;
            return 0 ;
          }
        ans[d]=m+1 ;
      }
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
