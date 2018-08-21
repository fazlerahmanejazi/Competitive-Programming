#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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
    int len ;
    string s, temp ;
    set<string> ans ;
    cin>> s ;
    len=s.length() ;
    reverse(all(s)) ;
    bool dp2[len+1]={0}, dp3[len+1]={0} ;
    dp2[1]=1 ; dp3[2]=1 ;
    if(s[0]!=s[2] || s[1]!=s[3]) dp2[3]=1 ;
    for(int i=4 ; i<len-5 ; i++)
      {
        dp2[i]=dp3[i-2]|(dp2[i-2]&(s[i]!=s[i-2] || s[i-1]!=s[i-3])) ;
        dp3[i]=dp2[i-3]|(dp3[i-3]&(s[i]!=s[i-3] || s[i-1]!=s[i-4] || s[i-2]!=s[i-5])) ;
      }
    for(int i=0 ; i<len-5 ; i++)
      {
        if(dp2[i])
          {
            temp="" ;
            temp+=s[i] ; temp+=s[i-1] ;
            ans.insert(temp) ;
          }
        if(dp3[i])
          {
            temp="" ;
            temp+=s[i] ; temp+=s[i-1] ; temp+=s[i-2] ;
            ans.insert(temp) ;
          }
      }
    cout<< ans.size() << endl ;
    for(auto x:ans)
      cout<< x << endl ;
  }
