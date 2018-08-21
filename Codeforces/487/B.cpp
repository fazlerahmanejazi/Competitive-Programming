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
    int n, p ;
    string s ;
    cin>> n >> p >> s ;
    bool pos=false ;
    for(int i=p ; i<n ; i++)
      {
        if(s[i]=='.' || s[i-p]=='.')
          {
            pos=true ;
            if(s[i]=='.')
              {
                if(s[i-p]=='1') s[i]='0' ;
                else s[i]='1' ;
              }
            else
              {
                if(s[i]=='1') s[i-p]='0' ;
                else s[i-p]='1' ;
              }
          }
        if(s[i]!=s[i-p]) pos=true ;
      }
    for(auto &c:s) if(c=='.') c='0' ;
    if(pos) cout<< s ;
    else cout<< "No" ;
  }
