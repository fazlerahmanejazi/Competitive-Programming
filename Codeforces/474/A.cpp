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
    int cnt[4] ;
    string s, r ;
    cin>> s ;
    r=s ;
    sort(all(r)) ;
    cnt[0]=cnt[1]=cnt[2]=0 ;
    for(auto c:s) cnt[c-'a']++ ;
    if(r!=s) cout<< "NO" ;
    else if(cnt[0] && cnt[1] && (cnt[2]==cnt[1] || cnt[2]==cnt[0])) cout<< "YES" ;
    else cout<< "NO" ;
  }
