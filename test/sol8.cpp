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
    int t ;
    cin>> t ;
    while(t--)
      {
        string s, r ;
        cin>> s >> r ;
        int i=0, j=0 ;
        while(i<r.length() && j<s.length())
          {
            while(s[j]!=r[i] && j<s.length()) j++ ;
            if(j==s.length()) break ;
            if(s[j]!=r[i]) break ;
            j++ ;
            i++ ;
          }
        if(i==r.length()) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
}
