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

bool check(char c)
  {
    if(c=='f' || c=='r' || c=='i' || c=='e' || c=='z' || c=='a') return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        string s ;
        cin>> s ;
        int cnt=1 ;
        bool prev=check(s[0]) ;
        for(int i=1 ; i<s.length() ; i++)
          if(check(s[i])==prev) cnt++ ;
          else cout<< cnt, cnt=1, prev=check(s[i]) ;
        if(cnt) cout<< cnt ;
        cout<< endl ;
      }
  }
