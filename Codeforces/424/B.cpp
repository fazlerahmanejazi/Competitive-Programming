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
    string a, b ;
    map<char, char> conv ;
    string s ;
    cin>> a >> b ;
    cin>> s ;
    for(int i=0 ; i<26 ; i++)
      {
        conv[a[i]]=b[i] ;
        conv[toupper(a[i])]=toupper(b[i]) ;
      }
    for(int i=0 ; i<s.length() ; i++)
      if(s[i]>='0' && s[i]<='9') continue ;
      else s[i]=conv[s[i]] ;
    cout<< s ;
  }
