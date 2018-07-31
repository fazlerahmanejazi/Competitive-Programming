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

bool compare(string &s, string &r)
  {
    int i=0, j=0 ;
    while(1)
      {
        if(i>=s.length()) return true ;
        if(j>=r.length()) return false ;
        if(s[i]==r[j]) i++, j++ ;
        else if(!i) j++ ;
        else i=0 ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        string s, p="", r ;
        bool pos=true ;
        cin>> s ;
        for(int i=0 ; i<s.length() ; i++)
          {
            p+=s[i] ;
            r=p+s ;
            pos=compare(s, r) ;
            if(!pos) break ;
          }
        if(!pos) cout<< "Case #" << tc << ": " << r << endl ;
        else cout<< "Case #" << tc << ": " << "Impossible" << endl ;
      }
  }
