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

bool isWord(string s)
  {
    if(!s.length()) return true ;
    if(s.length()>=2 && s[0]=='0') return true ;
    for(int i=0 ; i<s.length() ; i++)
      if(s[i]>='a' && s[i]<='z') return true ;
      else if(s[i]>='A' && s[i]<='B') return true ;
      else if(s[i]=='.') return true ;
    return false ;
  }

void print(string s)
  {
    cout<< (char)34 ;
    for(int i=0 ; i<s.length()-1 ; i++) cout<< s[i] ;
    cout<< (char)34 << endl ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    string s, a="", b="", r="" ;
    int n, pos=0, x=1, A=0, B=0 ;
    cin>> s ;
    n=s.length() ;
    vector<string> word ;
    for(int i=0 ; i<n ; i++)
      if(s[i]!=',' && s[i]!=';') r+=s[i] ;
      else word.pb(r), r="" ;
    word.pb(r) ;
    for(int i=0 ; i<word.size() ; i++)
      if(isWord(word[i])) b+=word[i], b+=',', B=1 ;
      else a+=word[i], a+=',', A=1 ;
    if(A) print(a) ;
    else cout<< "-" << endl ;
    if(B) print(b) ;
    else cout<< "-" << endl ;
  }
