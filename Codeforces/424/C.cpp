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
    //unordered_map<int, int> ans ;
    const int LIM=10000000 ;
    vi ans(2*LIM+10, 0) ;
    vb taken ;
    int n, k, cnt, curr, res=0 ;
    cin>> k >> n ;
    vi jury(k), scores(n), pre(k, 0)  ;
    for(int i=0 ; i<k ; i++)
      cin>> jury[i] ;
    for(int i=0 ; i<n ; i++)
      cin>> scores[i] ;
    pre[0]=-jury[0] ;
    for(int i=1 ; i<k ; i++)
      pre[i]=pre[i-1]-jury[i] ;
    for(int i=0 ; i<n ; i++)
      {
        //unordered_map<int, bool> taken ;
        taken.assign(2*LIM+10, false) ;
        for(int j=0 ; j<k ; j++)
          {
            curr=scores[i]+pre[j]+LIM ;
            if(!taken[curr])
              ans[curr]++ ;
            taken[curr]=true ;
          }
        taken.clear() ;
      }
    for(auto i:ans)
      if(i==n)
        res++ ;
    cout<< res ;
  }
