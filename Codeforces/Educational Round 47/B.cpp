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
    int n, cnt ;
    string s, ans="" ;
    cin>> s ;
    vi pos ;
    n=s.length() ;
    for(int i=0 ; i<n ; i++) if(s[i]=='2') pos.pb(i) ;
    if(pos.empty()) sort(all(s)), cout<< s ;
    else
      {
        pos.pb(n) ;
        cnt=0 ;
        for(int i=0 ; i<pos[0] ; i++) if(s[i]=='0') cnt++ ;
        for(int i=0 ; i<cnt ; i++) ans+='0' ;
        cnt=0 ;
        for(int i=0 ; i<n ; i++) if(s[i]=='1') cnt++ ;
        for(int i=0 ; i<cnt ; i++) ans+='1' ;
        for(int i=1 ; i<pos.size() ; i++)
          {
            cnt=0 ;
            ans+='2' ;
            for(int j=pos[i-1]+1 ; j<pos[i] ; j++) if(s[j]=='0') cnt++ ;
            for(int j=0 ; j<cnt ; j++) ans+='0' ;
          }
        cout<< ans ;
      }
  }
