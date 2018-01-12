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

bool isVowel(char c)
  {
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    string s ;
    int ans=0 ;
    cin>> s ;
    for(int i=0 ; i<s.length() ; i++)
      {
        if(isVowel(s[i])) ans++ ;
        else if(s[i]>='0' && s[i]<='9' && (s[i]-'0')%2) ans++ ;
      }
    cout<< ans ;
  }
