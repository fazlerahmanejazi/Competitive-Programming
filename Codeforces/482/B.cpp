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
    int n, x, t, tot, remain, mx=0 ;
    string s ;
    vi ans(3, 0), temp ;
    cin>> n ;
    for(int i=0 ; i<3 ; i++)
      {
        cin>> s ;
        t=n ;
        tot=s.length() ;
        map<char, int> cnt ;
        for(auto c:s) cnt[c]++ ;
        for(auto c:s)
          {
            remain=tot-cnt[c] ;
            if(!remain)
              {
                if(t==1) ans[i]=max(ans[i], tot-1) ;
                else ans[i]=tot ;
              }
            else if(remain<=t) ans[i]=tot ;
            else ans[i]=max(ans[i], cnt[c]+t) ;
          }
        mx=max(ans[i], mx) ;
      }
    temp=ans ;
    sort(all(temp)) ;
    if(temp[1]==temp[2]) cout<< "Draw" ;
    else if(mx==ans[0]) cout<< "Kuro" ;
    else if(mx==ans[1]) cout<< "Shiro" ;
    else cout<< "Katie" ;
  }
